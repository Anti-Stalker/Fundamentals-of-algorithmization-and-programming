#ifndef CIRCLE_H
#define CIRCLE_H
#include<QPainter>
#include<QWidget>
#include"figure.h"
class Circle : public Figure
{
protected:
    double x=0;
    double y=0;
    int h=0;
    QRect rec;
    qreal xx=1;
    QPointF m1=QPointF(0,0);
public:
    QRectF boundingRect() const override;
    double areaFind();
    double perFind();
    double centrFindX();
    double centrFindY();
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    void create();
    void destroy();
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

#endif // CIRCLE_H
