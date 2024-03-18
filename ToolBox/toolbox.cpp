#include "toolbox.h"

#include <QDebug>
#include <QFormLayout>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QFile>
#include <QPushButton>
#include <QScrollArea>

ToolPage::ToolPage(QWidget* parent)
    : QWidget(parent)
    , _expanded(false)
    , _btn(nullptr)
    , _label(nullptr)
    , _content(nullptr)
    , _vbl_content(nullptr)
{
    _label = new QLabel(this);                      //label用于显示图片
    _label->setFixedSize(20, 20);
    _label->setPixmap(QPixmap(":/img/down-arrow.png").scaled(_label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    _btn = new QPushButton(this);
    QHBoxLayout* layout = new QHBoxLayout(_btn);    //按钮内部布局
    layout->setContentsMargins(0, 0, 5, 0);
    layout->addStretch(1);
    layout->addWidget(_label);                      //|--stretch-|img|

    _content = new QWidget(this);
    _content->setAttribute(Qt::WA_StyledBackground);
    _vbl_content = new QVBoxLayout(_content);
    _vbl_content->setContentsMargins(0, 0, 0, 0);
    _vbl_content->setSpacing(0);

    auto page_layout = new QVBoxLayout(this); //整体布局
    page_layout->setContentsMargins(0, 0, 0, 0);
    page_layout->setSpacing(0);
    page_layout->addWidget(_btn);
    page_layout->addWidget(_content);

    QFile file(":/qss/toolpage.qss");
    if (file.open(QIODevice::ReadOnly)) {
        setStyleSheet(file.readAll());
    }
    file.close();

    connect(_btn, &QPushButton::clicked, this, &ToolPage::onPushButtonFoldClicked);

    //fixed
    _content->hide(); //初始隐藏
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    _label->setContentsMargins(0, 0, 0, 0);
}

ToolPage::~ToolPage()
{
}

void ToolPage::addWidget(const QString& title, QWidget* widget)
{
    _btn->setText(title);
    _vbl_content->addWidget(widget);
}

void ToolPage::expand()
{
    _content->show();
    _expanded = true;
    _label->setPixmap(QPixmap(":/img/down-arrow.png").scaled(_label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void ToolPage::collapse()
{
    _content->hide();
    _expanded = false;
    _label->setPixmap(QPixmap(":/img/left-arrow.png").scaled(_label->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void ToolPage::onPushButtonFoldClicked()
{
    if (_expanded) {
        collapse();
    }
    else {
        expand();
    }
}

/********************ToolBox**********************/

ToolBox::ToolBox(QWidget* parent)
    : QWidget(parent)
    , _scroll_area(nullptr)
    , _vbl_content(nullptr)
{

    _vbl_content = new QVBoxLayout;
    _vbl_content->setContentsMargins(0, 0, 0, 0);
    _vbl_content->setSpacing(0);

    QWidget* widget = new QWidget(this);
    auto wnd_layout = new QVBoxLayout(widget);
    wnd_layout->setContentsMargins(0, 0, 0, 0);
    wnd_layout->setSpacing(0);
    wnd_layout->addLayout(_vbl_content);

    wnd_layout->addStretch(1);  //添加弹簧
    
    _scroll_area = new QScrollArea(this);
    _scroll_area->setWidgetResizable(true); //不加这个widget不会被ScroolArea拉伸 而是原有大小
    _scroll_area->setWidget(widget);
	//QScrollArea 无法通过样式改变背景色，无法去除边框
	scrollArea->setBackgroundRole(QPalette::Dark);  // 背景色

    auto layout = new QVBoxLayout(this);    //box布局
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(_scroll_area);
}

ToolBox::~ToolBox()
{
}

void ToolBox::addWidget(const QString& title, QWidget* widget)
{
    ToolPage* page = new ToolPage(this);
    page->addWidget(title, widget);
    _vbl_content->addWidget(page);
}