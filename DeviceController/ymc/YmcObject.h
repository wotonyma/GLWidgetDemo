#pragma once

#include <QObject>
#include "ymcPCAPI.h"
#include "YmcCommon.h"
#include <vector>
#include <string>
#include <memory>

class YmcObject : public QObject
{
	Q_OBJECT
private:
	std::vector<Ymc::ComController> m_Devices; //begin为正在控制的cpu
	//HDEVICE jog_hDev = 0x0; //在jogging的轴
	//HDEVICE mv_hDev = 0x0;  //在positioning的轴

public:
	explicit YmcObject(QObject *parent = nullptr);
	~YmcObject();
	YmcObject(const YmcObject&) = delete;
	YmcObject& operator=(const YmcObject&) = delete;
	std::vector<Ymc::ComController>::iterator FindComControllerByCpuNumber(ulong cpuNo);
	std::vector<Ymc::AxisController>::iterator FindAxisControllerByAxisNumber(Ymc::ComController& dev, ulong axisNo);
	void SwitchController(ulong cpuNo);
	bool AxesMotion(std::shared_ptr<Ymc::MotionRequest> spMotionReq, short type);

public slots:
	void MotionAPIOpen(ulong cpuNo);
	void MotionAPIClose(ulong cpuNo);
	void MotionAPICloseAll();
	void InitAxisDevice(ulong cpuNo);
	void AxesServoControl(ushort opt);
	//axes param monitor and set
	std::vector<long> AxesUsedNumber();
	std::vector<long> AxesMotionMonitoring(std::vector<long> axesNo, Ymc::MontionMonitor opt);
	bool AxesMotionSetting(std::vector<long>axesNo, std::vector<long>settings, Ymc::MontionSetting opt);
	//alarm
	std::vector<ALARM_INFO> AxesAlarmInfo();
	void GetYmcAlarmInfo();
	void YmcAlarmProcessing(std::function<void(std::vector<ALARM_INFO>)> callback);
	void YmcAlarmClear();	
	void ServoAlarmGenerate();
	void ServoAlarmClear();
	//HomePosition
	void HomePosition();	
	//JOG
	void AxesMoveJog(std::shared_ptr<Ymc::MotionRequest> spMotionReq);
	void AxesStopJog(std::shared_ptr<Ymc::MotionRequest> spMotionReq);
	//movePosition
	bool AxesMovePositioning(std::shared_ptr<Ymc::MotionRequest> spMotionReq);
	void AxesStopPositioning(std::shared_ptr<Ymc::MotionRequest> spMotionReq);

signals:
	void YmcAlarmInfo(QVector<QString>);
};
