#include "figurerhombus.h"

FigureRhombus::FigureRhombus() {}

float FigureRhombus::findSquare()
{
    float scale = this->getScale();
    return d1 * d2 * scale * scale / 2;
}

float FigureRhombus::findPerimeter()
{
    float scale = this->getScale();
    return scale * 4 * sqrt(d1 * d1 / 4 + d2 * d2 / 4);
}

void FigureRhombus::receiveRhombus(sideAndAngleCoordinates &coordinates)
{
    d1 = coordinates.side1;
    d2 = coordinates.side2;
}

void FigureRhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPolygon(QPolygonF() << QPointF(-d1/2, 0) << QPointF(0, -d2/2) << QPointF(d1/2, 0) << QPointF(0, d2/2));
}
