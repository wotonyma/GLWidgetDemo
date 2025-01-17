#ifndef ACSCONTROLLER_H
#define ACSCONTROLLER_H

#include <QObject>
#include <string>
#include <vector>
#include <filesystem>
class ACSObject;

class AcsController : public QObject
{
    Q_OBJECT
public:
    static AcsController& Instance();
    ~AcsController();

    void connectObj(ACSObject *obj);
    void disconnectObj();

    //direct call
    /*connect*/
    bool OpenComm(std::string ip, int port);
    void CloseComm();
    bool AxisEnable(int axis);
    void AxisDisable(int axis);

    /*acs query*/
    QVector<QString> GetSysError();
    int GetServoState(int axis);
    double GetFPosition(int axis);
    double GetFVelocity(int axis);
    int GetFault(int axis);
    bool FaultClear(int axis);

    bool SetVelocity(int axis, double velo);
    bool MoveAbsolute(int axis, double pos);
    bool MoveRelative(int axis, double dist);
    bool MoveAbsoluteMuti(std::vector<int> axes, std::vector<double> points);

    void JogNegativeAsync(int axis, double velo = 0.0);
    void JogPositiveAsync(int axis, double velo = 0.0);
    void MoveAbsoluteAsync(int axis, double pos);
    void MoveRelativeAsync(int axis, double dist);

    bool startPEG(int axis,double width ,double first_point, double interval, double last_point, int tb_num, double tb_period);
    void stopPEG(int axis);

private:
    AcsController(QObject *parent);
    ACSObject* acsObj = nullptr;
    const double unit_cvt = 409600;

signals:
    void JogNegativeSig(int axis, double velo = 0.0);
    void JogPositiveSig(int axis, double velo = 0.0);
    void MoveAbsoluteSig(int axis, double pos);
    void MoveRelativeSig(int axis, double dist);

    void MotionStopSig(int axis);
    void MotionStopAllSig();
    void HomePositionSig();
};

#endif // ACSCONTROLLER_H
