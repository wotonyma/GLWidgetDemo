#pragma once

#include <string>
#include "qpoint.h"
#include "qrect.h"
#include "qvector.h"
#include "jcz2/bmp_ent.h"

class Laser
{
public:

	using Point = QPointF;
	using String = QString;
	using Rect = QRectF;
	using PointVec = QVector<QPointF>;
	using BitmapInfo = BmpEntInfo;

	Laser() = default;
	virtual ~Laser() = default;

	virtual int laser_Open() = 0;
	virtual int laser_Close() = 0;
	//直接打标
	virtual int laser_MarkPoint(Point point, double delay, int pen) = 0;
	virtual int laser_MarkLine(Point point1, Point point2, int pen) = 0;
	//振镜控制
	virtual int laser_GotoPos(Point pos) = 0;
	virtual int laser_GetCurPos(Point& pos) = 0;
	//对象控制
	virtual int laser_LoadMarkFile(String file) = 0;
	virtual int laser_MarkFile() = 0;
	virtual int laser_MarkEntity(String ent) = 0;
	virtual int laser_MarkEntity(String ent, int pen) = 0;
	//virtual int laser_SetRotateMoveParam(QPointF moveOffset, QPointF rotateCenter, double rotateAngle) = 0;

	virtual int laser_MirrorEnt(String ent, Point center, bool bx, bool by) = 0;
	virtual int laser_MoveEnt(String ent, Point offset) = 0;
	virtual int laser_RotateEnt(String ent, Point center, double angle) = 0;
	virtual int laser_ScaleEnt(String ent, Point center, double scaleX, double scaleY) = 0;
	virtual int laser_GetEntSize(String ent, Rect& rect) = 0;

	virtual int laser_AddPolygon(String ent, PointVec poly, bool close) = 0;
	//virtual int laser_HatchEnt(String ent) = 0;
	//virtual int laser_UnHatchEnt(String ent) = 0;
	virtual int laser_EnableHatchEnt(String ent, bool enableHatch, double hatchLineDist, int penNo) = 0;

	virtual int laser_GetBitmapEnt(String ent, BitmapInfo& bmpInfo) = 0;
	virtual int laser_SetBitmapEnt(String ent, const BitmapInfo& bmpInfo) = 0;

	virtual int laser_ChangeEntText(String ent, String text) = 0;

	virtual int laser_SaveToFile(String filename) = 0;

private:

};

