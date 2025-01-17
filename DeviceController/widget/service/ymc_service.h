#pragma once

#include "rep_ymc_service_source.h"

class YmcService : public YmcServiceSource
{
    Q_OBJECT

public:
    explicit YmcService(QObject* parent = nullptr) : YmcServiceSource(parent)
    {
    }

public:
    ~YmcService() override = default;

    virtual bool AxesEnable(bool st) override;
    virtual double AxisPosition(int axis) override;
    virtual double AxisVelocity(int axis) override;
    virtual bool AxisAbsoluteMotion(int axis, double pos, double velo) override;
    virtual bool AxisRelativeMotion(int axis, double pos, double velo) override;
    virtual bool AxisJogPositive(int axis, double velo) override;
    virtual bool AxisJogNegative(int axis, double velo) override;
    virtual bool AxisStopMotion(int axis) override;
    virtual bool AxisStopJog(int axis) override;
    virtual bool HomePosition() override;


private:
};