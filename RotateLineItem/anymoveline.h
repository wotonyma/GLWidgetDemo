#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>
#include <QDebug>
#include <QGraphicsScene>

class CustomLineItem : public QGraphicsItem
{
public:
    CustomLineItem(QGraphicsItem* parent = nullptr);
    ~CustomLineItem();

    void installEventFilter();

    void addItem2Scene(QGraphicsScene* scene)
    {
        //将全部item添加入场景
        scene->addItem(sp);
        scene->addItem(ep);
        scene->addItem(line);
    }

protected:
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;
    bool sceneEventFilter(QGraphicsItem* watched, QEvent* event) override;
    

private:
    QGraphicsEllipseItem* sp;
    QGraphicsEllipseItem* ep;
    QGraphicsLineItem* line;

    QPointF p1 = QPoint(50, 50);  //scene pos
    QPointF p2 = QPoint(100, 100);
    double r = 5.0;
};
