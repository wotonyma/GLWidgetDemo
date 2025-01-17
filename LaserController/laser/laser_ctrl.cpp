#include "laser_ctrl.h"

#include "laser.h"
#include "jcz2_laser.h"
#include "laser_cfg_mgr.h"

LaserControl& LaserControl::instance()
{
	static LaserControl ins;
	return ins;
}

bool LaserControl::initial()
{
	//具体激光器对象为 金橙子2代
	auto laser = std::make_unique<JCZ2Laser>();
	auto ezd_path = LaserCfgMgr::instance().install_path;
	laser->SetEzdPath(ezd_path);

	_laser = std::move(laser);
	return true;
}

Laser& LaserControl::laser()
{
	return *_laser;
}
