#include "plcobject.h"
#include "melsecplc.h"
#include "melexception.h"
#include "log.h"
#include <thread>
#include <numeric>
#include <QTime>
#include <QTimer>
#include <QCoreApplication>
#include <QEventLoop>`

PLCObject::PLCObject(QObject *parent)
	: QObject(parent)
	,plc(nullptr)
{
	qRegisterMetaType<std::string>("std::string");
	qRegisterMetaType<std::string>("std::string&");
	qRegisterMetaType<std::vector<std::string>>("std::vector<std::string>");
	qRegisterMetaType<std::vector<std::string>>("std::vector<std::string>&");
	qRegisterMetaType<std::vector<int>>("std::vector<int>");
	qRegisterMetaType<std::vector<int>>("std::vector<int>&");
	qRegisterMetaType<std::vector<short>>("std::vector<short>");
	qRegisterMetaType<std::vector<short>>("std::vector<short>&");
	qRegisterMetaType<std::function<void(std::vector<int>)>>("std::function<void(std::vector<int>)>");
}

PLCObject::~PLCObject()
{
}

bool PLCObject::waitForCompletion(const std::function<bool()>& func, int timeout)
{
	stopWait = false;
	auto timeEnd = QTime::currentTime().addMSecs(timeout);
	while (QTime::currentTime() < timeEnd)
	{
		//if user send stop order, break and return false; 不加锁有极低概率出问题
		if (stopWait)
			break;

		if (func())
			return true;
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
		std::this_thread::yield();
	}
	stopWait = false;
	return false;
}

bool PLCObject::waitForCompletion(const std::vector<std::string>& flagsAddr, short flag, int timeout)
{
	auto func = [this, &flagsAddr, flag, opResults=std::vector<short>()]() mutable {
		plc->ReadDeviceRandom16Bit(flagsAddr, opResults);
		auto sum = std::accumulate(opResults.begin(), opResults.end(), 0);
		return flagsAddr.size() * flag == sum;
		};
	return waitForCompletion(func, timeout);
}


long PLCObject::connectPLC(long no, const std::string& password)
{
	plc = std::make_shared<MelsecPLC>();
	unsigned long err =  plc->Connect(no, password);
	if (err != 0)
		SYS_LOG_ERROR("connect plc station={0}, password={1} error, errcode=[{2:#010x}]", no, password, err);
	else
		SYS_LOG_INFO("connect plc station:{0} sucessful", no);
	return err;
}

long PLCObject::disconnectPLC()
{
	try {
		return plc->Disconnect();
	}
	catch (const std::exception& e)
	{
		SYS_LOG_ERROR("disconnectPLC exception:{}",e.what());
		return 0;
	}
}

short PLCObject::readDevice16Bit(const std::string& dev)
{
	short data = 0x0;
	unsigned long err = plc->GetDevice16Bit(dev, data);
	if (err != 0)
		SYS_LOG_ERROR("plc GetDevice16Bit addr:{} error, errcode[{:#010x}]", dev, err);
	return data;
}

void PLCObject::writeDevice16Bit(const std::string& dev, short data)
{
	unsigned long err = plc->SetDevice16Bit(dev, data);
	if (err != 0)
		SYS_LOG_ERROR("plc SetDevice16Bit addr:{}={} error, errcode[{:#010x}]", dev, data, err);
}

int PLCObject::readDevice32Bit(const std::string& dev)
{
	int data = 0x0;
	unsigned long err = plc->GetDeviceINT32(dev, data);
	if (err != 0)
		SYS_LOG_ERROR("plc GetDevice32Bit addr:{} error, errcode[{:#010x}]", dev, err);
	return data;
}

void PLCObject::writeDevice32Bit(const std::string& dev, int data)
{
	unsigned long err = plc->SetDeviceINT32(dev, data);
	if (err != 0)
		SYS_LOG_ERROR("plc GetDevice32Bit addr:{}={} error, errcode[{:#010x}]", dev, data, err);
}

std::vector<short> PLCObject::readDeviceRandom16Bit(const std::vector<std::string>& devs)
{
	std::vector<short> datas;
	unsigned long err = plc->ReadDeviceRandom16Bit(devs, datas);
	if (err != 0)
		SYS_LOG_ERROR("plc ReadDeviceRandom16Bit error, errcode[{:#010x}]", err);
	return datas;
}
void PLCObject::writeDeviceRandom16Bit(const std::vector<std::string>& devs, const std::vector<short>& datas)
{
	unsigned long err = plc->WriteDeviceRandom16Bit(devs, datas);
	if (err != 0)
		SYS_LOG_ERROR("plc WriteDeviceRandomINT32 error, errcode[{:#010x}]", err);
}

std::vector<int> PLCObject::readDeviceRandom32Bit(const std::vector<std::string>& devs)
{
	std::vector<int> datas;
	unsigned long err = plc->ReadDeviceRandomINT32(devs, datas);
	if (err != 0)
		SYS_LOG_ERROR("plc ReadDeviceRandomINT32 error, errcode[{:#010x}]", err);
	return datas;
}

void PLCObject::writeDeviceRandom32Bit(const std::vector<std::string>& devs, const std::vector<int>& datas)
{
	unsigned long err = plc->WriteDeviceRandomINT32(devs, datas);
	if (err != 0)
		SYS_LOG_ERROR("plc WriteDeviceRandomINT32 error, errcode[{:#010x}]", err);
}

std::vector<int> PLCObject::monitorDevice32BitData(const std::vector<std::string>& devs, std::function<void(std::vector<int>)> process)
{
	auto datas = readDeviceRandom32Bit(devs);
	if (process != nullptr)
		process(datas);
	return datas;
}

long PLCObject::axesAbsoluteMotion(const std::vector<std::string>& p2pAddr, const std::vector<std::string>& p2pflagAddr, int timeout)
{
	assert(p2pAddr.size() == p2pflagAddr.size());

	std::vector<short> datas(p2pAddr.size(), 0x1);
	unsigned long err = plc->WriteDeviceRandom16Bit(p2pAddr, datas);

	auto br = waitForCompletion(p2pflagAddr, 0x1, timeout);
	if (br)
		return 0;
	
	SYS_LOG_ERROR("abs move timeout");
	return -1;
}

long PLCObject::homePosition(std::vector<std::string> devs, std::vector<std::string> flags, int timeout)
{	
	auto ret = axesAbsoluteMotion(devs, flags, timeout);
	if (ret < 0)
		SYS_LOG_ERROR("home position timeout");
	else
		SYS_LOG_INFO("home position success");
	return ret;
}

long PLCObject::initPosition(std::vector<std::string> initAddrs, std::vector<std::string> initflagAddrs, int timeout)
{
	if (initAddrs.size() != initflagAddrs.size()) {
		SYS_LOG_ERROR("count of init address not equal initflag address");
		return -1;
	}

	//此plc初始化的信号需要持续1s以上，但是不能一直持续
	auto pressSigs = std::vector<short>(initAddrs.size(), 0x1);
	plc->WriteDeviceRandom16Bit(initAddrs, pressSigs);
	QEventLoop loop;
	QTimer::singleShot(2000, &loop, &QEventLoop::quit);
	loop.exec();
	auto releaseSigs = std::vector<short>(initAddrs.size(), 0x0);
	plc->WriteDeviceRandom16Bit(initAddrs, releaseSigs);

	auto ret = waitForCompletion(initflagAddrs, 0x1, timeout);

	if (ret)
		SYS_LOG_INFO("axes init position success");
	else
		SYS_LOG_ERROR("axes init position timeout");

	return ret;
}

/*void axesStopMotion(std::vector<std::string> stopAddrs)
{

}*/

