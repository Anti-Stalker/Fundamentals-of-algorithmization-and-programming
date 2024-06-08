#include "square.h"
void Square::move_right(){
    dx+=0.1;
    rec=QRect(x,y,w,w);
    update();
}
void Square::move_left(){
    dx-=0.1;
    rec=QRect(x,y,w,w);
    update();
}
void Square::move_up(){
    dy-=0.1;
    rec=QRect(x,y,w,w);
    update();
}
void Square::move_down(){
    dy+=0.1;
    rec=QRect(x,y,w,w);
    update();
}
double Square::areaFind() {

    return w*(xx)*(xx)*2;
}


double Square::perFind(){
    return w/4*(xx);
}

double Square::centrFindX(){
    return (x+dx)*xx;
}
double Square::centrFindY(){
    return (y+dy)*xx;
}
void Square::destroy_square(){
    y=0;
    x=0;
    w=0;
    xx=0;
    dx=0;
    dy=0;
    rec=QRect(x,y,w,w);
    m1=QPointF(0,0);
    m2=QPointF(0,0);
    update();
}
void Square::create_square(){
    x=100;
    y=100;
    w=100;
    xx=1;
    dx=0;
    dy=0;
    rec=QRect(x,y,w,w);
    m1=QPointF(0,0);
    update();
}


QRectF Square::boundingRect() const {
    return QRect(20,20,200*110,200*110);
}
void Square::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget){
    Q_UNUSED(widget);
    Q_UNUSED(option);
    QPolygonF polygon;
    polygon << QPointF(((x)*xx+dx),(y)*xx+dy) << QPointF(2*(x)*xx+dx,(y)*xx+dy) << QPointF(2*(x)*xx+dx,2*(y)*xx+dy) << QPointF((x)*xx+dx,(y)*xx*2+dy);
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

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event) {
        m2=event->pos();
        this->setCursor(QCursor(Qt::ClosedHandCursor));
        m1=event->pos();

}
void Square::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if(fl){

        m1=event->pos();
        update();
    }
    else{
        this->setPos(mapToScene(event->pos()));
        fl=1;
    }
}
void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));

}
void Square::mashUp(QGraphicsItem* items){
    xx+=0.0001;
    items->setTransformOriginPoint(m1);
    items->setScale(xx);
}
void Square::mashDown(QGraphicsItem* items){
    xx-=0.0001;
    items->setTransformOriginPoint(m1);
    items->setScale(xx);
}
