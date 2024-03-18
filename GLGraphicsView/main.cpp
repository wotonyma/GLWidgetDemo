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

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

   
    auto wnd = new QWidget();
    //wnd->setFixedSize(240, 160);
    auto vlayout = new QVBoxLayout(wnd);

    auto scene = new QGraphicsScene();
    //auto imgItem = new QGraphicsPixmapItem(QPixmap("C:/zen/GL_Test/img1.png"));
    auto imgItem = new OpenGLPixmapItem(QPixmap("C:/zen/GL_Test/img1.png"));
    scene->addItem(imgItem);
    qDebug() << imgItem->boundingRect();

    QGraphicsView* view = new QGraphicsView(wnd);
    view->setViewport(new QOpenGLWidget);
    vlayout->addWidget(view);
    view->setScene(scene);


    auto gl = new QOpenGLWidget(view);
    gl->setPalette((QPalette::Foreground, Qt::blue));
    view->setViewport(gl);


    wnd->show();


    return app.exec();
}