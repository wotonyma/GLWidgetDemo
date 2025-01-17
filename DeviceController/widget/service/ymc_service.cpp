#include "ymc_service.h"

#include "YmcController.h"

//long 类型坐标速度单位为 um
//double 类型坐标速度单位为 mm
//外部使用double是为了统一单位

bool YmcService::AxesEnable(bool st)
{
	if (st)
	{
		YmcController::Instance().AxesServoControlSignal(SERVO_ON);
	}
	else
	{
		YmcController::Instance().AxesServoControlSignal(SERVO_OFF);
	}
	return true;
}

double YmcService::AxisPosition(int axis)
{
	auto pos = YmcController::Instance().getAxesMotionMonitor({ axis }, Ymc::MontionMonitor::APOS).front();
	return pos / 1000.0;
}

double YmcService::AxisVelocity(int axis)
{
	auto velo = YmcController::Instance().getAxesMotionMonitor({ axis }, Ymc::MontionMonitor::Speed).front();
	return velo / 1000.0;
}

bool YmcService::AxisAbsoluteMotion(int axis, double pos, double velo)
{
	if (velo > 10)
		return false;
	return YmcController::Instance().AxisAbsoluteMotion(axis, pos * 1000, velo * 1000);
}

bool YmcService::AxisRelativeMotion(int axis, double pos, double velo)
{
	if (velo > 10)
		return false;
	return YmcController::Instance().AxisRelativeMotion(axis, pos * 1000, velo * 1000);
}

bool YmcService::AxisJogPositive(int axis, double velo)
{
	if (velo > 10)
		return false;
	YmcController::Instance().AxisJogPositive(axis, velo * 1000);
	return true;
}

bool YmcService::AxisJogNegative(int axis, double velo)
{
	if (velo > 10)
		return false;
	YmcController::Instance().AxisJogNegative(axis, velo * 1000);
	return true;
}

bool YmcService::AxisStopMotion(int axis)
{
	YmcController::Instance().StopMotionPositioning({ axis });
	return true;
}

bool YmcService::AxisStopJog(int axis)
{
	YmcController::Instance().StopJog({ axis });
	return true;
}

bool YmcService::HomePosition()
{
	YmcController::Instance().HomePositionSignal();
	return true;
}
