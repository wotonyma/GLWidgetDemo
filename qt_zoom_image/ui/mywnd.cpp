#include "mywnd.h"
#include "ui_mywnd.h"
#include <QMessageBox>
#include <QGraphicsItem>
#include <QThread>
#include <QImage>
#include <QEvent>
#include <QMouseEvent>
#include <thread>
//#include "opencv2/opencv.hpp"
#include "fmt/format.h"
#include "spdlog/spdlog.h"

//using namespace cv;

myWnd::myWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWnd)
{
    ui->setupUi(this);
    qRegisterMetaType<std::string>("std::string");//注册该类型
    //connect(this, &myWnd::signal_msg, this, &myWnd::slot_test);
    m_scene = std::make_shared<QGraphicsScene>();
    ui->graphicsView->setScene(m_scene.get());
    ui->graphicsView->viewport()->setMouseTracking(true); //设置跟踪鼠标
    ui->graphicsView->viewport()->installEventFilter(this); //设置事件过滤器
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //设置滑动条关闭
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);//QGraphicsView::NoDrag;//(QGraphicsView::RubberBandDrag); //设置鼠标拖拽模式
    //ui->graphicsView->viewport()->setCursor(Qt::ArrowCursor);无法一直生效
    QApplication::setOverrideCursor(Qt::ArrowCursor);//一直生效(设置鼠标形状)
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse); //设置鼠标点为操作焦点,如缩放之类
    ui->graphicsView->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
}

myWnd::~myWnd()
{
    delete ui;
}

bool myWnd::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == ui->graphicsView->viewport())
    {
        if (event->type() == QEvent::MouseMove)
        {
            QMouseEvent* mouseEvent = dynamic_cast<QMouseEvent*>(event);
            QPoint mousePos = mouseEvent->pos();
            QPointF scenePos = ui->graphicsView->mapToScene(mousePos);
            QGraphicsItem* item = ui->graphicsView->itemAt(mousePos);
            if (item != nullptr)
            {
                QPointF imgPixelPos = item->mapFromScene(scenePos);
                auto pBtn = this->findChild<QPushButton*>("btnTest1");
                pBtn->setText(QString("xy:(%1, %2)").arg(imgPixelPos.x()).arg(imgPixelPos.y()));
            }
        }
        if (event->type() == QEvent::MouseButtonRelease)
        {
            //ui->graphicsView->viewport()->setCursor(Qt::ArrowCursor);没用
        }
        if (event->type() == QEvent::Wheel)
        {
            auto wheelEvt = dynamic_cast<QWheelEvent*>(event);
            int wheelDeltaVal = wheelEvt->delta();
            if (wheelDeltaVal > 0)
            {
                ui->graphicsView->scale(1.1, 1.1);
            }
            else
            {
                ui->graphicsView->scale(1 / 1.1, 1 / 1.1);
            }
            return true;//防止事件继续传播
        }
    }
    return false;
}

void myWnd::on_firstBtn_clicked()
{
    //QMessageBox::information(nullptr, "first","sec");
    //auto console = spdlog::stdout_color_mt("console");
    //auto err_logger = spdlog::stderr_color_mt("stderr");
    //console->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%l] [%s:%!:%#] [thread %t] %v");
    //spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
    //spdlog::drop_all();

    /*auto spQObj = std::make_shared<Worker>();
    auto spQThd = std::make_shared<QThread>();
    spQObj->moveToThread(spQThd.get());
    spQThd->start();
    spQThd->quit();*/
    
    auto itemList = m_scene->items();
    auto spItem = m_itemList.back();
    m_itemList.pop_back();
    m_scene->removeItem(spItem.get());
    //m_scene->items().clear();
    auto rect = m_scene->sceneRect();
    m_scene->setSceneRect(QRectF(-5.0, -5.0, 10.0, 10.0));
    m_itemList.emplace_back(m_scene->addText("hello graphic"));
    auto w = m_scene->width();
    auto h = m_scene->height();
    return;

    auto pW = new Worker();
    //auto pW = std::make_shared<Worker>();
    auto pT = new QThread();
    
    connect(this, &myWnd::signal_msg, pW, &Worker::displayMsg);
    connect(pW, &Worker::workFinish, this, &myWnd::slot_test);
    pT->start();
    pW->moveToThread(pT);
    return;
}

void myWnd::on_pushButton_clicked()
{
   // Mat ori = cv::imread("d:/QProject/test1.jpg", IMREAD_GRAYSCALE);
    //imshow("1", ori);
    //spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] [%l] [%s:%!:%#] [thread %t] %v");
    //spdlog::info("info");
    //cv::waitKey(0);
    
    QImage image("D:/QProject/large.jpg");
    //m_scene->setSceneRect(QRectF(-4096, -5000, 10000, 12000));
    double kw = ui->graphicsView->viewport()->width() / (double)image.width();
    double kh = ui->graphicsView->viewport()->height() / (double)image.height();
    double k = std::min(kw, kh);
    ui->graphicsView->scale(k, k);
    auto pItem = m_scene->addPixmap(QPixmap::fromImage(image));
    //pItem->setPos(-4096, -5000);
    //ui->graphicsView->centerOn(QPointF(-4096, -5000));
    std::shared_ptr<QGraphicsItem> spItem(pItem);
    m_itemList.emplace_back(spItem);
    auto w = m_scene->width();
    auto h = m_scene->height();
    auto vp = ui->graphicsView->pos();
    auto vrect = ui->graphicsView->rect();
    
    return;

    emit signal_msg("hello");
    return;
    

    std::thread th([this](std::string msg){
        emit signal_msg(msg);
        emit signal_msg("second");
        //spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
        //spdlog::info("thread emit");
    }, "first");
    th.detach();
}

void myWnd::on_btnTest1_clicked()
{
    ui->graphicsView->scale(0.5, 0.5);
    return;
    QMessageBox::StandardButton result = QMessageBox::question(this, "Title", "text");
    auto pBtn = this->findChild<QPushButton*>("btnTest1");
    pBtn->setText("成功");
    
}

void myWnd::on_BtnBig_clicked()
{
    ui->graphicsView->scale(1.1, 1.1);
    auto muti = ui->graphicsView->matrix().m11();
}

void myWnd::on_BtnSmall_clicked()
{
    //ui->graphicsView->scale(0.9, 0.9);
    //std::shared_ptr<QGraphicsItem> spLine = std::make_shared<QGraphicsLineItem>();
    auto spLine = std::make_shared<QGraphicsLineItem>();
    spLine->setLine(QLineF(50, 50, 100, 100));
    spLine->setPos(500, 0);
    m_itemList.emplace_back(spLine);
    m_scene->addItem(spLine.get());
    auto p = spLine->pos();
    auto l = spLine->line();
    return;
}

void myWnd::slot_test(std::string msg)
{
    //spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    spdlog::info("UI thread get msg:{}",msg);
    //this->setWindowTitle("测试乱码情况");
     
    
}
