#include "laser_cfg_mgr.h"
#include "qsettings.h"
#include "qfile.h"
#include <iostream>
#include <filesystem>

bool LaserCfgMgr::Load()
{
	QString cfg_file = "config/laser.ini";
	if (!QFile::exists(cfg_file))
	{
		std::cerr << cfg_file.toStdString().c_str() << " is not exist." << std::endl;
		std::cout << std::filesystem::current_path().string() << std::endl;
		return false;
	}

	QSettings ini(cfg_file, QSettings::IniFormat);

	ini.beginGroup("Service");
	this->host = ini.value("Host").toString();
	this->port = ini.value("Port").toInt();
	ini.endGroup();

	ini.beginGroup("Ezcad");
	this->install_path = ini.value("InstallPath").toString();
	this->tmpl_path = ini.value("TmplFile").toString();
	ini.endGroup();

	return true;
}

LaserCfgMgr::LaserCfgMgr()
	: port(8889)
{
}

LaserCfgMgr& LaserCfgMgr::instance()
{
	static LaserCfgMgr ins;
	return ins;
}

LaserCfgMgr::~LaserCfgMgr()
{
}