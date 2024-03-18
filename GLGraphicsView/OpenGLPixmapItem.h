#pragma once

#include <QGraphicsPixmapItem>
#include <QOpenGLTexture>
#include <QOpenGLExtraFunctions>
#include <QOpenGLFunctions>

class OpenGLPixmapItem : public QGraphicsPixmapItem, protected QOpenGLExtraFunctions
//class OpenGLPixmapItem : public QGraphicsPixmapItem, protected QOpenGLFunctions
{
public:
    OpenGLPixmapItem(const QPixmap& pixmap);
	~OpenGLPixmapItem();

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

private:
    QOpenGLTexture* m_texture;
};