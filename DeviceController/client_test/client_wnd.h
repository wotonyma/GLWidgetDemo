#pragma once

#include "qwidget.h"

class QThread;
class ServiceNode;

class ClientWidget : public QWidget
{
	Q_OBJECT

public:
	ClientWidget(QWidget* parent = nullptr);
	~ClientWidget();

	void initThread();
	void initForm();

private:
	std::unique_ptr<QThread> _thread;
	std::unique_ptr<ServiceNode> _node;
};
