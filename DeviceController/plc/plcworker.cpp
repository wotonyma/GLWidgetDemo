#include "plcworker.h"
#include "melexception.h"
#include "combaseapi.h"

PLCWorker::PLCWorker(QObject* parent)
	: QObject(parent)
	, plcThread(nullptr)
	, plcObject(nullptr)
{
}

PLCWorker::~PLCWorker()
{
	stop();
}

bool PLCWorker::start()
{
	plcThread = std::make_shared<QThread>();
	plcObject = std::make_shared<PLCObject>();
	plcObject->moveToThread(plcThread.get());
	connectPLCObject();
	plcThread->start();
	return true;
}

void PLCWorker::stop()
{
	if (plcObject != nullptr)
	{
		plcObject->disconnectPLC();
		plcObject = nullptr;
	}

	if (plcThread != nullptr)
	{
		plcThread->quit();
		plcThread->wait();
		plcThread = nullptr;
	}
}

void PLCWorker::connectPLCObject()
{
	auto plc = plcObject.get();
	connect(this,&PLCWorker::openPLCSig, plc, &PLCObject::connectPLC);
	connect(this, &PLCWorker::closePLCSig, plc, &PLCObject::disconnectPLC);
	connect(this, &PLCWorker::writeDevice16BitSig, plc, &PLCObject::writeDevice16Bit);
	connect(this, &PLCWorker::writeDevice32BitSig, plc, &PLCObject::writeDevice32Bit);
	connect(this, &PLCWorker::processMonitor32bitDataSig, plc, &PLCObject::monitorDevice32BitData);
	connect(this, &PLCWorker::homePositionSig, plc, &PLCObject::homePosition);
	connect(this, &PLCWorker::initPositionSig, plc, &PLCObject::initPosition);
}

PLCWorker& PLCWorker::instance()
{
	static PLCWorker inst;
	return inst;
}

short PLCWorker::readDevice16BitSync(const std::string& dev)
{
	short ret = 0;
	QMetaObject::invokeMethod(plcObject.get(),"readDevice16Bit",Qt::BlockingQueuedConnection,
		Q_RETURN_ARG(short, ret),
		Q_ARG(std::string, dev)
	);
	return ret;
}

int PLCWorker::readDevice32BitSync(const std::string& dev)
{
	int ret = 0;
	QMetaObject::invokeMethod(plcObject.get(), "readDevice32Bit", Qt::BlockingQueuedConnection,
		Q_RETURN_ARG(int, ret),
		Q_ARG(std::string, dev)
	);
	return ret;
}

short PLCWorker::readDevice16BitDirect(const std::string& dev)
{
	short ret = 0;
	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	if (FAILED(hr))
		return ret;
	ret = plcObject->readDevice16Bit(dev);
	CoUninitialize();
	return ret;
}

int PLCWorker::readDevice32BitDirect(const std::string& dev)
{
	int ret = 0;
	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	if (FAILED(hr))
		return ret;
	ret = plcObject->readDevice32Bit(dev);
	CoUninitialize();
	return ret;
}

std::vector<short> PLCWorker::readDeviceRandom16BitSync(const std::vector<std::string>& devs)
{
	std::vector<short> datas;
	QMetaObject::invokeMethod(plcObject.get(), "readDeviceRandom16Bit", Qt::BlockingQueuedConnection,
		Q_RETURN_ARG(std::vector<short>, datas),
		Q_ARG(std::vector<std::string>, devs));
	return datas;
}

std::vector<int> PLCWorker::readDeviceRandom32BitSync(const std::vector<std::string>& devs)
{
	std::vector<int> datas;
	QMetaObject::invokeMethod(plcObject.get(), "readDeviceRandom32Bit", Qt::BlockingQueuedConnection,
		Q_RETURN_ARG(std::vector<int>, datas),
		Q_ARG(std::vector<std::string>, devs));
	return datas;
}

std::vector<double> PLCWorker::getAxesPosition(const std::vector<PlcAxis>& axes)
{
	std::vector<std::string> axesPosAddr;
	for (auto axis : axes)
		axesPosAddr.emplace_back(PLCCfgMgr::instance().getAddr(axis).pos);

	auto iDatas = readDeviceRandom32BitSync(axesPosAddr);
	std::vector<double> axesPosData;
	for (int i = 0; i < iDatas.size(); ++i)
	{
		double dPos = iDatas[i] / muti;
		axesPosData.emplace_back(dPos);
	}
	return axesPosData;
}

long PLCWorker::setAxesVelocity(const std::vector<PlcAxis>& axes, const std::vector<int>& veloVal)
{
	if (axes.size() != veloVal.size())
	{
		return -1;
	}

	std::vector<std::string> veloAddrs;
	for (auto axis : axes)
		veloAddrs.emplace_back(PLCCfgMgr::instance().getAddr(axis).velo);

	QMetaObject::invokeMethod(plcObject.get(), "writeDeviceRandom32Bit", Qt::AutoConnection,
		Q_ARG(std::vector<std::string>, veloAddrs),
		Q_ARG(std::vector<int>, veloVal)
	);
	return 0;
}

long PLCWorker::setAxesDestination(const std::vector<PlcAxis>& axes, const std::vector<double>& posVal)
{
	if (axes.size() != posVal.size())
	{
		return -1;
	}

	std::vector<std::string> destAddrs;
	std::vector<int> dests;

	for (int i = 0; i < axes.size(); ++i)
	{
		destAddrs.emplace_back(PLCCfgMgr::instance().getAddr(axes[i]).dest);
		int iPos = static_cast<int>(posVal[i] * muti);
		dests.emplace_back(iPos);
	}

	QMetaObject::invokeMethod(plcObject.get(), "writeDeviceRandom32Bit", Qt::AutoConnection,
		Q_ARG(std::vector<std::string>, destAddrs),
		Q_ARG(std::vector<int>, dests)
	);

	return 0;
}

long PLCWorker::startAxesMotion(const std::vector<PlcAxis>& axes, int type, int timeout)
{
	std::vector<std::string> p2pAddrs; //请求移动地址
	std::vector<std::string> p2pFlags; //移动完成地址
	for (auto axis : axes)
	{
		p2pAddrs.emplace_back(PLCCfgMgr::instance().getAddr(axis).p2p);
		p2pFlags.emplace_back(PLCCfgMgr::instance().getAddr(axis).p2p_flag);
	}

	long ret = 0;
	if (type == Qt::BlockingQueuedConnection) {
		QMetaObject::invokeMethod(plcObject.get(), "axesAbsoluteMotion", (Qt::ConnectionType)type,
			Q_RETURN_ARG(long, ret),
			Q_ARG(std::vector<std::string>, p2pAddrs),
			Q_ARG(std::vector<std::string>, p2pFlags),
			Q_ARG(int, timeout));
	}
	else {
		QMetaObject::invokeMethod(plcObject.get(), "axesAbsoluteMotion", (Qt::ConnectionType)type,
			Q_ARG(std::vector<std::string>, p2pAddrs),
			Q_ARG(std::vector<std::string>, p2pFlags),
			Q_ARG(int, timeout));
	}

	return ret;
}

long PLCWorker::axisAbsoluteMotion(std::vector<PlcAxis> axes, std::vector<double> pos, std::vector<int> velo, int type)
{
	if (axes.size() != pos.size() || axes.size() != velo.size())
	{
		return - 1;
	}

	//绝对运动使能
	AbsMotionEnable(axes, true);
	//写入目的地址
	setAxesDestination(axes, pos);
	//写入速度
	setAxesVelocity(axes, velo);
	//执行motion
	auto ret = startAxesMotion(axes, type);
	return ret;
}

long PLCWorker::axisRelativeMotion(std::vector<PlcAxis> axes, std::vector<double> dis, std::vector<int> velo, int type)
{
	if (axes.size() != dis.size())
	{
		return -1;
	}
	//绝对运动使能
	AbsMotionEnable(axes, true);	
	auto curpos = getAxesPosition(axes);
	for (int i = 0; i < axes.size(); ++i)
		dis[i] += curpos[i];

	setAxesDestination(axes, dis);
	setAxesVelocity(axes, velo);
	auto ret = startAxesMotion(axes, type);

	return ret;
}

void PLCWorker::stopAxesMotionAll()
{
	auto addr = PLCCfgMgr::instance().getPlcControlAddr().stop_all;
	emit writeDevice16BitSig(addr, 0x1);
	plcObject->setStopWait();
}

long PLCWorker::HomePosition(std::vector<PlcAxis> axes)
{
	AbsMotionEnable(axes, false);
	long ret = -1;
	QMetaObject::invokeMethod(plcObject.get(), [this, axes = std::move(axes)]() {
		std::vector<std::string> home_flags, fin_flags;
		for (auto axis : axes)
		{
			home_flags.emplace_back(PLCCfgMgr::instance().getAddr(axis).home);
			fin_flags.emplace_back(PLCCfgMgr::instance().getAddr(axis).home_flag);
		}
		return this->plcObject->homePosition(home_flags, fin_flags, 10 * 60 * 1000);
		}, Qt::BlockingQueuedConnection, &ret);
	return ret;
}

void PLCWorker::AbsMotionEnable(std::vector<PlcAxis> axes, bool enable)
{
	short val = static_cast<short>(enable);
	std::vector<std::string> enable_addrs;
	enable_addrs.reserve(axes.size());
	std::vector<short> vals(axes.size(), val);
	for (auto axis : axes)
	{
		enable_addrs.emplace_back(PLCCfgMgr::instance().getAddr(axis).abs_on);
	}

	QMetaObject::invokeMethod(plcObject.get(), "writeDeviceRandom16Bit", Qt::AutoConnection,
		Q_ARG(std::vector<std::string>, enable_addrs),
		Q_ARG(std::vector<short>, vals)
	);
}

void PLCWorker::AbsMotionEnable(PlcAxis axis, bool enable)
{
	short val = static_cast<short>(enable);
	auto addr = PLCCfgMgr::instance().getAddr(axis).abs_on;
	emit writeDevice16BitSig(addr, val);
}

void PLCWorker::AxisJogNegative(PlcAxis axis, int velo)
{
	AbsMotionEnable(axis, false);
	auto v_addr = PLCCfgMgr::instance().getAddr(axis).jog_velo;
	emit writeDevice32BitSig(v_addr, velo);
	auto jn_addr = PLCCfgMgr::instance().getAddr(axis).jog_n;
	emit writeDevice16BitSig(jn_addr, 0x1);
}

void PLCWorker::AxisJogPositive(PlcAxis axis, int velo)
{
	AbsMotionEnable(axis, false);
	auto v_addr = PLCCfgMgr::instance().getAddr(axis).jog_velo;
	emit writeDevice32BitSig(v_addr, velo);
	auto jp_addr = PLCCfgMgr::instance().getAddr(axis).jog_p;
	emit writeDevice16BitSig(jp_addr, 0x1);
}

void PLCWorker::AxisJogStop(PlcAxis axis)
{
	auto jn_addr = PLCCfgMgr::instance().getAddr(axis).jog_n;
	auto jp_addr = PLCCfgMgr::instance().getAddr(axis).jog_p;
	emit writeDevice16BitSig(jp_addr, 0x1);
	emit writeDevice16BitSig(jn_addr, 0x1);
}
