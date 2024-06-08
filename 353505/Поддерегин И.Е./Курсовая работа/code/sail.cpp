#include "sail.h"

Sail::Sail()
{

}

Sail::~Sail()
{


}

void Sail::paint(QPainter *paint, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    paint->setRenderHint(QPainter::Antialiasing);
    paint->drawArc(75, 35, 75, 150, 2800, -660);
    paint->setBrush(Qt::black);
    paint->drawEllipse(85, 55, 5, 5);
    paint->drawLine(QLineF(87,55,76,107));
}

QRectF Sail::boundingRect() const
{
    return QRectF(50,40,75,75);
}
