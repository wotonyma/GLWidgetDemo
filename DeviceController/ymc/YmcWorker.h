#pragma once

#include "YmcObject.h"
#include <memory>
#include <QThread>

class YmcWorker : public QObject
{	
	Q_OBJECT
public:
	std::shared_ptr<YmcObject> ymcObj;
	std::shared_ptr<QThread> ymcTh;

	explicit YmcWorker(QObject *parent = nullptr);
	~YmcWorker();
	YmcWorker(const YmcWorker& src) = delete;
	YmcWorker& operator=(const YmcWorker& src) = delete; //qobject���󲻿ɸ����ƶ�

	void Start();
};
