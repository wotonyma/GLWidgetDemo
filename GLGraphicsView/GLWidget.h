#pragma once

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QImage>
#include <qopenglvertexarrayobject.h>
#include <qopenglbuffer.h>


class GLWidget : public QOpenGLWidget , protected QOpenGLExtraFunctions
{
	Q_OBJECT

public:
	GLWidget(QWidget *parent = nullptr);
	~GLWidget();
	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;

	void initTextures();
	void initShaders();

	void textureBindImage(QOpenGLTexture& texture, QImage& img);

private:
	QOpenGLShaderProgram _shader_program;	//着色器
	QOpenGLTexture *_texture;				//纹理
	QImage _img;
	QOpenGLVertexArrayObject VAO;
	QOpenGLBuffer VBO;
	QOpenGLBuffer EBO;
};

