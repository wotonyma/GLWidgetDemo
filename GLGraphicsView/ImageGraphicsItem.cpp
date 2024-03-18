#include "ImageGraphicsItem.h"

ImageGraphicsItem::ImageGraphicsItem(QGraphicsItem* parent)
	: QGraphicsItem(parent)
{
}

ImageGraphicsItem::~ImageGraphicsItem()
{
}

void ImageGraphicsItem::setPixmap(const QPixmap& img)
{
	_pixmap = img;
}

QPixmap ImageGraphicsItem::pixmap() const
{
	return _pixmap;
}

QRectF ImageGraphicsItem::boundingRect() const
{
	//此坐标系应为图形项坐标系
	return QRectF(0, 0, _pixmap.width(), _pixmap.height());
}

void ImageGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(painter);
	Q_UNUSED(option);
	Q_UNUSED(widget);


}

void ImageGraphicsItem::initShader()
{

}

void ImageGraphicsItem::initTexture()
{

}