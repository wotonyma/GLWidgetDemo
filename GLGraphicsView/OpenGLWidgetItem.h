#pragma once

#include <QGraphicsWidget>
#include <QOpenGLExtraFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>
#include <QMatrix4x4>

class OpenGLWidgetItem : public QGraphicsWidget, protected QOpenGLExtraFunctions
{

public:
	OpenGLWidgetItem(QGraphicsItem *parent = nullptr);
	~OpenGLWidgetItem();

protected:
	void resizeEvent(QGraphicsSceneResizeEvent* event) override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
	QOpenGLTexture* m_texture;
	QImage* m_img;
	bool m_init = false;
};
