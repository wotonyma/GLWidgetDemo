#include "service_worker.h"
#include "service_obj.h"
#include "qthread.h"

#include <exception>
#include "log.h"

ServiceWorker::ServiceWorker()
{
}

ServiceWorker& ServiceWorker::instance()
{
	static ServiceWorker ins;
	return ins;
}

ServiceWorker::~ServiceWorker()
{
	stopService();
}

void ServiceWorker::startService(const QUrl& url)
{
	_th = std::make_unique<QThread>();
	_th->start();

	_svc_obj = std::make_unique<ServiceObject>();
	_svc_obj->moveToThread(_th.get());

	QMetaObject::invokeMethod(_svc_obj.get(), [this, url] {
		try 
		{
			this->_svc_obj->startService(url);
		}
		catch(const std::exception& e)
		{
			SYS_LOG_ERROR("{}", e.what());
		}
		});
}

void ServiceWorker::stopService()
{
	if (_th)
	{
		_th->quit();
		_th->wait();
		_th.reset();
	}
	
}
