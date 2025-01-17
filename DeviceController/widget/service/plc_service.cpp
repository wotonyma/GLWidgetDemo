#include "plc_service.h"
#include "plcworker.h"

PlcAxis PlcService::ToEnumAxis(int axis)
{
	return static_cast<PlcAxis>(1 << (axis - 1)); //3Öá => (1 << 2)
}

QVector<double> PlcService::AxesPosition(QVector<int> axes)
{
	std::vector<PlcAxis> local_axes;
	local_axes.reserve(axes.size());
	for (auto axis : axes)
	{
		local_axes.emplace_back(ToEnumAxis(axis));
	}
	auto pos = PLCWorker::instance().getAxesPosition(local_axes);
	return QVector<double>(pos.begin(), pos.end());
}

bool PlcService::AxesAbsoluteMotion(QVector<int> axes, QVector<double> pos, QVector<double> velo)
{
	std::vector<PlcAxis> local_axes;
	std::vector<double> local_pos;
	std::vector<int> local_velo;
	local_axes.reserve(axes.size());
	local_pos.reserve(pos.size());
	local_velo.reserve(velo.size());
	if (axes.size() != pos.size() && axes.size() != velo.size())
	{
		return false;
	}
	for (int i = 0; i < axes.size(); ++i)
	{
		local_axes.emplace_back(ToEnumAxis(axes[i]));
		local_pos.emplace_back(pos[i]);
		local_velo.emplace_back((int)velo[i]);
	}
	
	long ret = -1;
	ret = PLCWorker::instance().axisAbsoluteMotion(local_axes, local_pos, local_velo);
	return ret >= 0;
}

bool PlcService::AxisAbsoluteMotion(int axis, double pos, double velo)
{
	long ret = PLCWorker::instance().axisAbsoluteMotion({ ToEnumAxis(axis) }, { pos }, { (int)velo });
	return ret >= 0;
}

bool PlcService::AxisRelativeMotion(int axis, double pos, double velo)
{
	long ret = PLCWorker::instance().axisRelativeMotion({ ToEnumAxis(axis) }, { pos }, { (int)velo });
	return ret >= 0;
}

bool PlcService::AxisStopMotion(int axis)
{
	return false;//to do...
}

bool PlcService::AxisJogPositive(int axis, double velo)
{
	PLCWorker::instance().AxisJogPositive(ToEnumAxis(axis), int(velo));
	return true;
}

bool PlcService::AxisJogNegative(int axis, double velo)
{
	PLCWorker::instance().AxisJogNegative(ToEnumAxis(axis), int(velo));
	return true;
}

bool PlcService::AxisJogStop(int axis)
{
	PLCWorker::instance().AxisJogStop(ToEnumAxis(axis));
	return true;
}

bool PlcService::HomePosition()
{
	auto ret = PLCWorker::instance().HomePosition({
		PlcAxis::AXIS_M1,
		PlcAxis::AXIS_M2,
		PlcAxis::AXIS_M3,
		PlcAxis::AXIS_M4,
		PlcAxis::AXIS_M5,
		PlcAxis::AXIS_M6,
		});
	return ret >= 0;
}


