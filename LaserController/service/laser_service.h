#pragma once

#include "rep_laser_service_source.h"

class LaserService : public LaserServiceSource
{
    Q_OBJECT

public:
    explicit LaserService(QObject* parent = nullptr) : LaserServiceSource(parent)
    {
    }
    
public:
    ~LaserService() override = default;

    int laser_Open() override;
    int laser_Close() override;
    int laser_MarkPoint(QPointF point, double delay, int pen) override;
    int laser_MarkLine(QPointF point1, QPointF point2, int pen) override;
    int laser_GotoPos(QPointF pos) override;
    QPointF laser_GetCurPos() override;
    int laser_LoadMarkFile(QString file) override;
    int laser_MarkFile() override;
    int laser_MarkEntity(QString ent) override;
    int laser_MarkEntity(QString ent, int pen) override;
    int laser_MirrorEnt(QString ent, QPointF center, bool bx, bool by) override;
    int laser_MoveEnt(QString ent, QPointF offset) override;
    int laser_RotateEnt(QString ent, QPointF center, double angle) override;
    int laser_ScaleEnt(QString ent, QPoint center, double scaleX, double scaleY) override;
    QRectF laser_GetEntSize(QString ent) override;
    int laser_AddPolygon(QString ent, QVector<QPointF> poly, bool close) override;
    int laser_EnableHatchEnt(QString ent, bool enableHatch, double hatchLineDist, int penNo) override;
    BmpEntInfo laser_GetBitmapEnt(QString ent) override;
    int laser_SetBitmapEnt(QString ent, const BmpEntInfo& bmpInfo) override;
    int laser_ChangeEntText(QString ent, QString text) override;


private:
};