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

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClearColor(0.0f, 0.5f, 0.7f, 1.0f);
    glColor3f(0.0f, 0.5f, 0.7f);
    

    // Bind texture and render with OpenGL
    if (!m_texture->isStorageAllocated())
        qDebug() << "not alloccte";

    glBegin(GL_QUADS);
    m_texture->bind(0);//绑定纹理
    glTexCoord2f(0, 0);//坐标1
    glVertex2d(-1.0, 1.0f);
    glTexCoord2f(1, 0);//坐标2
    glVertex2d(1.0f, 1.0f);
    glTexCoord2f(1, 1);//坐标3
    glVertex2d(1.0f, -1.0f);
    glTexCoord2f(0, 1);//坐标4
    glVertex2d(-1.0f, -1.0f);
    glEnd();

    //painter->endNativePainting();
    qDebug() << "paint()";
    return;
}