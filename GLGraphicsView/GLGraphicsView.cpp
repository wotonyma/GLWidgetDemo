#include "GLGraphicsView.h"
#include <qopenglwidget.h>

GLGraphicsView::GLGraphicsView(QWidget *parent)
	: QGraphicsView(parent)
{
	this->setViewport(new QOpenGLWidget());
	_scene = new QGraphicsScene(this);
	this->setScene(_scene);
}

GLGraphicsView::~GLGraphicsView()
{
}
