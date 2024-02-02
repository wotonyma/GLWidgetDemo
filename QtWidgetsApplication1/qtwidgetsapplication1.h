#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtwidgetsapplication1.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtWidgetsApplication1Class; };
QT_END_NAMESPACE

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1(QWidget *parent = nullptr);
    ~QtWidgetsApplication1();

private:
    Ui::QtWidgetsApplication1Class *ui;
};
