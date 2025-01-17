#include "service_node.h"

void ServiceNode::connectToService(const QUrl& url)
{
	node = std::make_unique<QRemoteObjectNode>();
	node->connectToNode(url);
	acs_rep.reset(node->acquire<AcsServiceReplica>());
	ymc_rep.reset(node->acquire<YmcServiceReplica>());
	plc_rep.reset(node->acquire<PlcServiceReplica>());
}
