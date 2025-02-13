#include <iostream>
#include "qcoreapplication.h"

#include "laser_cfg_mgr.h"
#include "laser_ctrl.h"
#include "service_ctrl.h"

#include "laser.h"

#include "Windows.h"
#define WM_USER_SUB_EXIT (WM_USER + 1024)

#include "qabstractnativeeventfilter.h"
class QuitEventFilter : public QAbstractNativeEventFilter
{
public:
	bool nativeEventFilter(const QByteArray& eventType, void* message, long* result) override
	{
		MSG* msg = static_cast<MSG*>(message);

		if (msg->message == WM_USER_SUB_EXIT)
		{
			QCoreApplication::quit();
			return true;
		}
		return false;
	}
};

int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);

	//安装事件过滤器以便接收主线程的退出消息
	QuitEventFilter eventFilter;
	app.installNativeEventFilter(&eventFilter);

	//ini配置管理
	if (!LaserCfgMgr::instance().Load())
	{
		std::cerr << "load laser config failed!" << std::endl;
		return 0;
	}

	//实例化全局Laser对象
	LaserControl::instance().initial();

	//启动LaserService服务
	ServiceControl::instance().start();

	LaserControl::instance().laser().laser_Open();
	LaserControl::instance().laser().laser_LoadMarkFile("D:\\TestFile\\test.ezd");

	QVector<QPointF> pts;
	pts << QPointF(0, 0) << QPointF(0, 1) << QPointF(1, 1) << QPointF(1, 0);
	//LaserControl::instance().laser().laser_AddPolygon("poly3", pts, false);
	//LaserControl::instance().laser().laser_AddPolygon("poly3", pts, true);
	//LaserControl::instance().laser().laser_EnableHatchEnt("rect", true, 0.03, 1);
	LaserControl::instance().laser().laser_EnableHatchEnt("rect", false, 0.03, 1);
	LaserControl::instance().laser().laser_SaveToFile("D:\\TestFile\\test3.ezd");
 
	LaserControl::instance().laser().laser_Close();

	return app.exec();
}