#pragma once

#include <memory>

class QRemoteObjectHost;
class LaserService;

class ServiceControl
{
public:
	ServiceControl(ServiceControl&) = delete;
	ServiceControl& operator=(ServiceControl&) = delete;
	~ServiceControl() = default;

	static ServiceControl& instance();
	bool start();

private:
	ServiceControl() = default;
	std::unique_ptr<QRemoteObjectHost> _host;
	std::unique_ptr<LaserService> _lsr_svc;
};