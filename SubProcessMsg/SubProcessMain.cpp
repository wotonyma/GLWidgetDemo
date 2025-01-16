#include <iostream>
#include "qcoreapplication.h"

#include "laser_cfg_mgr.h"
#include "laser_ctrl.h"
#include "service_ctrl.h"

#include "Windows.h"
#define WM_USER_SUB_EXIT (WM_USER + 1024)

#include "qabstractnativeeventfilter.h"
class QuitEventFilter : public QAbstractNativeEventFilter
{
public:
	bool nativeEventFilter(const QByteArray& eventType, void* message, long* result) override
	{
		MSG* msg = static_cast<MSG*>(message);
		//std::cout << "recv message:" << msg->message << std::endl;

		if (msg->message == WM_USER_SUB_EXIT)
		{
			//std::cout << "recv message:" << msg->message << std::endl;
			//Sleep(5000);

			QCoreApplication::quit();
			return true;
		}
		return false;
	}
};

int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);

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

	/*Sleep(6000);
	std::cout << "try recv message:" << std::endl;
	MSG msg;
	GetMessage(&msg, NULL, 0, 0);
	if (msg.message == WM_USER_SUB_EXIT)
	{
		std::cout << "recv message:" << msg.message << std::endl;
		Sleep(5000);
		return 0;
	}*/

	return app.exec();
}