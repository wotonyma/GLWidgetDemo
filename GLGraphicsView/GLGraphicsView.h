#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>

class GLGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	GLGraphicsView(QWidget *parent = nullptr);
	~GLGraphicsView();

private:
	QGraphicsScene* _scene;
};
