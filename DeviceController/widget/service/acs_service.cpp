#include "acs_service.h"

#include "AcsController.h"

//均为同步阻塞调用
//Axis 1 = 非龙门轴
//Axis 0 = 龙门主轴
//使用中以龙门轴为Y轴

bool AcsService::AxisEnable(int axis, bool st)
{
    if (st)
    {
        return AcsController::Instance().AxisEnable(axis);
    }
    else
    {
        AcsController::Instance().AxisDisable(axis);
        return true;
    }
    return false;
}

QPointF AcsService::AxisXYPosition()
{
    auto xpos = AcsController::Instance().GetFPosition(1); //非龙门轴
    auto ypos = AcsController::Instance().GetFPosition(0); //龙门轴
    return QPointF(xpos, ypos);
}

double AcsService::AxisPosition(int axis)
{
    return AcsController::Instance().GetFPosition(axis);
}

double AcsService::AxisVelocity(int axis)
{
    return AcsController::Instance().GetFVelocity(axis);
}

bool AcsService::SetAxisVelocity(int axis, double velo)
{
    return AcsController::Instance().SetVelocity(axis, velo);
}

bool AcsService::AxisAbsoluteMotion(int axis, double pos)
{
    return AcsController::Instance().MoveAbsolute(axis, pos);
}

bool AcsService::AxisRelativeMotion(int axis, double dist)
{
    return AcsController::Instance().MoveRelative(axis, dist);
}

bool AcsService::AxisXYAbsoluteMotion(double x, double y)
{
    return AcsController::Instance().MoveAbsoluteMuti({ 1, 0 }, { x, y });
}

bool AcsService::AxisJogPositive(int axis, double velo)
{
    AcsController::Instance().JogPositiveSig(axis, velo);
    return true;
}

bool AcsService::AxisJogNegative(int axis, double velo)
{
    AcsController::Instance().JogNegativeSig(axis, velo);
    return true;
}

bool AcsService::AxisStopMotion(int axis)
{
    AcsController::Instance().MotionStopSig(axis);
    return true;
}

bool AcsService::AxisStopMotionAll()
{
    AcsController::Instance().MotionStopAllSig();
    return true;
}

bool AcsService::HomePosition()
{
    AcsController::Instance().HomePositionSig();
    return true;
}

bool AcsService::StartPEG(int axis, double width, double sp, double interval, double ep, int tb_num, double tb_period)
{
    return AcsController::Instance().startPEG(axis, width, sp, interval, ep, tb_num, tb_period);
}

bool AcsService::StopPEG(int axis)
{
    AcsController::Instance().stopPEG(axis);
    return true;
}

