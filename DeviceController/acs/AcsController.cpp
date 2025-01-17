#include "AcsController.h"
#include "ACSObject.h"

AcsController::AcsController(QObject *parent)
    : QObject(parent)
{
}

AcsController::~AcsController()
{
}

AcsController& AcsController::Instance()
{
    static AcsController ctl(nullptr);
    return ctl;
}

void AcsController::connectObj(ACSObject* obj)
{
    if (obj == nullptr)
        return;
    acsObj = obj;
    //connect signal and slot ...
    connect(this, &AcsController::JogNegativeSig,   acsObj, &ACSObject::JogNegative);
    connect(this, &AcsController::JogPositiveSig,   acsObj, &ACSObject::JogPositive);
    connect(this, &AcsController::MoveAbsoluteSig,  acsObj, &ACSObject::MoveAbsolute);
    connect(this, &AcsController::MoveRelativeSig,  acsObj, &ACSObject::MoveRelative);
    connect(this, &AcsController::MotionStopSig,    acsObj, &ACSObject::MotionStop);
    connect(this, &AcsController::MotionStopAllSig, acsObj, &ACSObject::MotionStopAll);
    connect(this, &AcsController::HomePositionSig,  acsObj, &ACSObject::HomePosition);
}

void AcsController::disconnectObj()
{
    disconnect();
    acsObj = nullptr;
}

bool AcsController::OpenComm(std::string ip, int port)
{
    if (acsObj)
    {
        return acsObj->OpenCommEthernetTCP(ip, port);
    }
    return false;
}

void AcsController::CloseComm()
{
    if (acsObj)
    {
        acsObj->CloseComm();
    }
}

bool AcsController::AxisEnable(int axis)
{
    if (acsObj)
    {
        return acsObj->AxisEnable(axis);
    }
    return false;
}

void AcsController::AxisDisable(int axis)
{
    if (acsObj)
    {
        acsObj->AxisDisable(axis);
    }
}

QVector<QString> AcsController::GetSysError()
{
    if (acsObj)
    {
        return acsObj->GetSysError();
    }
    return QVector<QString>();
}

int AcsController::GetServoState(int axis)
{
    if (acsObj)
    {
        return acsObj->GetServoState(axis);
    }
    return -1;
}

double AcsController::GetFPosition(int axis)
{
    if (acsObj)
    {
        return acsObj->GetFPosition(axis) / unit_cvt;
    }
    return 0.0;
}

double AcsController::GetFVelocity(int axis)
{
    if (acsObj)
    {
        return acsObj->GetFVelocity(axis) / unit_cvt;
    }
    return 0.0;
}

int AcsController::GetFault(int axis)
{
    if (acsObj)
    {
        return acsObj->GetFault(axis);
    }
    return 0.0;
}

bool AcsController::FaultClear(int axis)
{
    if (acsObj)
    {
        return acsObj->FaultClear(axis);
    }
    return false;
}

bool AcsController::SetVelocity(int axis, double velo)
{
    double nvelo = velo * unit_cvt;
    double acc = 5 * velo * unit_cvt;
    double dec = 5 * velo * unit_cvt;
    double jerk = 10 * velo * unit_cvt;
    double kdec = 10 * velo * unit_cvt;
    if (acsObj)
    {
        return acsObj->SetVelocity(axis, nvelo, acc, dec, jerk, kdec);
    }
    return false;
}

bool AcsController::MoveAbsolute(int axis, double pos)
{
    pos = pos * unit_cvt;
    if (acsObj)
    {
        return acsObj->MoveAbsolute(axis, pos);
    }
    return false;
}

bool AcsController::MoveRelative(int axis, double dist)
{
    dist = dist * unit_cvt;
    if (acsObj)
    {
        return acsObj->MoveRelative(axis, dist);
    }
    return false;
}

bool AcsController::MoveAbsoluteMuti(std::vector<int> axes, std::vector<double> points)
{
    for (auto& pos : points)
    {
        pos = pos * unit_cvt;
    }
    if (acsObj)
    {
        return acsObj->MoveAbsoluteMuti(axes, points);
    }
    return false;
}

void AcsController::JogNegativeAsync(int axis, double velo)
{
    velo = velo * unit_cvt;
    emit JogNegativeSig(axis, velo);
}

void AcsController::JogPositiveAsync(int axis, double velo)
{
    velo = velo * unit_cvt;
    emit JogPositiveSig(axis, velo);
}

void AcsController::MoveAbsoluteAsync(int axis, double pos)
{
    pos = pos * unit_cvt;
    emit MoveAbsoluteSig(axis, pos);
}

void AcsController::MoveRelativeAsync(int axis, double dist)
{
    dist = dist * unit_cvt;
    emit MoveRelativeSig(axis, dist);
}

bool AcsController::startPEG(int axis, double width , double first_point, double interval, double last_point, int tb_num, double tb_period)
{
    first_point = first_point * unit_cvt;
    interval = interval * unit_cvt;
    last_point = last_point * unit_cvt;
    if (acsObj)
    {
       return acsObj->StartPEG(axis, width, first_point, interval, last_point, tb_num, tb_period);
    }
    return false;
}

void AcsController::stopPEG(int axis)
{
    if (acsObj)
    {
        acsObj->StopPEG(axis);
    }
}
