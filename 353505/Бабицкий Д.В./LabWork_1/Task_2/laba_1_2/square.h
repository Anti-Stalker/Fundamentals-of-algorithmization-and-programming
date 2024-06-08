#ifndef SQUARE_H
#define SQUARE_H
#include"figure.h"
class Square : public Figure
{
private:
    double w=0;
    double x=0;
    double y=0;
    double dx=0;
    double dy=0;
    QPointF current;
    QRectF rec;
    bool susp=0;
    bool fl=1;
    QPointF m1=QPointF(0,0);
    QPointF m2=QPointF(0,0);
    qreal xx=1;
    qreal xy=0;
public:
    double areaFind();
    double perFind();
    double centrFindX();
    double centrFindY();
     QRectF boundingRect() const override;
     void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    void create_square();
    void destroy_square();
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

#endif // SQUARE_H
