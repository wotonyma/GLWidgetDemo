#pragma once

#include <QWidget>

class QLabel;
class QVBoxLayout;
class QPushButton;


class ToolPage : public QWidget
{
	Q_OBJECT

public:
	ToolPage(QWidget* parent = nullptr);
	~ToolPage();

	void addWidget(const QString& title, QWidget* widget);
	void expand();
	void collapse();

private slots:
	void onPushButtonFoldClicked();

private:
	bool _expanded;
	QLabel* _label;
	QPushButton* _btn;
	QWidget* _content;
	QVBoxLayout* _vbl_content;
};

/*********************************************/

class QScrollArea;

class ToolBox : public QWidget
{
	Q_OBJECT

public:
	ToolBox(QWidget* parent = nullptr);
	~ToolBox();
	void addWidget(const QString& title, QWidget* widget);

private:
	QScrollArea* _scroll_area;
	QVBoxLayout* _vbl_content;
};