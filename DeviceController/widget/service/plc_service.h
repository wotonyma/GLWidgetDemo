#pragma once

#include "rep_plc_service_source.h"
#include "plccfgmgr.h"

class PlcService : public PlcServiceSource
{
	Q_OBJECT
public:
    explicit PlcService(QObject* parent = nullptr) : PlcServiceSource(parent)
    {
    }

public:
    ~PlcService() override = default;
    virtual QVector<double> AxesPosition(QVector<int> axes) override;
    virtual bool AxesAbsoluteMotion(QVector<int> axes, QVector<double> pos, QVector<double> velo) override;
    virtual bool AxisAbsoluteMotion(int axis, double pos, double velo) override;
    virtual bool AxisRelativeMotion(int axis, double pos, double velo) override;
    virtual bool AxisStopMotion(int axis) override;
    virtual bool AxisJogPositive(int axis, double velo) override;
    virtual bool AxisJogNegative(int axis, double velo) override;
    virtual bool AxisJogStop(int axis) override;
    virtual bool HomePosition() override;

private:
    //int类型数字轴转enum类型轴
    PlcAxis ToEnumAxis(int axis);
};