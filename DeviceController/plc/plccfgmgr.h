#pragma once

#include <unordered_map>
#include <string>

struct PlcControl {
	std::string mode;
	std::string stop_all;
};

struct AxisAddr {
	std::string abs_on;
	std::string pos;
	std::string jog_n;
	std::string jog_p;
	std::string home;
	std::string home_flag;
	std::string init;
	std::string init_flag;
	std::string p2p;
	std::string p2p_flag;
	std::string dest;
	std::string velo;
	std::string stop;
	std::string jog_velo;
};

enum class PlcAxis {
	AXIS_M1 = 1 << 0,
	AXIS_M2 = 1 << 1,
	AXIS_M3 = 1 << 2,
	AXIS_M4 = 1 << 3,
	AXIS_M5 = 1 << 4,
	AXIS_M6 = 1 << 5
};

class PLCCfgMgr
{
public:
	static PLCCfgMgr& instance();
	bool load();
	const std::unordered_map<std::string, AxisAddr> getAxesAddrMap() const;
	const AxisAddr& getAddr(std::string name) const;
	const AxisAddr& getAddr(PlcAxis axis) const;
	const PlcControl& getPlcControlAddr() const;
	long getStationNumber() const;
private:
	PLCCfgMgr();
	~PLCCfgMgr();
	PLCCfgMgr(const PLCCfgMgr&) = delete;
	PLCCfgMgr& operator=(const PLCCfgMgr&) = delete;

	std::string cfgPath;
	std::unordered_map<std::string, AxisAddr> plcAxisAddrMap;
	std::unordered_map<PlcAxis, AxisAddr> enumAxisAddrMap;
	PlcControl plcControl;
	long stationNumber;
};