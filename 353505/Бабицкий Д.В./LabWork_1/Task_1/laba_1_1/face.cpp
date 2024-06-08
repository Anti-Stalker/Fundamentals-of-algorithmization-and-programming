
#include "face.h"

void face::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    QBrush brush(Qt::yellow);
    QBrush brush1(Qt::white);
    QBrush brush2(Qt::blue);
    painter.setBrush(brush);
    painter.drawEllipse(50,50,100,100);
    painter.setBrush(brush1);
    painter.drawEllipse(x+10,70,10,10);
    painter.drawEllipse(x-10,70,10,10);
    painter.setBrush(brush2);
    painter.drawEllipse(x1-10,100,w,h);

}


void::face::move_eyes_right(){
    if(x<=120){
    x+=5;
    update();
    }
}


void::face::move_eyes_left(){
    if(x>=80){
    x-=5;
    update();
    }
}



void::face::close_mouth(){
    w=0;
    h=0;
    update();
}
void::face::open_mouth(){
    w=35;
    h=10;
    update();
}
