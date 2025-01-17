#pragma once

#include "qobject.h"
#include <memory>
#include "rep_plc_service_replica.h"
#include "rep_acs_service_replica.h"
#include "rep_ymc_service_replica.h"

class ServiceNode : public QObject
{
	Q_OBJECT

public:
	std::unique_ptr<QRemoteObjectNode> node;
	std::unique_ptr<AcsServiceReplica> acs_rep;
	std::unique_ptr<YmcServiceReplica> ymc_rep;
	std::unique_ptr<PlcServiceReplica> plc_rep;

	void connectToService(const QUrl& url);
};