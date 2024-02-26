#include "anymoveline.h"

CustomLineItem::CustomLineItem(QGraphicsItem* parent) {

    QRectF rect1(p1.x() - r, p1.y() - r, 2 * r, 2 * r);
    QRectF rect2(p2.x() - r, p2.y() - r, 2 * r, 2 * r);
    sp = new QGraphicsEllipseItem(rect1);
    ep = new QGraphicsEllipseItem(rect2);
    line = new QGraphicsLineItem(p1.x(), p1.y(), p2.x(), p2.y());
    sp->setFlag(QGraphicsItem::ItemIsMovable, true);
    ep->setFlag(QGraphicsItem::ItemIsMovable, true);
    line->setFlag(QGraphicsItem::ItemIsMovable, true);

    qDebug() << "------------------";
    qDebug() << "sp:" << sp->pos();
    qDebug() << "ep:" << ep->pos();
    qDebug() << "line:" << line->pos();

}

CustomLineItem::~CustomLineItem()
{

}

void CustomLineItem::installEventFilter() {
    //给需要组合的items安装场景事件过滤器
    sp->installSceneEventFilter(this);
    ep->installSceneEventFilter(this);
    line->installSceneEventFilter(this);
}

void CustomLineItem::addItem2Scene(QGraphicsScene* scene)
{
    //将全部item添加入场景
    scene->addItem(sp);
    scene->addItem(ep);
    scene->addItem(line);
}


//继承需要重写的虚函数
QRectF CustomLineItem::boundingRect() const
{
    return QRectF(p1, p2).normalized();
}

void CustomLineItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    // painter->drawLine(p1, p2);
}

bool CustomLineItem::sceneEventFilter(QGraphicsItem* watched, QEvent* event)
{
    if (event->type() != QEvent::GraphicsSceneMouseMove)
        return false;
    qDebug() << "------------------";
    auto me = (QGraphicsSceneMouseEvent*)event;

    if (watched == sp || watched == ep)
    {
        auto p3 = sp->scenePos() + sp->rect().center();
        auto p4 = ep->scenePos() + ep->rect().center();

        //line->setPos(0, 0);/*与后两句效果相同*/
        auto offset = line->pos(); //line->setPos() 相当于平移。setline 不会管自己pos()相关，所以需要手动管理pos
        line->setLine(p3.x() - offset.x(), p3.y() - offset.y(), p4.x() - offset.x(), p4.y() - offset.y());

        qDebug() << "sp:" << sp->pos();
        qDebug() << "ep:" << ep->pos();
        qDebug() << "line:" << line->pos();
        qDebug() << "line scene center " << line->mapToScene(line->boundingRect().center());
        qDebug() << "......circle..........";
    }

    if (watched == line)
    {
        auto last_scene_pos = line->mapToScene(me->lastPos());
        auto cur_scene_pos = line->mapToScene(me->pos());
        auto dist_x = cur_scene_pos.x() - last_scene_pos.x();
        auto dist_y = cur_scene_pos.y() - last_scene_pos.y();
        qDebug() << "dist_:" << cur_scene_pos.x() - last_scene_pos.x() << "," << cur_scene_pos.y() - last_scene_pos.y();

        //个人理解：平移只是改变了pos(),相当于setpos()
        sp->moveBy(dist_x, dist_y);
        ep->moveBy(dist_x, dist_y);
        qDebug() << "sp:" << sp->pos();
        qDebug() << "ep:" << ep->pos();
        qDebug() << "line:" << line->pos();
        qDebug() << "line scene center " << line->mapToScene(line->boundingRect().center());
    }

    return QGraphicsItem::sceneEventFilter(watched, event);
}