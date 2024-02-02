#include "GLWidget.h"
#include <qdebug.h>


GLWidget::GLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	/*QSurfaceFormat format;
	format.setVersion(4, 5);
	this->setFormat(format);*/
}

GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
	_img = QImage("d:/test/img2.jpg");

	initializeOpenGLFunctions();
	glClearColor(0.0f, 0.5f, 0.9f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);    //设置纹理2D功能可用
	initTextures();				//初始化纹理设置
	initShaders();				//设置shaders

	//_shader_program.bind();
	//_shader_program.setUniformValue("texture", 0);
	//_texture->bind();
}

void GLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除屏幕缓存和深度缓冲
	_shader_program.bind();
	_shader_program.setUniformValue("texture", 0);
	_texture->bind();

	_texture->setData(_img); //设置纹理图像
	//设置纹理细节
	_texture->setLevelofDetailBias(-1);//值越小，图像越清晰

	GLfloat coords[] = {
		0.5f,  0.5f, 0.0f,   // 右上角
		0.5f, -0.5f, 0.0f,   // 右下角
		-0.5f,  0.5f, 0.0f,   // 左上角
		-0.5f, -0.5f, 0.0f,  // 左下角
	};

	GLfloat colors[] = {
		1.0, 0.0, 0.0, 1.0,
		0.0, 1.0, 0.0, 1.0,
		0.0, 0.0, 1.0, 1.0,
		0.0, 0.0, 0.0, 0.0
	};

	GLfloat textcoords[] = {
		0, 1,
		1, 1,
		0, 0,
		1, 0
	};

	_shader_program.setAttributeArray("aPos", coords, 3);
	//_shader_program.setAttributeArray("aColor", colors, 4);
	_shader_program.setAttributeArray("aTextc", textcoords, 2);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);//绘制纹理

	_texture->release(); //释放绑定的纹理
	_texture->destroy(); //消耗底层的纹理对象
	_texture->create();
}

void GLWidget::initTextures()
{
	// 加载 .jpg 图片
	_texture = new QOpenGLTexture(QOpenGLTexture::Target2D);
	_texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	_texture->setMagnificationFilter(QOpenGLTexture::Linear);

	//纹理重复
	_texture->setWrapMode(QOpenGLTexture::Repeat);
	//设置纹理大小
	_texture->setSize(this->width(), this->height());
	//分配储存空间
	_texture->allocateStorage();
}

void GLWidget::initShaders()
{
	_shader_program.create();
	_shader_program.addShaderFromSourceFile(QOpenGLShader::Vertex, "./gl.vert");
	_shader_program.addShaderFromSourceFile(QOpenGLShader::Fragment, "./gl.frag");
	_shader_program.link();
	_shader_program.enableAttributeArray("aPos"); //shader file顶点坐标
	//_shader_program.enableAttributeArray("aColor"); //shader file顶点着色器
	_shader_program.enableAttributeArray("aTextc"); //shader file纹理
}
