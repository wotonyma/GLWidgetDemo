#include "ACSWorker.h"
#include "AcsController.h"

ACSWorker::ACSWorker()
{
    acsObj = std::make_shared<ACSObject>();

    acsTh = std::make_shared<QThread>();
}

ACSWorker::~ACSWorker()
{
    acsTh->quit();
    acsTh->wait();
}

void ACSWorker::Start()
{
    acsObj->moveToThread(acsTh.get());
    AcsController::Instance().connectObj(acsObj.get());
    acsTh->start();
}
