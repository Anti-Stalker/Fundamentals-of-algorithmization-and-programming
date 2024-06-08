#include "star_8.h"
void star_8::move_right(){

    dx+=0.1;

    update();
}
void star_8::move_left(){

    dx-=0.1;

    update();
}
void star_8::move_up(){

    dy-=0.1;

    update();
}
void star_8::move_down(){
    dy+=0.1;
    update();
}
double star_8::areaFind() {

    return 8*sqrt(qPow(((100+r*cos(-M_PI/2)-100+r*cos(-M_PI/2+M_PI/8)/2)*sqrt(2)),4)*3/16)*xx;
}


double star_8::perFind(){
    return 16*(100+r*cos(-M_PI/2)-100+r*cos(-M_PI/2+M_PI/8))*sqrt(2)*xx;
}

double star_8::centrFindX(){
    return (x+dx)*xx;
}
double star_8::centrFindY(){
    return (y-dy)*xx;
}
QRectF star_8::boundingRect() const {
    return QRectF(40,40,200*100,200*100);
}
void star_8::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) {
    if(n){
        QPointF *point=new QPointF[17];
        QPolygonF polygon;
        for(int i=0;i<8;++i){
            qreal angle=2*M_PI*i/8;
            point[i*2]=QPointF((x+r*sin(angle)*0.8+dx)*xx,(y+r*cos(angle)+dy)*xx);
            point[i*2+1]= QPointF((x+r*sin(angle+M_PI/8)/2*0.8+dx)*xx,(y+r/2*cos(angle+M_PI/8)+dy)*xx);
            }
        painter->setBrush(Qt::blue);
            point[16]=point[0];
        for(int i=0;i<16;++i){
                polygon << point[i]<< point[i+1];
        }
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
        else if((polygon[12].x()-10<=m2.x())&&(polygon[12].y()-10<=m2.y())&&(polygon[12].x()+10>=m2.x())&&(polygon[12].y()+10>=m2.y())){
            fl=1;
            polygon[12]=m1;
        }
        else if((polygon[13].x()-10<=m2.x())&&(polygon[13].y()-10<=m2.y())&&(polygon[13].x()+10>=m2.x())&&(polygon[13].y()+10>=m2.y())){
            fl=1;
            polygon[13]=m1;
        }
        else if((polygon[14].x()-10<=m2.x())&&(polygon[14].y()-10<=m2.y())&&(polygon[14].x()+10>=m2.x())&&(polygon[14].y()+10>=m2.y())){
            fl=1;
            polygon[14]=m1;
        }
        else if((polygon[15].x()-10<=m2.x())&&(polygon[15].y()-10<=m2.y())&&(polygon[15].x()+10>=m2.x())&&(polygon[15].y()+10>=m2.y())){
            fl=1;
            polygon[15]=m1;
        }
        else {
            fl=0;
        }
        painter->drawPolygon(polygon);
            update();
    }
}
void star_8::create_st8(){
    if(n!=1){
    n=1;
    x=100;
    y=100;
    r=60;
    xx=1;
    fl=0;
    m1=QPointF(0,0);
    m2=QPointF(0,0);
    update();
    }
}
void star_8::destroy_st8(){
    r=0;
    x=0;
    y=0;
    n=0;
    xx=0;
    fl=0;
    m1=QPointF(0,0);
    update();
}

void star_8::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    m1=event->pos();
    m2=event->pos();
    this->setCursor(QCursor(Qt::ClosedHandCursor));


}
void star_8::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {

    if(fl){

        m1=event->pos();
        update();
    }
    else{
        this->setPos(mapToScene(event->pos()));
        fl=1;
    }

}
void star_8::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));

}
void star_8::mashUp(QGraphicsItem* items){
    xx+=0.001;
    items->setTransformOriginPoint(m1);
    update();
}
void star_8::mashDown(QGraphicsItem* items){
    xx-=0.001;
    items->setTransformOriginPoint(m1);
    update();
}
