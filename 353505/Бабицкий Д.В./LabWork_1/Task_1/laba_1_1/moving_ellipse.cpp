#include "moving_ellipse.h"


void Moving_ellipse::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);

    painter.drawEllipse(x,50,50,50);

}


void::Moving_ellipse::moveEllipse(){
    x+=10;
    update();
}

