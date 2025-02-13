#include "laser_service.h"

#include "laser.h"
#include "laser_ctrl.h"

#define LASER LaserControl::instance().laser()

int LaserService::laser_Open()
{
	return LASER.laser_Open();
}

int LaserService::laser_Close()
{
	return LASER.laser_Close();
}

int LaserService::laser_MarkPoint(QPointF point, double delay, int pen)
{
	return LASER.laser_MarkPoint(point, delay, pen);
}

int LaserService::laser_MarkLine(QPointF point1, QPointF point2, int pen)
{
	return LASER.laser_MarkLine(point1, point2, pen);
}

int LaserService::laser_GotoPos(QPointF pos)
{
	return LASER.laser_GotoPos(pos);
}

QPointF LaserService::laser_GetCurPos()
{
	QPointF pos;
	int err = LASER.laser_GetCurPos(pos);
	return pos;
}

int LaserService::laser_LoadMarkFile(QString file)
{
	return LASER.laser_LoadMarkFile(file);
}

int LaserService::laser_MarkFile()
{
	return LASER.laser_MarkFile();
}

int LaserService::laser_MarkEntity(QString ent)
{
	return LASER.laser_MarkEntity(ent);
}

int LaserService::laser_MarkEntity(QString ent, int pen)
{
	return LASER.laser_MarkEntity(ent, pen);
}

int LaserService::laser_MirrorEnt(QString ent, QPointF center, bool bx, bool by)
{
	return LASER.laser_MirrorEnt(ent, center, bx, by);
}

int LaserService::laser_MoveEnt(QString ent, QPointF offset)
{
	return LASER.laser_MoveEnt(ent, offset);
}

int LaserService::laser_RotateEnt(QString ent, QPointF center, double angle)
{
	return LASER.laser_RotateEnt(ent, center, angle);
}

int LaserService::laser_ScaleEnt(QString ent, QPoint center, double scaleX, double scaleY)
{
	return LASER.laser_ScaleEnt(ent, center, scaleX, scaleY);
}

QRectF LaserService::laser_GetEntSize(QString ent)
{
	QRectF rect;
	auto err = LASER.laser_GetEntSize(ent, rect);
	return rect;
}

int LaserService::laser_AddPolygon(QString ent, QVector<QPointF> poly, bool close)
{
	return LASER.laser_AddPolygon(ent, poly, close);
}

int LaserService::laser_EnableHatchEnt(QString ent, bool enableHatch, double hatchLineDist, int penNo)
{
	return LASER.laser_EnableHatchEnt(ent, enableHatch, hatchLineDist, penNo);
}

BmpEntInfo LaserService::laser_GetBitmapEnt(QString ent)
{
	BmpEntInfo info;
	LASER.laser_GetBitmapEnt(ent, info);
	return info;
}

int LaserService::laser_SetBitmapEnt(QString ent, const BmpEntInfo& bmpInfo)
{
	return LASER.laser_SetBitmapEnt(ent, bmpInfo);
}

int LaserService::laser_ChangeEntText(QString ent, QString text)
{
	return LASER.laser_ChangeEntText(ent, text);
}
