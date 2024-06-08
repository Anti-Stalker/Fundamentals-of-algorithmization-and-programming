#include "circle.h"
void Circle::move_right(){
    x+=0.1;
    rec=QRect(x,y,h,h);
    update();
}
void Circle::move_left(){
    x-=0.1;
    rec=QRect(x,y,h,h);
    update();
}
void Circle::move_up(){
    y-=0.1;
    rec=QRect(x,y,h,h);
    update();
}
void Circle::move_down(){
    y+=0.1;
    rec=QRect(x,y,h,h);
    update();
}
QRectF Circle::boundingRect() const {
    return rec;
}
double Circle::areaFind() {
    
    return 3.141592*h/4*(xx)*xx;
}


double Circle::perFind(){
    return 3.141592*h*(xx);
}

double Circle::centrFindX(){
    return x*xx;
}
double Circle::centrFindY(){
    return y*xx;
}
void Circle::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget){
    rec=QRect(x,y,h,h);
    painter->drawEllipse(x,y,h,h);
    update();
}

void Circle::create(){
    x=50;
    y=50;
    h=50;
    xx=1;
    rec=QRect(x,y,h,h);
    update();
}
void Circle::destroy(){
    x=0;
    y=0;
    h=0;
    xx=0;
    rec=QRect(x,y,h,h);
    update();
}
void Circle::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    this->setCursor(QCursor(Qt::ClosedHandCursor));
    update();

}
void Circle::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    m1=event->pos();
    this->setPos(mapToScene(event->pos()));
     update();
}
void Circle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));
     update();
}
void Circle::mashUp(QGraphicsItem* items){
    xx+=0.001;
    items->setTransformOriginPoint(m1);
    items->setScale(xx);
}
void Circle::mashDown(QGraphicsItem* items){
    xx-=0.001;
    items->setTransformOriginPoint(m1);
    items->setScale(xx);
}
