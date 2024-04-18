#include "OpenGLWidgetItem.h"
#include "qpainter.h"

OpenGLWidgetItem::OpenGLWidgetItem(QGraphicsItem *parent)
	: QGraphicsWidget(parent)
{
    //QGraphicsItem::ItemIgnoresTransformations
    this->setFlag(QGraphicsItem::ItemIgnoresTransformations);
}

OpenGLWidgetItem::~OpenGLWidgetItem()
{
}

void OpenGLWidgetItem::resizeEvent(QGraphicsSceneResizeEvent* event)
{
    qDebug() << "resizeEvent";
}

void OpenGLWidgetItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    
    qDebug() << size();
    qDebug() << "paint device" << widget;

    

    if (!m_init)
    {
        m_init = true;
        // Create OpenGL texture from pixmap
        m_img = new QImage("d:/test/copy/inv_test.bmp");
        initializeOpenGLFunctions();
        m_texture = new QOpenGLTexture(*m_img);
        m_texture->setMinificationFilter(QOpenGLTexture::Linear);
        m_texture->setMagnificationFilter(QOpenGLTexture::Linear);
        qDebug() << *m_img;
    }

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0f, 0.5f, 0.7f);
    glViewport(100, 100, 1000, 1000);
    

    painter->beginNativePainting();
    glEnable(GL_TEXTURE_2D);	//允许使用纹理
    m_texture->bind();//绑定纹理
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);//左下坐标1
    glVertex2d(-1.0, -1.0f);
    glTexCoord2f(1, 0);//右下坐标2
    glVertex2d(1.0f, -1.0f);
    glTexCoord2f(1, 1);//右上坐标3
    glVertex2d(1.0f, 1.0f);
    glTexCoord2f(0, 1);//左上坐标4
    glVertex2d(-1.0f, 1.0f);
    glEnd();
    painter->endNativePainting();
    qDebug() << size();

    QPen pen;
    pen.setWidth(5);
    pen.setColor(QColor(255, 0, 0));
    painter->setPen(pen);
    painter->drawRect(boundingRect());
}

