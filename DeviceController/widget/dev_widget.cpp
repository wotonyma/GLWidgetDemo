#include "dev_widget.h"
#include "qmenu.h"
#include "qapplication.h"
#include "qevent.h"

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

#include "init_cfg_mgr.h"

DevWidget::DevWidget(QWidget* parent)
	:QWidget(parent)
{
    initForm();
    //initDevice();//此处初始化导致非调试状态启动进程rpc call无法调用成功
}

DevWidget::~DevWidget()
{
}

void DevWidget::initForm()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    menu = new QMenu(this);
    //QIcon icon(":/images/images/QtIcon.ico");
    QIcon icon("icon/rpc.ico");
    sys_icon = new QSystemTrayIcon(this);
    sys_icon->setIcon(icon);
    sys_icon->setToolTip("Device Service");
    min = new QAction("最小化", this);
    connect(min, &QAction::triggered, this, &DevWidget::hide);
    max = new QAction("最大化", this);
    connect(max, &QAction::triggered, this, &DevWidget::showMaximized);
    restor = new QAction("恢复", this);
    connect(restor, &QAction::triggered, this, &DevWidget::showNormal);
    quit = new QAction("退出", this);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
    connect(sys_icon, &QSystemTrayIcon::activated, this, &DevWidget::activatedSysTrayIcon);

    menu->addAction(min);
    menu->addAction(max);
    menu->addAction(restor);
    menu->addSeparator(); //分割
    menu->addAction(quit);
    sys_icon->setContextMenu(menu);
    sys_icon->show();
    close();
}

void DevWidget::initDevice()
{
    //启动ymc
    auto ymc = std::make_shared<YmcWorker>();
    SYS_LOG_INFO("Ymc service start...");
    ymc->Start();
    YmcController::Instance().MotionAPIOpenSignal(1);
    YmcController::Instance().InitAxisDeviceSignal(1);

    //启动acs
    auto acs = std::make_shared<ACSWorker>();
    SYS_LOG_INFO("ACS service start...");
    acs->Start();
    auto acs_ip = InitConfigMgr::Instance().Cfg().acs_ip;
    auto acs_port = InitConfigMgr::Instance().Cfg().acs_port;
    if (!AcsController::Instance().OpenComm(acs_ip, acs_port))
    {
        SYS_LOG_ERROR("ACS connect error!");
    }
    else
    {
        SYS_LOG_INFO("Success connect ACS controller!");
    }

    //启动PLC
    if (PLCCfgMgr::instance().load())
    {
        SYS_LOG_INFO("PLC service start...");
        PLCWorker::instance().start();
        auto stationNumber = PLCCfgMgr::instance().getStationNumber();
        PLCWorker::instance().openPLCSig(stationNumber, " ");
    }
    else
    {
        SYS_LOG_ERROR("find plc config error!");
    }

    //启动服务
    auto svr_host = InitConfigMgr::Instance().Cfg().svr_host;
    auto svr_port = InitConfigMgr::Instance().Cfg().svr_port;
    QUrl url;
    url.setScheme("tcp");
    url.setHost(svr_host.c_str());
    url.setPort(svr_port);
    ServiceWorker::instance().startService(url);
}

void DevWidget::closeEvent(QCloseEvent* event)
{
    if (sys_icon->isVisible())
    {
        this->hide();
        sys_icon->showMessage("DeviceService", "ACS & Ymc & PLC Service");
        event->ignore();
    }
    else {
        event->accept();
    }
}

void DevWidget::activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {

    case QSystemTrayIcon::Trigger:
        break;
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    default:
        break;
    }
}
