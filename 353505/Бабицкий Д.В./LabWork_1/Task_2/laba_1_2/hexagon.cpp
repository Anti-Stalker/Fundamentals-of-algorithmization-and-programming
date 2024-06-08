#include "hexagon.h"
void hexagon::move_right(){

    dx+=0.1;
    rec=QRect(0,0,200,200);
    update();
}
void hexagon::move_left(){

    dx-=0.1;

    update();
}
void hexagon::move_up(){

    dy+=0.1;

    update();
}
void hexagon::move_down(){

    dy-=0.1;

    update();
}
double hexagon::areaFind() {

    return 3*sqrt(3)/2*100*100/4*xx*xx;
}


double hexagon::perFind(){
    return 6*100/4*xx;
}

double hexagon::centrFindX(){
    return (x+dx)*xx;
}
double hexagon::centrFindY(){
    return (y+dy)*xx;
}
QRectF hexagon::boundingRect() const {
    return QRectF(0,0,200*100,200*100);
}
void hexagon::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) {

        QPolygonF polygon;
    polygon << QPointF(((x/2)+dx)*xx,dy*xx) << QPointF((dx+x)*xx,dy*xx) << QPointF((1.25*(x)+dx)*xx,((y)/2+dy)*xx) << QPointF((x+dx)*xx,(y+dy)*xx) << QPointF(((x)/2+dx)*xx,(y+dy)*xx) << QPointF((0.25*(x)+dx)*xx,((y)/2+dy)*xx);
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
        else if((polygon[4].x()-10<=m2.x())&&(polygon[4].y()-10<=m2.y())&&(polygon[4].x()+10>=m2.x())&&(polygon[4].y()+10>=m2.y())){
            fl=1;
            polygon[4]=m1;
        }
        else if((polygon[5].x()-10<=m2.x())&&(polygon[5].y()-10<=m2.y())&&(polygon[5].x()+10>=m2.x())&&(polygon[5].y()+10>=m2.y())){
            fl=1;
            polygon[5]=m1;
        }
        else {
            fl=0;
        }
        painter->setBrush(Qt::blue);
        painter->drawPolygon(polygon);
          update();

}
void hexagon::create_hexagon(){
    y=100;
    x=100;
    n=1;
    xx=1;
    fl=1;
    update();
      update();
}
void hexagon::destroy_hexagon(){
    x=0;
    y=0;
    n=0;
    dx=0;
    dy=0;
    xx=0;
    fl=0;
    m1=QPointF(0,0);
    m2=QPointF(0,0);
     update();
}
void hexagon::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    m2=event->pos();
    m1=event->pos();
    this->setCursor(QCursor(Qt::ClosedHandCursor));


}
void hexagon::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if(fl){

        m1=event->pos();
        update();
    }
    else{
        this->setPos(mapToScene(event->pos()));
        fl=1;
    }

}
void hexagon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));

}
void hexagon::mashUp(QGraphicsItem* items){
    xx+=0.001;
    items->setTransformOriginPoint(m1);
    update();
}
void hexagon::mashDown(QGraphicsItem* items){
    xx-=0.001;
    items->setTransformOriginPoint(m1);
    update();
}
