#include "saill.h"

SailL::SailL()
{

}

SailL::~SailL()
{

}

void SailL::paint(QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    paint->drawArc(24, 38, 75, 150, 80, 660);
    paint->setBrush(Qt::black);
    paint->drawEllipse(85, 55, 5, 5);
    paint->drawLine(QLineF(87,55,98,107));
}


QRectF SailL::boundingRect() const{
    return QRectF(50,10,75,90);
}
