#ifndef MYWND_H
#define MYWND_H

#include <QWidget>
#include <QObject>
#include <memory>
#include <QGraphicsScene>

#include "spdlog/spdlog.h"
//#include "spdlog/sinks/stdout_color_sinks.h"
class Worker : public QObject
{
    Q_OBJECT
public slots:
    void displayMsg() 
    {
        spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
        spdlog::info("hello world");  
        std::this_thread::sleep_for(std::chrono::seconds(5));
        emit workFinish("finish");
    }
signals:
    void workFinish(std::string);
};

namespace Ui {
class myWnd;
}

class myWnd : public QWidget
{
    Q_OBJECT

public:
    explicit myWnd(QWidget *parent = nullptr);
    ~myWnd();
    bool eventFilter(QObject* watched, QEvent* event);

private slots:
    void on_firstBtn_clicked();
    void on_pushButton_clicked();
    void on_btnTest1_clicked();
    void on_BtnBig_clicked();
    void on_BtnSmall_clicked();
    void slot_test(std::string msg);

signals:
    void signal_msg(std::string msg);

private:
    Ui::myWnd *ui;
    std::shared_ptr<QGraphicsScene> m_scene;
    std::vector<std::shared_ptr<QGraphicsItem>> m_itemList;
};

#endif // MYWND_H
