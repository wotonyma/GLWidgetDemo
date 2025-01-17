#ifndef ACSOBJECT_H
#define ACSOBJECT_H
#pragma once

#include <QObject>
#include <vector>
#include <string>
#include <QPoint>
#include "ACSC.h"

using HANDLE = void *;
const int TIMEOUT_MOTOR_ENABLED = 3000;
const int TIMEOUT_MOTOR_DISABLE = 3000;

class ACSObject : public QObject
{
    Q_OBJECT

public:
    ACSObject(QObject* parent = nullptr);
    ~ACSObject();
    void TerminatePrevConnect();

public slots:
    /*acs open*/
    bool OpenCommEthernetTCP(std::string ip, int port);
    void CloseComm();
    bool AxisEnable(int axis);
    void AxisDisable(int axis);
    bool AxisEnableAll();
    void AxisDisableAll();
    /*peg*/
    bool StartPEG(int axis,double width,double first_point, double interval, double last_point, int tb_num, double tb_period);
    void StopPEG(int axis);
    /*acs query*/
    QVector<QString> GetSysError();
    int GetServoState(int axis);
    double GetFPosition(int axis);
    double GetFVelocity(int axis);
    int GetFault(int axis);
    bool FaultClear(int axis);
    /*acs home*/
    bool HomePosition();

    /*acs motion*/
    bool SetVelocity(int axis, double velo, double acc, double dec, double jerk, double kdec);
    bool JogNegative(int axis, double velo = 0.0);
    bool JogPositive(int axis, double velo = 0.0);
    bool MoveAbsolute(int axis, double pos);
    bool MoveRelative(int axis, double dist);
    bool MoveAbsoluteMuti(std::vector<int> axes, std::vector<double> points);
    bool MotionStop(int axis);
    bool MotionStopAll();

private:
    HANDLE m_hAcsComm;
    int g_nTotalAxes;
    int g_nTotalBuffer;

};

#endif // ACSOBJECT_H
