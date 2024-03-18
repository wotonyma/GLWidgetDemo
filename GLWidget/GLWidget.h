#pragma once

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QImage>

class GLWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions
{
	Q_OBJECT

	struct Vertex 
	{
		QVector3D pos;
		QVector4D color;
		QVector2D texture;
	};

public:
	GLWidget(QWidget* parent = nullptr);
	~GLWidget();
	//用于等比例显示纹理图片
	void updateVertexData(float w, float h);

public slots:
	void updateImage(const QImage& img);

protected:
	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;

private:
	QOpenGLShaderProgram _shader_program;
	QOpenGLTexture _texture;
	QOpenGLVertexArrayObject _vao;
	QOpenGLBuffer _vbo;
	QOpenGLBuffer _ebo;

	QVector<Vertex> _vertices;
};