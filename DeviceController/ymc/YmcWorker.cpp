#include "YmcWorker.h"
#include "YmcController.h"

YmcWorker::YmcWorker(QObject *parent)
	:QObject(parent)
{
	ymcObj = std::make_shared<YmcObject>();
	ymcTh = std::make_shared<QThread>();
}

YmcWorker::~YmcWorker()
{
	YmcController::Instance().disconnectObj();
	ymcTh->quit();
	ymcTh->wait();	
}

void YmcWorker::Start()
{
	ymcObj->moveToThread(ymcTh.get());
	YmcController::Instance().connectObj(ymcObj.get());
	ymcTh->start();
}
