#include "ACSObject.h"
#include "log.h"
#include "fmt/format.h"
#include <string>
#include <array>
#include <QDebug>

ACSObject::ACSObject(QObject *parent)
    : QObject(parent),
    m_hAcsComm(ACSC_INVALID),
    g_nTotalAxes(0),
    g_nTotalBuffer(0)
{
}

ACSObject::~ACSObject()
{

}

void ACSObject::TerminatePrevConnect()
{
    std::array<ACSC_CONNECTION_DESC, 10> ConnectionList;
    int nConnections;

    if (!acsc_GetConnectionsList(ConnectionList.data(), 10, &nConnections))
        return;

    for (int i = 0; i < nConnections; ++i)
    {
        std::string_view app_path = ConnectionList[i].Application;
        auto pos = app_path.find_last_of("\\");
        auto app_name = app_path.substr(pos + 1);

        if (app_name == "ACS.Framework.exe")
            continue;
        acsc_TerminateConnection(&(ConnectionList[i]));
    }
}

bool ACSObject::OpenCommEthernetTCP(std::string ip, int port)
{
    TerminatePrevConnect();
    m_hAcsComm = acsc_OpenCommEthernetTCP((char *)ip.c_str(), port);
    if (m_hAcsComm == ACSC_INVALID) {
        SYS_LOG_ERROR("acsc_OpenCommEthernetTCP Error! acs ip:{},port:{}", ip, port);
        return false;
    }
//    double SysInfo = 0.0;
//    acsc_SysInfo(m_hAcsComm, 13, &SysInfo, ACSC_SYNCHRONOUS);
//    g_nTotalAxes = (int)SysInfo;
//    if (g_nTotalAxes == 0)
//        g_nTotalAxes = 2;

//    acsc_SysInfo(m_hAcsComm, 10, &SysInfo, ACSC_SYNCHRONOUS);
//    g_nTotalBuffer = (int)SysInfo;
//    if (g_nTotalBuffer == 0)
//        g_nTotalBuffer = 10;
   return true;
}

void ACSObject::CloseComm()
{
    if (ACSC_INVALID == m_hAcsComm)
        return;

    if (acsc_CloseComm(m_hAcsComm))
    {
        m_hAcsComm = ACSC_INVALID;
    }
}

bool ACSObject::AxisEnable(int axis)
{
    int Error = 0;
    char ErrorStr[256] = {'\0'};
    int Received = 0;
    if (acsc_Enable(m_hAcsComm, axis, NULL))
    {
        return true;
    }
    if (acsc_WaitMotorEnabled(m_hAcsComm, axis, 1, TIMEOUT_MOTOR_ENABLED))
        return true;

    SYS_LOG_ERROR("ACS Axis:{} enable error", axis);

    if (acsc_GetMotorError(m_hAcsComm, axis, &Error, NULL))
    {
        if (Error > 0)
        {
            if (acsc_GetErrorString(m_hAcsComm, Error, ErrorStr, 255, &Received))
            {
                ErrorStr[Received] = '\0';
                std::string_view errMsg = ErrorStr;
                SYS_LOG_ERROR("ACS Axis error cause:{}", errMsg);
            }
        }

    }

    return false;
}

void ACSObject::AxisDisable(int axis)
{
    if (acsc_Disable(m_hAcsComm, axis, NULL))
        return;
    if (acsc_WaitMotorEnabled(m_hAcsComm, axis, 0, TIMEOUT_MOTOR_ENABLED))
        return;
    SYS_LOG_ERROR("ACS disable axis:{} fail!", axis);

}

bool ACSObject::AxisEnableAll()
{
    bool ret = true;
    for (int axis = 0; axis < g_nTotalAxes; ++axis)
    {
        if (!AxisEnable(axis))
            ret = false;
    }
    return ret;
}

void ACSObject::AxisDisableAll()
{
    if (!acsc_DisableAll(m_hAcsComm, NULL))
        SYS_LOG_ERROR("ACS disable all fail");
}

bool ACSObject::StartPEG(int axis,double width, double first_point, double interval, double last_point, int tb_num, double tb_period)
{
    acsc_Enable(m_hAcsComm, axis, NULL);

    int ast0 = 0;
    acsc_GetAxisState(m_hAcsComm, 0, &ast0, NULL);

    if (!acsc_PegInc(m_hAcsComm, 0, axis, width, first_point, interval, last_point, tb_num, tb_period, NULL))
    {
        auto err = acsc_GetLastError();
        SYS_LOG_ERROR("ACS PegInc fail, Errcode:{}", err);
        return FALSE;
    }
    return TRUE;
}

void ACSObject::StopPEG(int axis)
{
    acsc_StopPeg(m_hAcsComm, axis, NULL);
}

QVector<QString> ACSObject::GetSysError()
{
    QVector<QString> contents;

    char ErrorStr[256];
    int ErrorCode = 0, Received = 0;
    std::string hd("<font color=red>");
    std::string tl("</font>");

    ErrorCode = acsc_GetLastError();
    if (ErrorCode > 0)
    {
        acsc_GetErrorString(m_hAcsComm, ErrorCode, ErrorStr, 255, &Received);
        ErrorStr[Received] = '\0';
        std::string lastErr = fmt::format("ACS function ErrorCode:{}, error info:{}", ErrorCode, ErrorStr);
        contents.push_back(std::string(hd + lastErr + tl).c_str());
    }

    for (int i = 0; i < 3; ++i)
    {
        ErrorCode = 0; Received = 0;
        acsc_GetMotorError(m_hAcsComm, i, &ErrorCode, NULL);
        if (ErrorCode > 0) {
            acsc_GetErrorString(m_hAcsComm, ErrorCode, ErrorStr, 255, &Received);
            ErrorStr[Received] = '\0';
            std::string motorErr = fmt::format("ACS axis {} Motor ErrorCode:{}, error info:{}", i, ErrorCode, ErrorStr);
            contents.push_back(std::string(hd + motorErr + tl).c_str());
        }

    }

    return contents;
}

int ACSObject::GetServoState(int axis)
{
    int st = 0x0;
    acsc_GetMotorState(m_hAcsComm, axis, &st, ACSC_SYNCHRONOUS);
    //return st & ACSC_MST_ENABLE;
    return st;
}

double ACSObject::GetFPosition(int axis)
{
    double fpos = 0.0;
    acsc_GetFPosition(m_hAcsComm, axis, &fpos, ACSC_SYNCHRONOUS);
    return fpos;
}

double ACSObject::GetFVelocity(int axis)
{
    double fvelo = 0.0;
    acsc_GetFVelocity(m_hAcsComm, axis, &fvelo, ACSC_SYNCHRONOUS);
    return fvelo;
}

int ACSObject::GetFault(int axis)
{
    int fault = 0x0;
    acsc_GetFault(m_hAcsComm, axis, &fault, ACSC_SYNCHRONOUS);
    return fault;
}

bool ACSObject::FaultClear(int axis)
{
    return acsc_FaultClear(m_hAcsComm, axis, ACSC_SYNCHRONOUS);
}

bool ACSObject::HomePosition()
{
    bool ret = acsc_RunBuffer(m_hAcsComm, 0, NULL, ACSC_SYNCHRONOUS);
    if (ret)
        SYS_LOG_INFO("ACS run buffer:0 Success!");
    else
    {
        SYS_LOG_ERROR("ACS run buffer:0 Error!");
        return false;
    }

    for (int i = 1; i < 6; ++i)
    {
        if (!acsc_SetOutputPort(m_hAcsComm, i, 1, ACSC_SYNCHRONOUS))
        {
            SYS_LOG_ERROR("acsc_SetOutputPort {} fail!", i);
            return false;
        }
    }
    ret = acsc_RunBuffer(m_hAcsComm, 1, NULL, ACSC_SYNCHRONOUS);
    if(ret)
        SYS_LOG_INFO("ACS run buffer:1 Success!");
    else {
        SYS_LOG_ERROR("ACS run buffer:1 Error!");
        return false;
    }

    SYS_LOG_INFO("ACS HomePostion Success!");
    return true;
}

bool ACSObject::SetVelocity(int axis, double velo, double acc, double dec, double jerk, double kdec)
{
    acsc_SetVelocityImm(m_hAcsComm, axis, velo, NULL);
    acsc_SetAccelerationImm(m_hAcsComm, axis, acc, NULL);
    acsc_SetDecelerationImm(m_hAcsComm, axis, dec, NULL);
    acsc_SetJerkImm(m_hAcsComm, axis, jerk, NULL);
    acsc_SetKillDecelerationImm(m_hAcsComm, axis, kdec, NULL);
    return true;
}

bool ACSObject::JogNegative(int axis, double velo)
{
    if (velo != 0)
    {
        if (!acsc_Jog(m_hAcsComm, ACSC_AMF_VELOCITY, axis, velo * (-1), ACSC_SYNCHRONOUS))
            return false;
    }
    else
    {
        if (!acsc_Jog(m_hAcsComm, 0, axis, ACSC_NEGATIVE_DIRECTION, ACSC_SYNCHRONOUS))
            return false;
    }
    return true;
}

bool ACSObject::JogPositive(int axis, double velo)
{
    if (velo != 0)
    {
        if (!acsc_Jog(m_hAcsComm, ACSC_AMF_VELOCITY, axis, velo, NULL))
            return false;
    }
    else
    {
        if (!acsc_Jog(m_hAcsComm, 0, axis, ACSC_POSITIVE_DIRECTION, NULL))
            return false;
    }
    return true;
}

bool ACSObject::MoveAbsolute(int axis, double pos)
{
    int mst = 0x0;
    acsc_GetMotorState(m_hAcsComm, axis, &mst, NULL);
    //if (mst & ACSC_MST_ACC) return true;            //加速
    //if (mst & ACSC_MST_MOVE) return true;           //正在移动
    mst = acsc_ToPoint(m_hAcsComm, 0, axis, pos, NULL);
    if (mst == 0) 
    {
        SYS_LOG_ERROR("Axis{} MoveAbsolute point to point error !", axis);
        return false;
    }
    acsc_WaitMotionEnd(m_hAcsComm, axis,5*60*1000);
    return true;
}

bool ACSObject::MoveRelative(int axis, double dist)
{
    if (!acsc_ToPoint(m_hAcsComm, ACSC_AMF_RELATIVE, axis, dist, ACSC_SYNCHRONOUS))
    {
        SYS_LOG_ERROR("Axis{} MoveRelative point to point error !", axis);
        return false;
    }
    acsc_WaitMotionEnd(m_hAcsComm, axis, 5*60*1000);
    return true;
}

bool ACSObject::MoveAbsoluteMuti(std::vector<int> axes, std::vector<double> points)
{
    if (axes.size() != points.size())
        return false;
    axes.emplace_back(-1); //must Add '-1' at the last of array
    if (!acsc_ToPointM(m_hAcsComm, 0, axes.data(), points.data(), NULL))
    {
        SYS_LOG_ERROR("Axes MoveAbsolute point to point error !");
        return false;
    }
    for (auto i : axes)
        acsc_WaitMotionEnd(m_hAcsComm, i, 5*60*1000);
    return true;
}

bool ACSObject::MotionStop(int axis)
{
    return acsc_Halt(m_hAcsComm, axis, NULL);
}

bool ACSObject::MotionStopAll()
{
    int axes[10] = { 0 };
    for (int i = 0; i < g_nTotalAxes; ++i)
        axes[i] = i;
    axes[g_nTotalAxes] = -1;

    return acsc_HaltM(m_hAcsComm, axes, NULL);
}
