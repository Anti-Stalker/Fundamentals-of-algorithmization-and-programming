#include "star_6.h"
void star_6::move_right(){

    dx+=0.1;

    update();
}
void star_6::move_left(){

    dx-=0.1;

    update();
}
void star_6::move_up(){

    dy-=0.1;

    update();
}
void star_6::move_down(){
    dy+=0.1;
    update();
}
double star_6::areaFind() {

    return 6*sqrt(qPow(((100+r*cos(-M_PI/2)-100+r*cos(-M_PI/2+M_PI/6)/2)*sqrt(2)),4)*3/16)*xx;
}


double star_6::perFind(){
    return 12*(100+r*cos(-M_PI/2)-100+r*cos(-M_PI/2+M_PI/6)/2)*sqrt(2)*xx;
}

double star_6::centrFindX(){
    return (x+dx)*xx;
}
double star_6::centrFindY(){
    return (y-dy)*xx;
}
QRectF star_6::boundingRect() const {
    return QRectF(40,40,200*100,200*100);
}
void star_6::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) {
    if(n){
        QPolygonF polygon;

        for(int i=0;i<6;++i){
            qreal angle=2*M_PI*i/6-M_PI/2;
            polygon << QPointF((x+r*cos(angle)+dx)*xx,(y+r*sin(angle)+dy)*xx);
            angle+=M_PI/6;
            polygon << QPointF((x+r*cos(angle)/2+dx)*xx,(y+r/2*sin(angle)+dy)*xx);
        }
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
            else if((polygon[6].x()-10<=m2.x())&&(polygon[6].y()-10<=m2.y())&&(polygon[6].x()+10>=m2.x())&&(polygon[6].y()+10>=m2.y())){
                fl=1;
                polygon[6]=m1;
            }
            else if((polygon[7].x()-10<=m2.x())&&(polygon[7].y()-10<=m2.y())&&(polygon[7].x()+10>=m2.x())&&(polygon[7].y()+10>=m2.y())){
                fl=1;
                polygon[7]=m1;
            }
            else if((polygon[8].x()-10<=m2.x())&&(polygon[8].y()-10<=m2.y())&&(polygon[8].x()+10>=m2.x())&&(polygon[8].y()+10>=m2.y())){
                fl=1;
                polygon[8]=m1;
            }
            else if((polygon[9].x()-10<=m2.x())&&(polygon[9].y()-10<=m2.y())&&(polygon[9].x()+10>=m2.x())&&(polygon[9].y()+10>=m2.y())){
                fl=1;
                polygon[9]=m1;
            }
            else if((polygon[10].x()-10<=m2.x())&&(polygon[10].y()-10<=m2.y())&&(polygon[10].x()+10>=m2.x())&&(polygon[10].y()+10>=m2.y())){
                fl=1;
                polygon[10]=m1;
            }
            else if((polygon[11].x()-10<=m2.x())&&(polygon[11].y()-10<=m2.y())&&(polygon[11].x()+10>=m2.x())&&(polygon[11].y()+10>=m2.y())){
                fl=1;
                polygon[11]=m1;
            }
            else {
                fl=0;
            }
            painter->drawPolygon(polygon);
                update();
        }
}
void star_6::create_st6(){
    x=100;
    y=100;
    r=50;
    n=1;
    xx=1;
    fl=1;
    m1=QPointF(0,0);
    m2=QPointF(0,0);
    update();
}
void star_6::destroy_st6(){
    r=0;
    x=0;
    y=0;
    n=0;
    xx=0;
    fl=0;
    m1=QPointF(0,0);
    m2=QPointF(0,0);
    update();
}

void star_6::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    m1=event->pos();
    m2=event->pos();
    this->setCursor(QCursor(Qt::ClosedHandCursor));


}
void star_6::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {

    if(fl){

        m1=event->pos();
        update();
    }
    else{
        this->setPos(mapToScene(event->pos()));
        fl=1;
    }

}
void star_6::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));

}
void star_6::mashUp(QGraphicsItem* items){
    xx+=0.001;
    items->setTransformOriginPoint(m1);
    update();
}
void star_6::mashDown(QGraphicsItem* items){
    xx-=0.001;
    items->setTransformOriginPoint(m1);
    update();
}
