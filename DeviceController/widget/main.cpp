#include <iostream>
#include "qapplication.h"

#include "log_cfg_mgr.h"
#include "log.h"
#include "spdlog/spdlog.h"
#include "ACSWorker.h"
#include "AcsController.h"
#include "YmcWorker.h"
#include "YmcController.h"
#include "plcworker.h"
#include "plccfgmgr.h"
#include "service/service_worker.h"

#include "dev_widget.h"
#include "init_cfg_mgr.h"

#include "sub_proc/sub_proc_ctrl.h"

int main(int argc, char* argv[])
{

	QApplication app(argc, argv);
	app.processEvents();

	//启动日志
	if (!LogConfigMgr::Instance().Load()) 
	{
		spdlog::warn("load log config file false, using default config!");
	}
	spdlog::info("logger load success!");
	Logger::Instance().Start();

	//mgr load
	InitConfigMgr::Instance().LoadCfg();

	//启动laser子进程
	std::string subAppPath = "SubProcess/LaserCtrl.exe";
	SubProcessCtrl subProc;
	if (!std::filesystem::exists(subAppPath)) {
		spdlog::warn("{} not exist.", subAppPath);
	}
	else {
		subProc.SetApplicationPath(subAppPath);
		subProc.StartSubProcess();
	}

    DevWidget w;
    w.show();
	DevWidget::initDevice();

	auto ret = app.exec();
    PLCWorker::instance().stop();
    ServiceWorker::instance().stopService();
	subProc.ExitSubProcess();
	spdlog::drop_all();
	return 0;
}