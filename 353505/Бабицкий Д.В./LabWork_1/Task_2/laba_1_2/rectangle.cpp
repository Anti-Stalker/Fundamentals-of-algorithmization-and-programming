#include "rectangle.h"
void Rectangle::move_right(){
    dx+=0.1;
    rec=QRect(x,y,w,h);
    update();
}
void Rectangle::move_left(){
    dx-=0.1;
    rec=QRect(x,y,w,h);
    update();
}
void Rectangle::move_up(){
    dy-=0.1;
    rec=QRect(x,y,w,h);
    update();
}
void Rectangle::move_down(){
    dy+=0.1;
    rec=QRect(x,y,w,h);
    update();
}
QRectF Rectangle::boundingRect() const {
    return QRectF(20,20,200*110,200*110);
}
double Rectangle::areaFind() {

    return w*h*xx;
}


double Rectangle::perFind(){
    return 2*(w+h)*xx;
}

double Rectangle::centrFindX(){
    return (x+dx)*xx;
}
double Rectangle::centrFindY(){
    return (y+dy)*xx;
}
void Rectangle::destroy_rectangle(){
    y=0;
    x=0;
    w=0;
    h=0;
    xx=0;
    fl=0;
    rec=QRectF(x,y,w,h);
    m1=QPointF(0,0);
    m2=QPointF(0,0);
    update();
}
void Rectangle::create_rectangle(){
    x=100;
    y=100;
    w=100;
    h=w/2;
    dx=0;
    dy=0;
    xx=1;
    fl=1;
    rec=QRectF(x,y,w,h);
    m1=QPointF(0,0);
    m2=QPointF(0,0);
    update();
}




void Rectangle::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget){
    Q_UNUSED(widget);
    Q_UNUSED(option);
    painter->setBrush(Qt::red);
    QPolygonF polygon;
    polygon << QPointF((x)*xx+dx,(y)*xx+dy) << QPointF(4*(x)*xx+dx,(y)*xx+dy) << QPointF(4*(x)*xx+dx,2*(y)*xx+dy) << QPointF((x)*xx+dx,(y)*xx*2+dy);
    painter->setBrush(Qt::red);
    if((polygon[0].x()-10<=m2.x())&&(polygon[0].y()-10<=m2.y())&&(polygon[0].x()+10>=m2.x())&&(polygon[0].y()+10>=m2.y())){
        fl=1;
        polygon[0]=m1;
    }
    else if((polygon[1].x()-10<=m2.x())&&(polygon[1].y()-10<=m2.y())&&(polygon[1].x()+10>=m2.x())&&(polygon[1].y()+10>=m2.y())){
        fl=1;
        polygon[1]=m1;
    }
    else if((polygon[2].x()-10<=m2.x())&&(polygon[2].y()-10<=m2.y())&&(polygon[2].x()+10>=m2.x())&&(polygon[2].y()+10>=m2.y())){
        fl=1;
        polygon[2]=m1;
    }
    else if((polygon[3].x()-10<=m2.x())&&(polygon[3].y()-10<=m2.y())&&(polygon[3].x()+10>=m2.x())&&(polygon[3].y()+10>=m2.y())){
        fl=1;
        polygon[3]=m1;
    }
    else {
        fl=0;
    }
    painter->drawPolygon(polygon);
      update();
}

void Rectangle::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    m1=event->pos();
    m2=event->pos();
    this->setCursor(QCursor(Qt::ClosedHandCursor));


}
void Rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if(fl){

        m1=event->pos();
        update();
    }
    else{
        this->setPos(mapToScene(event->pos()));
        fl=1;
    }

}
void Rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));

}
void Rectangle::mashUp(QGraphicsItem* items){
    xx+=0.001;
    items->setTransformOriginPoint(m1);
    items->setScale(xx);
}
void Rectangle::mashDown(QGraphicsItem* items){
    xx-=0.001;
    items->setTransformOriginPoint(m1);
    items->setScale(xx);
}


