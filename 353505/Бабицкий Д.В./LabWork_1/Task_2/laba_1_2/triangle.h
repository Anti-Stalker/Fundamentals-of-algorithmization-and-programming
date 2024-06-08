#ifndef TRIANGLE_H
#define TRIANGLE_H
#include"figure.h"
class triangle : public Figure
{
    protected:
    double x=0;
    double y=0;
    double n=0;
    double dx=0;
    double dy=0;
    bool fl=1;
    QRectF rec;
    qreal xx=1;
    QPointF m1=QPointF(0,0);
    QPointF m2=QPointF(0,0);
public:
    double areaFind();
    double perFind();
    double centrFindX();
    double centrFindY();
     QRectF boundingRect() const override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    void create_triangle();
    void destroy_triangle();
    void mousePressEvent(QGraphicsSceneMouseEvent*event)  override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent*event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void move_right();
    void move_left();
    void move_up();
    void move_down();
    void mashUp(QGraphicsItem *item);
    void mashDown(QGraphicsItem *item);
};

#endif // TRIANGLE_H
