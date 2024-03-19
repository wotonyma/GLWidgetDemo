#include "OpenGLPixmapItem.h"
#include <QPainter>
#include <qdebug.h>

OpenGLPixmapItem::OpenGLPixmapItem(const QPixmap& pixmap) 
	: QGraphicsPixmapItem(pixmap)
	, m_texture(nullptr) 
{
}

OpenGLPixmapItem::~OpenGLPixmapItem()
{
}

void OpenGLPixmapItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    /*subclass of QGraphicsPixmapItem can't work well*/

    Q_UNUSED(option)
    Q_UNUSED(widget)

    if (!m_texture)
    {
        // Create OpenGL texture from pixmap
        initializeOpenGLFunctions();
        m_texture = new QOpenGLTexture(pixmap().toImage());
        m_texture->setMinificationFilter(QOpenGLTexture::Linear);
        m_texture->setMagnificationFilter(QOpenGLTexture::Linear);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glColor3f(0.0f, 0.5f, 0.7f);
    

    // Bind texture and render with OpenGL
    if (!m_texture->isStorageAllocated())
        qDebug() << "not alloccte";

    //painter->beginNativePainting();
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

    //painter->endNativePainting();
    qDebug() << "paint()";
    return;
}