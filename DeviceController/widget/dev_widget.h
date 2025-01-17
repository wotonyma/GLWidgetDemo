#pragma once

#include "qwidget.h"
#include "qsystemtrayicon.h"

class DevWidget : public QWidget
{
	Q_OBJECT

public:
	DevWidget(QWidget* parent = nullptr);
	~DevWidget();

	static void initDevice();

private:
	void initForm();
	

	virtual void closeEvent(QCloseEvent* event) override;
	void activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);

	QSystemTrayIcon* sys_icon;
	QMenu* menu;
	QAction* min;
	QAction* max;
	QAction* restor;
	QAction* quit;
};

