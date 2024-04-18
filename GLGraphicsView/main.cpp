#include <iostream>
#include <GLWidget.h>
#include <qapplication.h>
#include <QWidget>
#include <qlayout.h>
#include <qgraphicsview.h>
#include <qopenglwidget.h>
#include <qgraphicsscene.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include "GLWidget.h"
#include <QDebug>
#include "OpenGLPixmapItem.h"
#include "OpenGLWidgetItem.h"
#include <QGraphicsWidget>
#include <QPainter>
#include <any>
#include <filesystem>
#include "ArgsExpanding.hpp"
#include <atomic>
#include <type_traits>
#include <thread>
#include <cmath>

struct ATM
{
    int a;
    int b;
    int c;
    ATM() = default;
    ATM(int _a, int _b, int _c):a(_a),b(_b),c(_c){}
    //ATM(const ATM& a) {}
    //ATM& operator=(const ATM& a) { return *this; }
    ATM& operator++(int) {
        a++;
        b++;
        c++;
        return *this;
    } ;

    void print()
    {
        std::ostringstream oss;
        oss << "a:" << a;
        oss << ",b:" << b;
        oss << ",c:" << a;
        std::cout << oss.str() << std::endl;
    }
};

std::atomic<int> a = 0;
std::atomic<int> b = 0;

void foo()
{
    for (int i = 0; i < 100000; ++i)
    {
        a.fetch_add(1);
        //auto x = a.load(std::memory_order_relaxed);
        //++x;
        //a.store(x, std::memory_order_relaxed);
    }
}
void bar()
{
    for (int i = 0; i < 100000; ++i)
    {
        a.fetch_add(1);
        /*auto x = a.load(std::memory_order_relaxed);
        ++x;
        a.store(x, std::memory_order_relaxed);*/
    }
}

int main(int argc, char* argv[])
{
    //ATM atm0(0);
    
    static_assert(std::is_standard_layout<ATM>::value, "T is not is_standard_layout");
    static_assert(std::is_pod<ATM>::value, "T is not pod");
    static_assert(std::is_trivial<ATM>::value, "T is not trivial");
    static_assert(std::is_trivially_copyable<ATM>::value, "T is not trivially copyable.");
    std::atomic<ATM> x;
    x = { 0,0,0 };
    int y = 0;
    int z = 0;
    //std::cout << x.is_lock_free() << std::endl;
    auto writeThread = [&x, &y, &z]() {
        Sleep(30);
            for (int i = 0; i < 10; ++i) {
                y++;
                z++;
                ATM t = { 1,1,1 };
                x.store(t, std::memory_order_release);
                
            }
        };

    auto readThread = [&x, &y, &z]() {
        Sleep(30);
            for (int i = 0; i < 10; ++i) {
                //x.operator ATM().print();
                ATM tt;
                auto tx = x.load(std::memory_order_acquire);
                auto ty = y;
                auto tz = z;
                std::cout << "y:" << ty << std::endl;
                std::cout << "z:" << tz << std::endl;
                tx.print();
            }
        };
    
    auto th1 = std::thread(bar);
    auto th2 = std::thread(foo);

    th1.join();
    th2.join();
    
    std::cout << "relax:" << a.load();
    //y1 = 4, x1 = 3
    auto theta = atan2(4.0, 3.0);
    auto vx = 5 * cos(theta);
    auto vy = 5 * sin(theta);
    std::cout << "vx:" << vx << ",vy:" << vy << std::endl;
    
    return 0;
    QApplication app(argc, argv);


    auto wnd = new QWidget();
    //wnd->setFixedSize(240, 160);
    auto vlayout = new QVBoxLayout(wnd);

    auto scene = new QGraphicsScene();
    //auto imgItem = new QGraphicsPixmapItem(QPixmap("C:/zen/GL_Test/img1.png"));
    //auto imgItem = new OpenGLPixmapItem(QPixmap("C:/zen/GL_Test/img1.png"));
    auto imgItem = new QGraphicsRectItem(QRectF(0, 0, 2000, 1000));
    auto imgItem1 = new QGraphicsPixmapItem(QPixmap("d:/test/copy/inv_test.bmp"));
    auto imgItem2 = new QGraphicsPixmapItem(QPixmap("d:/test/copy/inv_test2.bmp"));
    imgItem1->setParentItem(imgItem);
    imgItem2->setParentItem(imgItem);
    imgItem2->setPos(500000, 0);


    //auto imgItem = new OpenGLPixmapItem(QPixmap("d:/test/copy/mark_inv.jpg"));
    scene->addItem(imgItem);
    //scene->addItem(imgItem1);
    //scene->addItem(imgItem2);

    /*auto imgwnd = new OpenGLWidgetItem();
    imgwnd->setGeometry(0, 0, 1000, 1000);
    scene->addItem(imgwnd);*/

    QGraphicsView* view = new QGraphicsView(wnd);
    //view->setViewport(new QOpenGLWidget());
    vlayout->addWidget(view);
    view->setScene(scene);

    qDebug() << "scene:" << scene;
    qDebug() << "view:" << view;


    auto ss = foldPrint(1, 2, "helloworld");
    std::cout << "foldPrint:" << ss.str() << std::endl;

    auto i = SumSquare<1, 2, 3>::value;
    qDebug() << "SumSquare" << i;

    auto csv_str = print_csv("dddd", "666", 1, 2, 778);
    std::cout << csv_str.str() << std::endl;

    std::cout << logMessage(0, 1, 2).str();
    

    wnd->show();

    
    return app.exec();
}