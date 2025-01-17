#pragma once

#include <QObject>
#include <memory>
#include <functional>
#include <string>
#include <vector>

class MelsecPLC;

class PLCObject : public QObject
{
	Q_OBJECT

public:
	PLCObject(QObject *parent = nullptr);
	~PLCObject();
	bool waitForCompletion(const std::function<bool()>& func, int timeout);
	bool waitForCompletion(const std::vector<std::string>& flagsAddr, short flag, int timeout);
	void setStopWait() { stopWait = true; }
	
public slots:
	//on/off
	long connectPLC(long no, const std::string& password);
	long disconnectPLC();
	//read/write
	short readDevice16Bit(const std::string& dev);
	void writeDevice16Bit(const std::string& dev, short data);
	int readDevice32Bit(const std::string& dev);
	void writeDevice32Bit(const std::string& dev, int data);
	std::vector<short> readDeviceRandom16Bit(const std::vector<std::string>& devs);
	void writeDeviceRandom16Bit(const std::vector<std::string>& devs, const std::vector<short>& datas);
	std::vector<int> readDeviceRandom32Bit(const std::vector<std::string>& devs);
	void writeDeviceRandom32Bit(const std::vector<std::string>& devs, const std::vector<int>& datas);
	//operate
	std::vector<int> monitorDevice32BitData(const std::vector<std::string>& devs, std::function<void(std::vector<int>)> process = nullptr);
	long axesAbsoluteMotion(const std::vector<std::string>& p2pAddr, const std::vector<std::string>& p2pflagAddr, int timeout);
	long homePosition(std::vector<std::string> devs, std::vector<std::string> flags, int timeout); //timeout unit: ms
	long initPosition(std::vector<std::string> initAddrs, std::vector<std::string> initflagAddrs, int timeout);
	//void axesStopMotion(std::vector<std::string> stopAddrs);


private:
	std::shared_ptr<MelsecPLC> plc;
	bool stopWait{ false }; //适用于同步移动
};
