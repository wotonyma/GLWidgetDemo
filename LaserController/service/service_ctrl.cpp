#include "service_ctrl.h"
#include "laser_service.h"
#include "laser_cfg_mgr.h"

ServiceControl& ServiceControl::instance()
{
	static ServiceControl ins;
	return ins;
}

bool ServiceControl::start()
{
	auto ip = LaserCfgMgr::instance().host;
	auto port = LaserCfgMgr::instance().port;

	QUrl url;
	url.setScheme("tcp");
	url.setHost(ip);
	url.setPort(port);

	_host = std::make_unique<QRemoteObjectHost>(url);
	_lsr_svc = std::make_unique<LaserService>();
	_host->enableRemoting(_lsr_svc.get());

	return true;
}
