#pragma once

#include <QGraphicsItem>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QPixmap>

class ImageGraphicsItem : public QGraphicsItem, public QOpenGLExtraFunctions
{
	Q_OBJECT

public:
	ImageGraphicsItem(QGraphicsItem* parent = nullptr);
	~ImageGraphicsItem();
	void setPixmap(const QPixmap& img);
	QPixmap pixmap() const;


protected:
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	//inherits QWidgetItem need override, QGraphicsItem needn't
	//void resizeEvent(QGraphicsSceneResizeEvent* event) override; 

private:
	void makeObject();
	void paintGL();
	void cleanup();

	void initShader();
	void initTexture();

private:
	QPixmap _pixmap;

	/*opengl*/
	QOpenGLShaderProgram* _shader_prog;
	QOpenGLVertexArrayObject _vao;
	QOpenGLBuffer _vbo;
	QOpenGLBuffer _ebo;
	QOpenGLTexture* _texture;
};
