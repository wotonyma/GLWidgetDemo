#pragma once

//将所有service包裹的包裹器,使其能够在线程执行
#include "acs_service.h"
#include "ymc_service.h"
#include "plc_service.h"
#include <memory>

class ServiceObject : public QObject
{
	Q_OBJECT
public:
	std::unique_ptr<QRemoteObjectHost> host;
	std::unique_ptr<AcsService> acs;
	std::unique_ptr<YmcService> ymc;
	std::unique_ptr<PlcService> plc;

	void startService(const QUrl& url)
	{
		host = std::make_unique<QRemoteObjectHost>(url);
		acs = std::make_unique<AcsService>();
		ymc = std::make_unique<YmcService>();
		plc = std::make_unique<PlcService>();

		host->enableRemoting(acs.get());
		host->enableRemoting(ymc.get());
		host->enableRemoting(plc.get());
	}
};
