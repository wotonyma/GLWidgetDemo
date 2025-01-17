#include "client_wnd.h"

#include "qthread.h"
#include "service_node.h"

#include "qdebug.h"
#include "qlayout.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include "qvalidator.h"
#include "qspinbox.h"

ClientWidget::ClientWidget(QWidget* parent)
	:QWidget(parent)
{
	initThread();
	initForm();
}

ClientWidget::~ClientWidget()
{
}

void ClientWidget::initThread()
{
	_thread = std::make_unique<QThread>();
	_thread->start();

	_node = std::make_unique<ServiceNode>();
	_node->moveToThread(_thread.get());
}

void ClientWidget::initForm()
{
	this->resize(480, 360);

	auto lyt_v = new QVBoxLayout(this);
	lyt_v->setAlignment(Qt::AlignTop);

	auto lyt_v_h1 = new QHBoxLayout;
	lyt_v_h1->setAlignment(Qt::AlignLeft);
	lyt_v->addLayout(lyt_v_h1);
	auto url_text = new QLineEdit("192.168.88.6:8848");
	auto conn_btn = new QPushButton(QStringLiteral("连接"));
	lyt_v_h1->addWidget(new QLabel("url:"));
	lyt_v_h1->addWidget(url_text);
	lyt_v_h1->addWidget(conn_btn);
	//子线程连接service
	connect(conn_btn, &QPushButton::clicked, this->_node.get(), [this, url_text] {
		QUrl url("tcp://" + url_text->text());
		if (!url.isValid())
		{
			qDebug() << "invalid url format!";
		}
		//url.setScheme("tcp");
		this->_node->connectToService(url);
		});


	/**************************ACS Test*****************************/
	auto lyt_v_h2 = new QHBoxLayout;
	lyt_v_h2->setAlignment(Qt::AlignLeft);
	lyt_v->addLayout(lyt_v_h2);
	auto acs_enable_btn = new QPushButton("Y1Y2 Enable");
	//输入范围
	auto acs_pos_text = new QLineEdit;
	auto* validator = new QDoubleValidator;
	validator->setRange(0.0, 2000.0, 3);
	acs_pos_text->setValidator(validator);
	auto acs_abs_btn = new QPushButton("move");

	lyt_v_h2->addWidget(acs_enable_btn);
	lyt_v_h2->addWidget(acs_pos_text);
	lyt_v_h2->addWidget(acs_abs_btn);

	connect(acs_enable_btn, &QPushButton::clicked, this->_node.get(),[this] {
		auto rply = this->_node->acs_rep->AxisEnable(0, true);
		rply.waitForFinished();
		if (rply.returnValue())
		{
			qDebug() << "enable motor Axis_Y1Y2 success!";
		}
		});
	connect(acs_abs_btn, &QPushButton::clicked, this->_node.get(),[this, acs_pos_text] {
		auto rply0 = this->_node->acs_rep->StartPEG(0, 0.05, 1000, 0.005, 1800, -1, -1);
		rply0.waitForFinished();
		auto rply = this->_node->acs_rep->AxisAbsoluteMotion(0, acs_pos_text->text().toDouble());
		rply.waitForFinished(10 * 60 * 1000);
		if (rply.returnValue())
		{
			qDebug() << "axis absoulute move success!";
		}
		});

	/***************************YMC Test**********************/
	auto lyt_v_h3 = new QHBoxLayout;
	lyt_v_h3->setAlignment(Qt::AlignLeft);
	lyt_v->addLayout(lyt_v_h3);
	auto ymc_axis_enable = new QPushButton(QStringLiteral("ymc enable"));
	auto ymc_axis_sb = new QSpinBox;
	auto ymc_velo_text = new QLineEdit;
	//auto ymc_jogn_btn = new QPushButton("jog_n");
	//auto ymc_jogp_btn = new QPushButton("jog_p");
	auto ymc_pos_text = new QLineEdit;
	auto ymc_abs_btn = new QPushButton("abs move");

	ymc_axis_sb->setRange(1, 6);
	ymc_axis_sb->setMaximumWidth(48);
	auto* validator2 = new QDoubleValidator;
	validator2->setRange(0.0, 3.0, 3);
	ymc_velo_text->setValidator(validator2);
	lyt_v_h3->addWidget(ymc_axis_enable);
	lyt_v_h3->addWidget(ymc_axis_sb);
	lyt_v_h3->addWidget(new QLabel(QStringLiteral("velo:")));
	lyt_v_h3->addWidget(ymc_velo_text);
	//lyt_v_h3->addWidget(ymc_jogn_btn);
	//lyt_v_h3->addWidget(ymc_jogp_btn);
	lyt_v_h3->addWidget(new QLabel(QStringLiteral("pos:")));
	lyt_v_h3->addWidget(ymc_pos_text);
	lyt_v_h3->addWidget(ymc_abs_btn);

	connect(ymc_axis_enable, &QPushButton::clicked, this->_node.get(), [this] {
		auto rply = this->_node->ymc_rep->AxesEnable(true);
		rply.waitForFinished();
		if (rply.returnValue())
		{
			qDebug() << QStringLiteral("enable ymc axis success.");
		}
		});
	connect(ymc_abs_btn, &QPushButton::clicked, this->_node.get(), [this, ymc_axis_sb, ymc_velo_text, ymc_pos_text] {
		auto axis = ymc_axis_sb->value();
		auto velo = ymc_velo_text->text().toDouble();
		auto pos = ymc_pos_text->text().toDouble();
		auto rply = this->_node->ymc_rep->AxisAbsoluteMotion(axis, pos, velo);
		rply.waitForFinished();
		if (rply.returnValue())
		{
			qDebug() << QStringLiteral(" ymc axis move success.");
		}
		});

}
