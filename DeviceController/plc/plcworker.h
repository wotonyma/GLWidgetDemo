#pragma once

#include <QObject>
#include <QThread>
#include <memory>
#include "plcobject.h"
#include "plccfgmgr.h"

class PLCWorker : public QObject
{
	Q_OBJECT
public:
	static PLCWorker& instance();
	bool start();
	void stop();
	short readDevice16BitSync(const std::string& dev);
	int readDevice32BitSync(const std::string& dev);
	short readDevice16BitDirect(const std::string& dev);
	int readDevice32BitDirect(const std::string& dev);
	std::vector<short> readDeviceRandom16BitSync(const std::vector<std::string>& devs);
	std::vector<int> readDeviceRandom32BitSync(const std::vector<std::string>& devs);

	std::vector<double> getAxesPosition(const std::vector<PlcAxis>& axes);
	long setAxesVelocity(const std::vector<PlcAxis>& axes, const std::vector<int>& veloVal);
	long setAxesDestination(const std::vector<PlcAxis>& axes, const std::vector<double>& posVal);
	long startAxesMotion(const std::vector<PlcAxis>& axes, int type = Qt::BlockingQueuedConnection, int timeout = 3 * 60 * 1000);
	long axisAbsoluteMotion(std::vector<PlcAxis> axes, std::vector<double> pos, std::vector<int> velo, int type = Qt::BlockingQueuedConnection);
	long axisRelativeMotion(std::vector<PlcAxis> axes, std::vector<double> dis, std::vector<int> velo, int type = Qt::BlockingQueuedConnection);
	void stopAxesMotionAll();
	//void axesStopMotion(std::vector<PlcAxis>);
	long HomePosition(std::vector<PlcAxis> axes);
	void AbsMotionEnable(std::vector<PlcAxis> axes, bool enable);  //绝对运动使能.abs运动需开启,jog运动需要关闭
	void AbsMotionEnable(PlcAxis axis, bool enable);
	void AxisJogNegative(PlcAxis axis, int velo);
	void AxisJogPositive(PlcAxis axis, int velo);
	void AxisJogStop(PlcAxis axis);

signals:
	void openPLCSig(long stationNumber, const std::string& password);
	void closePLCSig();
	void homePositionSig(const std::vector<std::string>& devs, const std::vector<std::string>& flags, int timeout);
	void initPositionSig(const std::vector<std::string>& devs, const std::vector<std::string>& flags, int timeout);
	void writeDevice16BitSig(const std::string& dev, short data);
	void writeDevice32BitSig(const std::string& dev, int data);
	void processMonitor32bitDataSig(const std::vector<std::string>& devs, std::function<void(std::vector<int>)>process);

public:
	std::shared_ptr<QThread> plcThread;
	std::shared_ptr<PLCObject> plcObject;
private:
	PLCWorker(QObject* parent = nullptr);
	~PLCWorker();
	PLCWorker(const PLCWorker& worker) = delete;
	PLCWorker& operator=(const PLCWorker&) = delete;
	void connectPLCObject();

	const int muti = 1000; //unit exchange
};