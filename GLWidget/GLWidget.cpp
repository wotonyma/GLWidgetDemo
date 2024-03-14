#include "glwidget.h"

GLWidget::GLWidget(QWidget* parent)
	: QOpenGLWidget(parent)
	, _texture(QOpenGLTexture::Target2D)
	, _vbo(QOpenGLBuffer::VertexBuffer)
	, _ebo(QOpenGLBuffer::IndexBuffer)
{
}

GLWidget::~GLWidget()
{
	makeCurrent();
	_vbo.destroy();
	_ebo.destroy();
	_texture.destroy();
	doneCurrent();
}

void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(0.0f, 0.5f, 0.7f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);    //设置纹理2D功能可用

	QVector<Vertex> vertices = {
		{{1.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
		{{1.0f, -1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}, {1.0f, 0.0f}},
		{{-1.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},
		{{-1.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}}
	};
	_vertices = vertices;

	//ebo数据
	GLuint element[] = {0, 1, 2, 3};

	_vao.create();
	_vao.bind();

	_vbo.create();
	_vbo.bind();
	_vbo.allocate(vertices.data(), sizeof(Vertex) * vertices.size());

	_ebo.create();
	_ebo.bind();
	_ebo.allocate(element, sizeof(element));
	
	_shader_program.create();
	_shader_program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/opengl/gl.vert");
	_shader_program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/opengl/gl.frag");
	_shader_program.link();

	//_shader_program.setAttributeBuffer(0, GL_FLOAT, 0 * sizeof(GL_FLOAT), 3, 9 * sizeof(GL_FLOAT));
	_shader_program.setAttributeBuffer(0, GL_FLOAT, offsetof(Vertex, pos), 3, sizeof(Vertex));
	_shader_program.enableAttributeArray(0);
	_shader_program.setAttributeBuffer(1, GL_FLOAT, offsetof(Vertex, color), 4, sizeof(Vertex));
	_shader_program.enableAttributeArray(1);
	_shader_program.setAttributeBuffer(2, GL_FLOAT, offsetof(Vertex, texture), 2, sizeof(Vertex));
	_shader_program.enableAttributeArray(2);

	_vao.release();
	_vbo.release();
	_ebo.release(); //确认vao释放在ebo释放之前
}

void GLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
}

void GLWidget::paintGL()
{
	if (!_texture.isStorageAllocated())
		return;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除屏幕缓存和深度缓冲
	_shader_program.bind();
	_texture.bind(0);
	_shader_program.setUniformValue("texture", 0);
	QOpenGLVertexArrayObject::Binder bind(&_vao);

	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);//绘制纹理
	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, nullptr); //使用ebo绘制

	_texture.release();
	_shader_program.release();
}

void GLWidget::updateImage(const QImage& img)
{
	makeCurrent();
	////test_start
	updateVertexData(img.width(), img.height());
	_vbo.bind();
	_vbo.write(0, _vertices.data(), 4 * sizeof(Vertex));
	_vbo.release();
	////--end
	_texture.destroy();
	_texture.create();
	_texture.setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);	//纹理缩小格式
	_texture.setMagnificationFilter(QOpenGLTexture::Linear);			//纹理放大格式
	_texture.setWrapMode(QOpenGLTexture::Repeat);						//纹理环绕模式
	_texture.setLevelofDetailBias(-1);									//值越小纹理越清晰
	_texture.setData(img);
	paintGL();
}

void GLWidget::updateVertexData(float w, float h)
{
	//w h 为纹理图片的width height
	float ratio_xy = w * this->size().height() / (h * this->size().width());
	float rx = ratio_xy;
	float ry = 1.0f;
	if (rx > ry) {
		ry = ry / rx;
		rx = 1.0f;
	}
	_vertices[0].pos = { 1.0f * rx, 1.0f * ry, 0.0f };
	_vertices[1].pos = { 1.0f * rx, -1.0f * ry, 0.0f };
	_vertices[2].pos = { -1.0f * rx, 1.0f * ry, 0.0f };
	_vertices[3].pos = { -1.0f * rx, -1.0f * ry, 0.0f };
}