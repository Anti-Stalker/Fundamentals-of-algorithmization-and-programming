#include "rhombus.h"
void Rhombus::move_right(){

    dx+=0.1;
    rec=QRect((x+dx)*xx,(y+dy)*xx,200*xx*xx,200*xx*xx);
    update();
}
void Rhombus::move_left(){

    dx-=0.1;
    rec=QRect(0,0,200,200);
    update();
}
void Rhombus::move_up(){

    dy-=0.1;
    rec=QRect(0,0,200,200);
    update();
}
void Rhombus::move_down(){

    dy+=0.1;
    rec=QRect(0,0,200,200);
    update();
}

QRectF Rhombus::boundingRect() const {
    return QRectF(-20,-20,100*100,100*100);
}
double Rhombus::areaFind() {

    return sqrt(3)*50*50*xx;
}


double Rhombus::perFind(){
    return 50*sqrt(2)*4*xx;
}

double Rhombus::centrFindX(){
    return (x+dx)*xx;
}
double Rhombus::centrFindY(){
    return (y-dy)*xx;
}
void Rhombus::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) {
    if(n){
        QPolygonF polygon;
      polygon << QPointF((x-50+dx)*xx,(y+dy)*xx) << QPointF((x+dx)*xx,(y+50+dy)*xx) << QPointF((x+50+dx)*xx,(y+dy)*xx) << QPointF((x+dx)*xx,(y-50+dy)*xx);
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

     painter->setBrush(Qt::blue);
    painter->drawPolygon(polygon);
     update();
    }
}


void Rhombus::create_rhombus(){

    x=100;
    y=100;
    w=100;
    n=1;
    xx=1;
    fl=1;
    m1=QPointF(0,0);
    update();
}
void Rhombus::destroy_rhombus(){
    x=0;
    y=0;
    n=0;
    xx=0;
    fl=0;
    dx=0;
    dy=0;
    m1=QPointF(0,0);
    m2=QPointF(0,0);
    update();
}
void Rhombus::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    m2=event->pos();
    m1=event->pos();
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    update();

}
void Rhombus::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if(fl){

        m1=event->pos();
    update();
    }
    else{
    this->setPos(mapToScene(event->pos()));
        fl=1;
    }

}
void Rhombus::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));
    update();

}
void Rhombus::mashDown(QGraphicsItem* items){
    xx-=0.001;
    items->setTransformOriginPoint(m1);
    update();
}
void Rhombus::mashUp(QGraphicsItem* items){
    xx+=0.001;
    items->setTransformOriginPoint(m1);
    update();
}





