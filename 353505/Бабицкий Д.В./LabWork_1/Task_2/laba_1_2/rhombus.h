#ifndef RHOMBUS_H
#define RHOMBUS_H
#include"figure.h"
class Rhombus: public Figure
{
private:
    double y=0;
    double x=0;
    double w=0;
    double n=0;
    double dx=0;
    double dy=0;
    int ind=0;
    bool fl=1;
    int l=0;
    QRectF rec;
    qreal xx=1;
    QPointF m1=QPointF(0,0);
    QPointF m2=QPointF(0,0);
public:
    QRectF boundingRect() const override;
    double areaFind();
    double perFind();
    double centrFindX();
    double centrFindY();
       void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    void create_rhombus();
    void destroy_rhombus();
    void mousePressEvent(QGraphicsSceneMouseEvent *event)  override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void move_right();
    void move_left();
    void move_up();
    void move_down();
    void mashUp(QGraphicsItem *item);
    void mashDown(QGraphicsItem *item);
};

#endif // RHOMBUS_H
