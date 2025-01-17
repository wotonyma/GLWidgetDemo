#include "plccfgmgr.h"
#include "fmt/format.h"
#include <filesystem>
#include <QSettings>

PLCCfgMgr::PLCCfgMgr()
{
	stationNumber = 1;
	auto path = std::filesystem::current_path();
	path = path / "config" / "melsecplc.ini";
	cfgPath = path.string();
}

PLCCfgMgr::~PLCCfgMgr()
{

}

PLCCfgMgr& PLCCfgMgr::instance()
{
	static PLCCfgMgr cfg;
	return cfg;
}

bool PLCCfgMgr::load()
{
	if (!std::filesystem::exists(cfgPath))
		return false;

	std::vector<std::string> axes = {"m1","m2","m3","m4","m5","m6"};
	auto iniFile = QSettings(cfgPath.c_str(), QSettings::IniFormat);
	for (auto& axis : axes)
	{
		AxisAddr addr;
		auto name = fmt::format("axis_{}", axis);
		addr.abs_on = iniFile.value(std::string(name + "/abs_on").c_str()).toString().toStdString();
		addr.pos = iniFile.value(std::string(name + "/pos").c_str()).toString().toStdString();
		addr.jog_n = iniFile.value(std::string(name + "/jog_n").c_str()).toString().toStdString();
		addr.jog_p = iniFile.value(std::string(name + "/jog_p").c_str()).toString().toStdString();
		addr.home = iniFile.value(std::string(name + "/home").c_str()).toString().toStdString();
		addr.home_flag = iniFile.value(std::string(name + "/home_flag").c_str()).toString().toStdString();
		addr.init = iniFile.value(std::string(name + "/init").c_str()).toString().toStdString();
		addr.init_flag = iniFile.value(std::string(name + "/init_flag").c_str()).toString().toStdString();
		addr.p2p = iniFile.value(std::string(name + "/p2p").c_str()).toString().toStdString();
		addr.p2p_flag = iniFile.value(std::string(name + "/p2p_flag").c_str()).toString().toStdString();
		addr.dest = iniFile.value(std::string(name + "/dest").c_str()).toString().toStdString();
		addr.velo = iniFile.value(std::string(name + "/velo").c_str()).toString().toStdString();
		addr.stop = iniFile.value(std::string(name + "/stop").c_str()).toString().toStdString();
		addr.jog_velo = iniFile.value(std::string(name + "/jog_velo").c_str()).toString().toStdString();

		plcAxisAddrMap.insert_or_assign(name, addr);
	}

	stationNumber = iniFile.value("login/station").toString().toInt();

	plcControl.mode = iniFile.value("control/mode").toString().toStdString();
	plcControl.stop_all = iniFile.value("control/stop_all").toString().toStdString();

	//enum class
	enumAxisAddrMap.insert_or_assign(PlcAxis::AXIS_M1, getAddr("axis_m1"));
	enumAxisAddrMap.insert_or_assign(PlcAxis::AXIS_M2, getAddr("axis_m2"));
	enumAxisAddrMap.insert_or_assign(PlcAxis::AXIS_M3, getAddr("axis_m3"));
	enumAxisAddrMap.insert_or_assign(PlcAxis::AXIS_M4, getAddr("axis_m4"));
	enumAxisAddrMap.insert_or_assign(PlcAxis::AXIS_M5, getAddr("axis_m5"));
	enumAxisAddrMap.insert_or_assign(PlcAxis::AXIS_M6, getAddr("axis_m6"));
	return true;
}

const std::unordered_map<std::string, AxisAddr> PLCCfgMgr::getAxesAddrMap() const
{
	return plcAxisAddrMap;
}

const AxisAddr& PLCCfgMgr::getAddr(std::string name) const
{
	return plcAxisAddrMap.at(name);
}

const AxisAddr& PLCCfgMgr::getAddr(PlcAxis axis) const
{
	return enumAxisAddrMap.at(axis);
}

const PlcControl& PLCCfgMgr::getPlcControlAddr() const
{
	return plcControl;
}

long PLCCfgMgr::getStationNumber() const
{
	return stationNumber;
}