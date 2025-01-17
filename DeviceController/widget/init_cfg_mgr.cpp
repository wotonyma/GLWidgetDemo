#include "init_cfg_mgr.h"
#include "qsettings.h"

InitConfigMgr& InitConfigMgr::Instance()
{
	static InitConfigMgr ins;
	return ins;
}

void InitConfigMgr::LoadCfg()
{
	QSettings ini = QSettings("config/device.ini", QSettings::IniFormat);

	ini.beginGroup("ACS");
	cfg.acs_ip = ini.value("ip").toString().toStdString();
	cfg.acs_port = ini.value("port").toInt();
	ini.endGroup();

	ini.beginGroup("Service");
	cfg.svr_host = ini.value("host").toString().toStdString();
	cfg.svr_port = ini.value("port").toInt();
	ini.endGroup();
}
