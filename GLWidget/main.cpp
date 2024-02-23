#include <iostream>
#include <GLWidget.h>
#include <qapplication.h>
#include <QWidget>
#include <qlayout.h>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget wnd;
    QVBoxLayout vb_layout(&wnd);
    

    GLWidget w1(&wnd);
    //w1.setGeometry(0, 0, 480, 320);

    GLWidget w2(&wnd);
    w2.setGeometry(0, 340, 480, 320);

    vb_layout.addWidget(&w1, 1);
    vb_layout.addWidget(&w2, 1);

    //wnd.setLayout(&vb_layout);
    wnd.show();

    return app.exec();
}