#ifndef ACSWORKER_H
#define ACSWORKER_H

#pragma once

#include <QThread>
#include "ACSObject.h"
#include <memory>

class ACSWorker
{
public:
    ACSWorker();
    ~ACSWorker();
    void Start();

private:
    std::shared_ptr<ACSObject> acsObj;
    std::shared_ptr<QThread> acsTh;
};

#endif // ACSWORKER_H
