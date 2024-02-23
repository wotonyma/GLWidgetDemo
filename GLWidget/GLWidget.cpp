#include "GLWidget.h"
#include <qdebug.h>


GLWidget::GLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
	, VBO(QOpenGLBuffer::VertexBuffer)
	, EBO(QOpenGLBuffer::IndexBuffer)
{
	/*QSurfaceFormat format;
	format.setVersion(4, 5);
	this->setFormat(format);*/

	//_img = QImage("C:/zen/GL_Test/img1.png");
	auto img = QImage("D:/test/img2.jpg");
	//_img = img.scaled(img.width() / 4, img.height() / 4);
	_img = img;
}

GLWidget::~GLWidget()
{
	makeCurrent();

	EBO.destroy();
	VBO.destroy();
	VAO.destroy();
	_texture->destroy();

	delete _texture;

	doneCurrent();
}

void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(0.0f, 0.5f, 0.7f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);    //设置纹理2D功能可用

	GLfloat vertices[] = {
		// pos                   color					    textcoor
		0.8f,  0.8f, 0.0f,		1.0f, 0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
		0.8f, -0.8f, 0.0f,		0.0f, 1.0f, 0.0f, 1.0f,		1.0f, 0.0f,
		-0.8f,  0.8f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		0.0f, 1.0f,
		-0.8f, -0.8f, 0.0f,		0.0f, 0.0f, 0.0f, 0.0f,		0.0f, 0.0f
	};

	VBO.create();
	VBO.bind();
	VAO.create();
	VAO.bind();

	EBO.create();
	EBO.bind();
	uint element[] = {0, 1, 2, 3 };
	EBO.allocate(element, sizeof(element));

	initTextures();				//初始化纹理设置
	initShaders();				//设置shaders

	VBO.allocate(vertices, sizeof(vertices));
	_shader_program.setAttributeBuffer(0, GL_FLOAT, 0 * sizeof(GL_FLOAT), 3, 9 * sizeof(GL_FLOAT));
	_shader_program.enableAttributeArray(0);
	_shader_program.setAttributeBuffer(1, GL_FLOAT, 3 * sizeof(GL_FLOAT), 4, 9 * sizeof(GL_FLOAT));
	_shader_program.enableAttributeArray(1);
	_shader_program.setAttributeBuffer(2, GL_FLOAT, 7 * sizeof(GL_FLOAT), 2, 9 * sizeof(GL_FLOAT));
	_shader_program.enableAttributeArray(2);

	VAO.release();
	VBO.release();
	EBO.release(); //确认vao释放在ebo释放之前
}

void GLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, w , h);
}

void GLWidget::paintGL()
{
	if (!_texture->isStorageAllocated()) return;
	qDebug() << "paintGL()";
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除屏幕缓存和深度缓冲
	_shader_program.bind();

	//float xratio = 1.0 * this->size().height() / this->size().width();
	//float yratio = 1.0 * this->size().width() / this->size().height();
	//_shader_program.setUniformValue("factor", xratio, yratio, 0.0f);
	_texture->bind(0);
	_shader_program.setUniformValue("texture", 0);
	
	//_texture->setData(_img); //设置纹理图像(当图片很大时此函数很耗时,在paintGL重新设置会很卡)
	//设置纹理细节
	//_texture->setLevelofDetailBias(-1);//值越小，图像越清晰

	/*在初始化opengl时设置
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
	//_shader_program.setAttributeArray(0, GL_FLOAT, coords, 3);
	//_shader_program.setAttributeArray("aColor", colors, 4);
	_shader_program.setAttributeArray("aTextc", textcoords, 2);*/

	QOpenGLVertexArrayObject::Binder vao_bind(&VAO); //没有此句不能显示

	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);//绘制纹理
	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, nullptr); //使用ebo绘制

	//_texture->release(); //释放绑定的纹理
	//_texture->destroy(); //消耗底层的纹理对象
	//_texture->create();

	_texture->release();
	_shader_program.release();
}

void GLWidget::initTextures()
{
	// 加载 .jpg 图片
	_texture = new QOpenGLTexture(QOpenGLTexture::Target2D);
	_texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	//_texture->setMinificationFilter(QOpenGLTexture::Nearest);
	_texture->setMagnificationFilter(QOpenGLTexture::Linear);

	//纹理重复
	_texture->setWrapMode(QOpenGLTexture::Repeat);
	//设置纹理大小
	//_texture->setSize(this->width(), this->height());

	//分配储存空间
	//_texture->allocateStorage();//此代码加上会报一些异常
	/*原因:Qt允许我们使用一个便捷方法setData(QImage)，
	只需传入一个QImage就能快速创建一个纹理对象，
	无需再调用allocateStorage()分配存储
	（因为setData函数内部会根据QImage的格式自动分配)*/

	_texture->setData(_img); //设置纹理图像
	//设置纹理细节
	_texture->setLevelofDetailBias(-1);//值越小，图像越清晰
}

void GLWidget::initShaders()
{
	_shader_program.create();
	_shader_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/gl/gl.vert");
	_shader_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/gl/gl.frag");
	_shader_program.link();
	//_shader_program.enableAttributeArray("aPos"); //shader file顶点坐标(开启VAO顶点属性"aPos")
	//_shader_program.enableAttributeArray("aColor"); //shader file顶点着色器
	//_shader_program.enableAttributeArray("aTextc"); //shader file纹理
}

void GLWidget::textureBindImage(QOpenGLTexture& texture, QImage& img)
{
	makeCurrent(); //opengl上下文
	texture.destroy();
	texture.create();
	texture.setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);	//纹理缩小格式
	texture.setMagnificationFilter(QOpenGLTexture::Linear);				//纹理放大格式
	texture.setWrapMode(QOpenGLTexture::Repeat);						//纹理环绕模式
	texture.setLevelofDetailBias(-1);									//值越小纹理越清晰
	texture.setData(img);
	paintGL();
}