#include "YmcObject.h"
#include "log.h"
#include <future>
#include "fmt/format.h"

YmcObject::YmcObject(QObject *parent)
	: QObject(parent)
{
}

YmcObject::~YmcObject()
{
    DWORD rc;
    for (auto& dev : m_Devices)
    {
        for (auto& axis : dev.v_AxisCtl)
        {
            rc = ymcServoControl(axis.g_hDevice, SERVO_OFF, 5000);
            rc = ymcClearDevice(axis.g_hDevice);
        }
    }
    MotionAPICloseAll();
}

std::vector<Ymc::ComController>::iterator YmcObject::FindComControllerByCpuNumber(ulong cpuNo)
{
    auto it = find_if(m_Devices.begin(), m_Devices.end(), [cpuNo](const Ymc::ComController& dev) {
        return dev.com_dev.CpuNumber == cpuNo;
        });
    return it;
}

std::vector<Ymc::AxisController>::iterator YmcObject::FindAxisControllerByAxisNumber(Ymc::ComController& dev, ulong axisNo)
{
    auto it = find_if(dev.v_AxisCtl.begin(), dev.v_AxisCtl.end(), [axisNo](const Ymc::AxisController& axis) {
        return axis.axisNo == axisNo;
        });
    return it;
}

void YmcObject::SwitchController(ulong cpuNo)
{
    /*获取正在使用的cpu,本项目只控制一个cpu,如有多cpu使用前需切换到目标cpu*/  
    auto it_cpu = FindComControllerByCpuNumber(cpuNo);
    if (it_cpu == m_Devices.end()) {
        SYS_LOG_ERROR("can not find the using cpu{} Controller info, switched cpu false",cpuNo);
        return;
    }
    if (it_cpu != m_Devices.begin())
        std::iter_swap(m_Devices.begin(), it_cpu);
    return;
}

bool YmcObject::AxesMotion(std::shared_ptr<Ymc::MotionRequest> spMotionReq, short type)
{
    if (spMotionReq == nullptr)
        return false;
    auto& req = *spMotionReq;
    if (req.axesNo.empty()) {
        SYS_LOG_WARN("Warning AxesJogMove param axes is NULL!");
        return false;
    }

    if (m_Devices.empty())
    {
        SYS_LOG_ERROR("Ymc Axes are uninitial!");
        return false;
    }
    auto& dev = m_Devices.front();
    std::vector<HAXIS> hAxes;//单轴移动有效 
    for (auto& reqAxisNo : req.axesNo)
    {
        auto it_axis = FindAxisControllerByAxisNumber(dev, reqAxisNo);
        if (it_axis == dev.v_AxisCtl.end())
        {
            SYS_LOG_ERROR("Not find Axis:{}, check this axis is initialized", reqAxisNo);
            return false;
        }
        hAxes.emplace_back(it_axis->hAxis);
    }

    HDEVICE mv_hDev;
    DWORD rc;
    rc = ymcDeclareDevice((WORD)hAxes.size(), hAxes.data(), &mv_hDev); //临时定轴
    if (type == 0) {
        rc = ymcMoveDriverPositioning(mv_hDev, req.motionDatas.data(), req.posDatas.data(), NULL, (LPBYTE)req.objName.c_str(), req.waitForCompletions.data(), 0);
        if (rc != MP_SUCCESS) {
            SYS_LOG_ERROR("Error ymcMoveDriverPositioning,ErrorCode[ {:#x} ]", rc);
            return false;
        }
    }
    else if (type == 1) {
        rc = ymcStopMotion(mv_hDev, req.motionDatas.data(), NULL, req.waitForCompletions.data(), 0);
        if (rc != MP_SUCCESS)
            SYS_LOG_ERROR("Error ymcStopMotion,ErrorCode[ {:#x} ]", rc);
    }
    else if (type == 2) {
        rc = ymcMoveJOG(mv_hDev, req.motionDatas.data(), req.directions.data(), req.timeouts.data(), NULL, (LPBYTE)req.objName.c_str(), 0);
        if (rc != MP_SUCCESS)
            SYS_LOG_ERROR("Error ymcMoveJOG,ErrorCode[ {:#x} ]", rc);
    } 
    else if (type == 3) {
        rc = ymcStopJOG(mv_hDev, NULL, (LPBYTE)req.objName.c_str(), req.waitForCompletions.data(), 0);
        if (rc != MP_SUCCESS)
            SYS_LOG_ERROR("Error ymcStopJOG,ErrorCode[ {:#x} ]", rc);
    }
    rc = ymcClearDevice(mv_hDev);
    return true;
}

void YmcObject::MotionAPIOpen(ulong cpuNo)
{
    auto it = FindComControllerByCpuNumber(cpuNo);
    if (it != m_Devices.end())
        return;

	Ymc::ComController com;
	memset(&com, 0x00, sizeof(com));
    com.com_dev.ComDeviceType = COMDEVICETYPE_PCI_MODE;
    com.com_dev.PortNumber = 1;
    com.com_dev.CpuNumber = cpuNo;
    com.com_dev.NetworkNumber = NULL;
    com.com_dev.StationNumber = NULL;
    com.com_dev.UnitNumber = NULL;
    com.com_dev.IPAddress = NULL;
    com.com_dev.Timeout = 10000;

    ulong rc;
    rc = ymcOpenController(&com.com_dev, &com.g_hController);
    if (rc != MP_SUCCESS)
    {
        SYS_LOG_ERROR("Error ymcOpenController! ErrorCode:[ {:#x} ]", rc);
        return;
    }
    m_Devices.emplace_back(com);
    SYS_LOG_INFO("Success ymcOpenController cpu{}!",cpuNo);

    rc = ymcSetAPITimeoutValue(60000);
    if (rc != MP_SUCCESS)
    {
        SYS_LOG_ERROR("Error ymcSetAPITimeoutValue! ErrorCode [ {:#x} ]", rc);
        return;
    }
    SYS_LOG_TRACE("Success ymcSetAPITimeoutValue!");

    return;
}

void YmcObject::MotionAPIClose(ulong cpuNo)
{
    auto iter = FindComControllerByCpuNumber(cpuNo);
    if (iter == m_Devices.end())
    {
        SYS_LOG_INFO("no ymcDevice running!");
        return;
    }       

    ulong rc = ymcCloseController(iter->g_hController);
    if (rc != MP_SUCCESS)
    {
        SYS_LOG_ERROR("Error ymcCloseController! ErrorCode [ {:#x} ]", rc);
    }
    m_Devices.erase(iter);
    SYS_LOG_INFO("Success ymcCloseController!");
    return;
}

void YmcObject::MotionAPICloseAll()
{
    for (auto& dev : m_Devices)
    {
        ulong rc = ymcCloseController(dev.g_hController);
        if (rc != MP_SUCCESS)
        {
            SYS_LOG_ERROR("Error ymcCloseController! cpuNumber:{},ErrorCode [ {:#x} ]", dev.com_dev.CpuNumber, rc);
        }
    }
    m_Devices.clear();
    SYS_LOG_INFO("Success ymcCloseController All!");
    return;
}

void YmcObject::InitAxisDevice(ulong cpuNo)
{
    //the cpu is opened?
    auto iter_cpu = FindComControllerByCpuNumber(cpuNo);
    if (iter_cpu == m_Devices.end())
    {
        SYS_LOG_ERROR("Switched cpu is not open, please open cpu{} Control!", cpuNo);
        return;
    }
    //switches the target Machine Controller.
    DWORD rc = ymcSetController(iter_cpu->g_hController);

    rc = ymcClearAllAxes();
    std::vector<size_t> axes = { 1,2,3,6 };
    HAXIS    hAxis_test[10] = { 0 };
    for (auto i : axes)
    {
        rc = ymcDeclareAxis(1, 0, 3, i, i, REAL_AXIS, (LPBYTE)fmt::format("Axis-{}", i).c_str(), &hAxis_test[i]);
    }

    HAXIS    hAxis[10] = { 0 };
    short    i;
    for (i = 0; i < 10; i++)
    {
        ymcGetAxisHandle(PHYSICALAXIS, 1, 0, 3, i + 1, 0, 0, &hAxis[i]);
        if (0 == hAxis[i])
            continue;
        Ymc::AxisController axis;
        axis.axisNo = i + 1;
        axis.hAxis = hAxis[i];
        DWORD rc = ymcDeclareDevice(1, &hAxis[i], &axis.g_hDevice);
        if (MP_SUCCESS != rc)
        {
            SYS_LOG_WARN("Error ymcDeclareDevice! axisNo:{}, ErrorCode[ {:#x} ]", axis.axisNo, rc);
            continue;
        }
        iter_cpu->v_AxisCtl.emplace_back(axis);
    }
}

void YmcObject::AxesServoControl(ushort opt)
{
    if (m_Devices.empty()) {
        SYS_LOG_ERROR("No Ymc Controller is working!");
        return;
    }
    auto& dev = m_Devices.front();

    DWORD rc;
    for (auto& axis : dev.v_AxisCtl)
    {
        rc = ymcServoControl(axis.g_hDevice, opt, 5000);
        if (rc != MP_SUCCESS)
            SYS_LOG_WARN("Error ymcServoControl SERVO OPT:{}! cpu{} axis{},ErrorCode [ {:#x} ]", opt, dev.com_dev.CpuNumber, axis.axisNo, rc);
    }
}

std::vector<long> YmcObject::AxesUsedNumber()
{
    std::vector<long> axesNo;
    if (m_Devices.empty())
        return axesNo;
    for (auto axis : m_Devices.front().v_AxisCtl)
    {
        axesNo.emplace_back(axis.axisNo);
    }
    return axesNo;
}

std::vector<long> YmcObject::AxesMotionMonitoring(std::vector<long> axesNo, Ymc::MontionMonitor opt)
{
    std::vector<long> axesRet;
    if (m_Devices.empty())
    {
        SYS_LOG_ERROR("No ymc device is working!");
        return axesRet;
    }
    
    for (auto& axisNo : axesNo)
    {
        auto it = FindAxisControllerByAxisNumber(m_Devices.front(), axisNo);
        if (it == m_Devices.front().v_AxisCtl.end()) {
            SYS_LOG_WARN("Select valid axis:{} or axis is uninitialized!", axisNo);
            axesRet.emplace_back(0);
        }
        DWORD store = 0, rc, offset;
        offset = static_cast<DWORD>(opt);
        rc = ymcGetMotionParameterValue(it->hAxis, MONITOR_PARAMETER, offset, &store);
        if (rc != MP_SUCCESS)
            SYS_LOG_ERROR("Error ymcGetMotionParameterValue!ErrorCode[{:#x}],Monitor offset:{}", rc, offset);
        axesRet.emplace_back((long)store);
    }
    return axesRet;
}

bool YmcObject::AxesMotionSetting(std::vector<long> axesNo, std::vector<long> settings, Ymc::MontionSetting opt)
{
    if (m_Devices.empty())
    {
        SYS_LOG_ERROR("No ymc device is working! Set failed!");
        return false;
    }
    if (axesNo.size() != settings.size()) {
        SYS_LOG_ERROR("{} axes but {} settings, not equal! Set failed!");
        return false;
    }

    for (int i = 0; i < axesNo.size(); ++i)
    {
        auto it = FindAxisControllerByAxisNumber(m_Devices.front(), axesNo[i]);
        if (it == m_Devices.front().v_AxisCtl.end()) {
            SYS_LOG_WARN("Select valid axis:{} or axis is uninitialized!", axesNo[i]);
            continue;
        }
        DWORD rc;
        rc = ymcSetMotionParameterValue(it->hAxis, SETTING_PARAMETER, static_cast<DWORD>(opt), (DWORD)settings[i]);
    }
    return true;
}

std::vector<ALARM_INFO> YmcObject::AxesAlarmInfo()
{
    std::vector<ALARM_INFO> almInfo;
    if (m_Devices.empty())
        return almInfo;

    DWORD         	rc;
    HALARM        	Alarm[MAX_CURRENT_ALARM];
    ALARM_INFO	AlarmInfo[MAX_CURRENT_ALARM];
    DWORD         	AlarmNumber;
    WORD          	i;

    AlarmNumber = 0;
    memset(Alarm, 0, sizeof(HALARM) * MAX_CURRENT_ALARM);
    memset(AlarmInfo, 0, sizeof(ALARM_INFO) * MAX_CURRENT_ALARM);
    //current switched cpu Alarm generating
    auto& dev = m_Devices.front();
    for (auto& axis : dev.v_AxisCtl)
    {
        HAXIS hAxis;
        ymcGetAxisHandle(PHYSICALAXIS, 1, 0, 3, axis.axisNo, 0, 0, &hAxis);
    }
    // Gets all the alarm information. 
    rc = ymcGetAlarm(0, Alarm, AlarmInfo, &AlarmNumber);
    
    for (i = 0; i < AlarmNumber; i++)
    {
        if (0 == AlarmInfo[i].hAxis)
            continue; //无效轴
        almInfo.emplace_back(AlarmInfo[i]);
    }
    return almInfo;
}

void YmcObject::GetYmcAlarmInfo()
{
    DWORD         	rc;
    HALARM        	Alarm[MAX_CURRENT_ALARM];
    ALARM_INFO	AlarmInfo[MAX_CURRENT_ALARM];
    DWORD         	AlarmNumber;
    WORD          	i;

    AlarmNumber = 0;
    memset(Alarm, 0, sizeof(HALARM) * MAX_CURRENT_ALARM);

    //current switched cpu Alarm generating
    if (m_Devices.empty()) {
        SYS_LOG_ERROR("No Controller is working!");
        return;
    }
    auto& dev = m_Devices.front();
    for (auto& axis : dev.v_AxisCtl)
    {
        HAXIS hAxis;
        ymcGetAxisHandle(PHYSICALAXIS, 1, 0, 3, axis.axisNo, 0, 0, &hAxis);
    }

    // Gets all the alarm information. 
    rc = ymcGetAlarm(0, Alarm, AlarmInfo, &AlarmNumber);
    if (rc != MP_SUCCESS)
    {
        SYS_LOG_ERROR("Error ymcGetAlarm! ErrorCode [ {:#x} ]", rc);
        return;
    }

    // Displays the obtained alarm information.
    QVector<QString> almInfo;
    for (i = 0; i < AlarmNumber; i++)
    {
        if (0 == AlarmInfo[i].hAxis)
            continue; //无效轴
        std::string hd("<font color=red>");
        std::string tl("</font>");

        std::string str = fmt::format("ErrorCode:{:#x}, hDevice:{:#x}, hAxis:{:#x}",
            AlarmInfo[i].ErrorCode, AlarmInfo[i].hDevice, AlarmInfo[i].hAxis);

        std::string tm = fmt::format(" time:{:4d}-{:02d}-{:02d} {:02d}:{:02d}:{:02d}",
            AlarmInfo[i].Calendar.Year, AlarmInfo[i].Calendar.Month, AlarmInfo[i].Calendar.Day,
            AlarmInfo[i].Calendar.Hour, AlarmInfo[i].Calendar.Minutes, AlarmInfo[i].Calendar.Second);

        str = hd + str + tm + tl;
        almInfo.push_back(str.c_str());      
    }
    if (almInfo.empty())
        SYS_LOG_INFO("No Ymc Alarm occurred!");
    
    emit YmcAlarmInfo(almInfo);
}

void YmcObject::YmcAlarmProcessing(std::function<void(std::vector<ALARM_INFO>)> callback)
{
    if (m_Devices.empty())
        return;

    DWORD         	rc;
    HALARM        	Alarm[MAX_CURRENT_ALARM];
    ALARM_INFO	AlarmInfo[MAX_CURRENT_ALARM];
    DWORD         	AlarmNumber;
    WORD          	i;

    AlarmNumber = 0;
    memset(Alarm, 0, sizeof(HALARM) * MAX_CURRENT_ALARM);
    memset(AlarmInfo, 0, sizeof(ALARM_INFO) * MAX_CURRENT_ALARM);
    //current switched cpu Alarm generating
    auto& dev = m_Devices.front();
    for (auto& axis : dev.v_AxisCtl)
    {
        HAXIS hAxis;
        ymcGetAxisHandle(PHYSICALAXIS, 1, 0, 3, axis.axisNo, 0, 0, &hAxis);
    }
    // Gets all the alarm information. 
    rc = ymcGetAlarm(0, Alarm, AlarmInfo, &AlarmNumber);
    std::vector<ALARM_INFO> almInfo;
    for (i = 0; i < AlarmNumber; i++)
    {
        if (0 == AlarmInfo[i].hAxis)
            continue; //无效轴
        almInfo.emplace_back(AlarmInfo[i]);
    }
    if (callback != nullptr)
        callback(almInfo);
}

void YmcObject::YmcAlarmClear()
{
    DWORD	    rc;
    // Clears all the Machine Controller alarms. 
    rc = ymcClearAlarm(0);
    if (rc != MP_SUCCESS)
    {
        SYS_LOG_ERROR("Error ymcClearAlarm! ErrorCode[ {:#x} ]", rc);
        return;
    }
}

void YmcObject::ServoAlarmGenerate()
{
    /*获取正在使用的cpu,本项目只控制一个cpu,多cpu使用前需切换到目标cpu*/
    if (m_Devices.empty()) {
        SYS_LOG_ERROR("No Controller is working!");
        return;
    }  
    auto& dev = m_Devices.front();

    DWORD rc;    
    for (auto& axis : dev.v_AxisCtl)
    {
        rc = ymcServoControl(axis.g_hDevice, SERVO_ON, 5000);
        if (rc != MP_SUCCESS)
        {
            SYS_LOG_WARN("Error ymcServoControl SERVO_ON! cpu{} axis{},ErrorCode [ {:#x} ]", dev.com_dev.CpuNumber,axis.axisNo,rc);
            continue;
        }
        rc = ymcServoControl(axis.g_hDevice, SERVO_OFF, 5000);
        if (rc != MP_SUCCESS)
        {
            SYS_LOG_WARN("Error ymcServoControl SERVO_OFF! cpu{} axis{},ErrorCode [ {:#x} ]", dev.com_dev.CpuNumber, axis.axisNo, rc);
            continue;
        }
    }
}

void YmcObject::ServoAlarmClear()
{
    /*获取正在使用的cpu,本项目只控制一个cpu,多cpu使用前需切换到目标cpu*/
    if (m_Devices.empty()) {
        SYS_LOG_ERROR("No Controller is working!");
        return;
    }

    DWORD rc;
    for (auto& axis : m_Devices.front().v_AxisCtl)
    {
        rc = ymcClearServoAlarm(axis.hAxis);
        if (MP_SUCCESS != rc)
            SYS_LOG_WARN("Error ymcClearServoAlarm! cpu{} axis{},ErrorCode [ {:#x} ]", m_Devices.front().com_dev.CpuNumber, axis.axisNo, rc);
    }
}

void YmcObject::HomePosition()
{
    if (m_Devices.empty()) {
        SYS_LOG_ERROR("No Controller is working!");
        return;
    }
    auto& dev = m_Devices.front();
    //控制当前所有轴回零
    DWORD rc;
    std::vector<HAXIS> hAxes;
    for (auto& axis : dev.v_AxisCtl)
    {
        hAxes.emplace_back(axis.hAxis);
    }
    
    HDEVICE hDev;
    rc = ymcDeclareDevice((WORD)hAxes.size(), hAxes.data(), &hDev); //临时定义所有轴
    rc = ymcServoControl(hDev, SERVO_ON, 5000);
    if (MP_SUCCESS != rc) {
        SYS_LOG_ERROR("Error ymcServoControl, check servo alarm!");
        return;
    }

    // Motion data setting at phase C pulse method 
    MOTION_DATA      MotionData;        // MOTION_DATA structure
    /* Not Use MotionData.CoordinateSystem = NULL; */
    /* Not Use MotionData.MoveType= NULL; */
    MotionData.VelocityType = VTYPE_UNIT_PAR;	// Speed [reference unit/s]
    MotionData.AccDecType = ATYPE_TIME;         // Time constant specified [ms]
    /*MotionData.FilterType = FTYPE_NOTHING;*/  // Not use acceleration/deceleration filter type
    MotionData.DataType = 0x0;                  // All parameters directly specified
    /* MotionData.MaxVelocity = NULL; */
    MotionData.Acceleration = 100;              // Acceleration time constant [ms] 
    MotionData.Deceleration = 100;				// Deceleration time constant [ms]
    /* Not Use MotionData.FilterTime= NULL; */
    //MotionData.Velocity = 20000;
    MotionData.ApproachVelocity = 10000;        // Approach speed [Reference unit/s]
    MotionData.CreepVelocity = 2000;           // Creep speed (reference unit/s]
    /* Not Use MotionData.FilterTime= NULL; */
        
    

    LONG arg_Position = 0;
    POSITION_DATA    Pos;               // POSITION_DATA structure
    Pos.DataType = DATATYPE_IMMEDIATE;
    Pos.PositionData = arg_Position;

    //WORD arg_HomeMethod = HMETHOD_INPUT_C; //not work
    //WORD arg_HomeMethod = HMETHOD_C;       //not work
    WORD arg_HomeMethod = HMETHOD_ZERO;
    WORD arg_Direction = DIRECTION_NEGATIVE;

    WORD WaitForCompletion;	// Completion attribute storage variables
    //WaitForCompletion = COMMAND_STARTED;调用立即返回
    WaitForCompletion = DISTRIBUTION_COMPLETED; //运动完成返回

    MOTION_DATA      mData[8];           // MOTION_DATA structure
    POSITION_DATA    pData[8];       // POSITION_DATA structure
    WORD             hMethod[8];         // Zero point return method
    WORD             dir[8];            // Moving direction
    WORD             waitType[8];    // Attribute for completion

    for (int i = 0; i < 8; ++i)
    {
        mData[i] = MotionData;
        pData[i] = Pos;
        hMethod[i] = arg_HomeMethod;
        dir[i] = arg_Direction;
        waitType[i] = WaitForCompletion;
    }
    rc = ymcMoveHomePosition(hDev, mData, pData, hMethod, dir, 0, NULL, waitType, 0);

    if (MP_SUCCESS != rc) {
        SYS_LOG_ERROR("Error ymcMoveHomePosition! ErrorCode [ {:#x} ]", rc);
        for (auto hAxis : hAxes) {
            ymcSetMotionParameterValue(hAxis, SETTING_PARAMETER, 8, 0);
        }
        //AxesMotionSetting({ 1,2,3,6 }, { 0,0,0,0 }, Ymc::MontionSetting::MotionCommand);
    }
    
    //rc = ymcServoControl(hDev, SERVO_OFF, 5000);
    rc = ymcClearDevice(hDev); //清除临时定义所有轴
    SYS_LOG_INFO("ymc home position success");
}

void YmcObject::AxesMoveJog(std::shared_ptr<Ymc::MotionRequest> spMotionReq)
{
    AxesMotion(spMotionReq, 2);
    return;   
}

void YmcObject::AxesStopJog(std::shared_ptr<Ymc::MotionRequest> spMotionReq)
{
    AxesMotion(spMotionReq, 3);
    return;
}

bool YmcObject::AxesMovePositioning(std::shared_ptr<Ymc::MotionRequest> spMotionReq)
{
    return AxesMotion(spMotionReq, 0);
}

void YmcObject::AxesStopPositioning(std::shared_ptr<Ymc::MotionRequest> spMotionReq)
{
    AxesMotion(spMotionReq, 1);
    return;
}




