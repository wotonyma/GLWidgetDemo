#pragma once

#include <QObject>
#include "YmcCommon.h"
#include "YmcObject.h"
#include <functional>
#include <vector>

class YmcController : public QObject
{
	Q_OBJECT
public:	
	static YmcController& Instance();
	~YmcController();

private:
	YmcController(QObject* parent);
	YmcObject* ctlObj = nullptr;

public:
	void connectObj(YmcObject *obj);
	void disconnectObj();
	std::vector<long> getAxesMotionMonitor(std::vector<long> axesNo, Ymc::MontionMonitor opt);
	bool setAxesMotionSetting(std::vector<long> axesNo, std::vector<long> settings, Ymc::MontionSetting opt);
	std::vector<long> getAxesUsedNumber();
	std::vector<ALARM_INFO> getAxesAlarmInfo();

	//简单封装功能positioning
	std::shared_ptr<Ymc::MotionRequest> GeneratePositionMsg(std::vector<long> axesNo, std::vector<long> pos, short mv_type, long velo, WORD wait);
	void AsyncMotionPositioning(std::vector<long> axesNo, std::vector<long> pos, short mv_type, long velo = 5000);
	bool SyncMotionPositioning(std::vector<long> axesNo, std::vector<long> pos, short mv_type, long velo = 5000);
	void StopMotionPositioning(std::vector<long> axesNo);
	void StopJog(std::vector<long> axesNo);
	//11.21 huq add
	void AxisJogNegative(int axis, long velo);
	void AxisJogPositive(int axis, long velo);
	void AxisJogMotion(int axis, long velo, long direction);
	//Sync call
	bool AxisAbsoluteMotion(int axis, long pos, long velo);
	bool AxisRelativeMotion(int axis, long pos, long velo);

signals:
	void MotionAPIOpenSignal(ulong cpuNumber);
	void MotionAPICloseSignal(ulong cpuNumber);
	void MotionAPICloseAllSignal();
	void InitAxisDeviceSignal(ulong cpuNo);
	void AxesServoControlSignal(ushort opt);
	//monitor and setting
	void AxesMotionMonitorSignal(std::vector<long> axesNo, Ymc::MontionMonitor opt);
	void AxesMotionSettingSignal(std::vector<long> axesNo, std::vector<long> settings, Ymc::MontionSetting opt);
	//alarm operate
	void GetYmcAlarmSignal();
	void YmcAlarmInfoSignal(QVector<QString> info);
	void YmcAlarmProcessSignal(std::function<void(std::vector<ALARM_INFO>)> callback);
	void YmcAlarmClearSignal();	
	void ServoAlarmGenerateSignal();
	void ServoAlarmClearSignal();
	//home positon
	void HomePositionSignal();
	//jog
	void AxesMoveJogSignal(std::shared_ptr<Ymc::MotionRequest> spMotionReq);
	void AxesStopJogSignal(std::shared_ptr<Ymc::MotionRequest> spMotionReq);
	//positioning
};
