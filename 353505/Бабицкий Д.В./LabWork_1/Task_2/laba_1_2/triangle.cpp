#include "triangle.h"
void triangle::move_right(){

    dx+=0.1;
    rec=QRect(0,0,200,200);
    update();
}
void triangle::move_left(){

    dx-=0.1;
    rec=QRect(0,0,200,200);
    update();
}
void triangle::move_up(){

    dy+=0.1;
    rec=QRect(0,0,200,200);
    update();
}
void triangle::move_down(){

    dy-=0.1;
    rec=QRect(0,0,200,200);
    update();
}
double triangle::areaFind() {

    return 100*sqrt(3)*100/4*xx*xx;
}


double triangle::perFind(){
    return 100*4*xx;
}

double triangle::centrFindX(){
    return (x+dx)*xx;
}
double triangle::centrFindY(){
    return (y-dy)*xx;
}
QRectF triangle::boundingRect() const {
    return QRectF(0,0,150*100,150*100);
}

void triangle::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget){
    QPolygonF polygon;
    Q_UNUSED(widget);
    Q_UNUSED(option);
    polygon << QPointF((x/2+dx)*xx,(y/2+dy)*xx) << QPointF((x*3/2+dx)*xx,(y/2+dy)*xx) << QPointF((x+dx)*xx,(y*3/2+dy)*xx);
    painter->setBrush(Qt::blue);
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
    else {
        fl=0;
    }
    painter->drawPolygon(polygon);
    update();
}
void triangle::destroy_triangle(){
    y=0;
    x=0;
    xx=0;
    dx=0;
    dy=0;
    m1=QPointF(0,0);
    fl=1;
    update();
}
void triangle::create_triangle(){
    x=100;
    y=100;
    xx=1;
    dx=0;
    dy=0;
    fl=0;
    m1=QPointF(0,0);
    m2=QPointF(0,0);
    update();
}
void triangle::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    m1=event->pos();
    m2=event->pos();
    this->setCursor(QCursor(Qt::ClosedHandCursor));


}
void triangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {

    if(fl){

        m1=event->pos();
        update();
    }
    else{
        this->setPos(mapToScene(event->pos()));
        fl=1;
    }

}
void triangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));

}
void triangle::mashUp(QGraphicsItem* items){
    xx+=0.001;
    items->setTransformOriginPoint(m1);
    update();
}
void triangle::mashDown(QGraphicsItem* items){
    xx-=0.001;
    items->setTransformOriginPoint(m1);
    update();
}
