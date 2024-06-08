#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"figure.h"
class Rectangle : public Figure
{
    private:
    double w=0;
    double h=0;
    double x=0;
    double y=0;
    QPointF current;
    QRectF rec;
    qreal xx=1;
    bool fl=1;
    double dx=0;
    double dy=0;
    QPointF m1=QPointF(0,0);
    QPointF m2=QPointF(0,0);
public:
     QRectF boundingRect() const override;
    double areaFind();
    double perFind();
    double centrFindX();
    double centrFindY();
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    void create_rectangle();
    void destroy_rectangle();
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

#endif // RECTANGLE_H
