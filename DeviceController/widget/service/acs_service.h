#pragma once

#include "rep_acs_service_source.h"

class AcsService : public AcsServiceSource
{
    Q_OBJECT

public:
    explicit AcsService(QObject* parent = nullptr) : AcsServiceSource(parent)
    {
    }

public:
    ~AcsService() override = default;

    virtual bool AxisEnable(int axis, bool st) override;
    virtual QPointF AxisXYPosition() override;
    virtual double AxisPosition(int axis) override;
    virtual double AxisVelocity(int axis) override;
    virtual bool SetAxisVelocity(int axis, double velo) override;
    virtual bool AxisAbsoluteMotion(int axis, double pos) override;
    virtual bool AxisRelativeMotion(int axis, double dist) override;
    virtual bool AxisXYAbsoluteMotion(double x, double y) override;
    virtual bool AxisJogPositive(int axis, double velo) override;
    virtual bool AxisJogNegative(int axis, double velo) override;
    virtual bool AxisStopMotion(int axis) override;
    virtual bool AxisStopMotionAll() override;
    virtual bool HomePosition() override;
    virtual bool StartPEG(int axis, double width, double sp, double interval, double ep, int tb_num, double tb_period) override;
    virtual bool StopPEG(int axis) override;


private:
};