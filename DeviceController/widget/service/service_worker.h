#pragma once

#include <memory>
#include "qurl.h"

class QThread;
class ServiceObject;

class ServiceWorker
{
public:
	static ServiceWorker& instance();
	ServiceWorker(const ServiceWorker&) = default;
	ServiceWorker& operator=(const ServiceWorker&) = default;
	~ServiceWorker();

	void startService(const QUrl& url);
	void stopService();

private:
	ServiceWorker();
	std::unique_ptr<QThread> _th;
	std::unique_ptr<ServiceObject> _svc_obj;
};

