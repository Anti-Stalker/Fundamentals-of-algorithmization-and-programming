#include "figurerectangle.h"

FigureRectangle::FigureRectangle() {}

float FigureRectangle::findPerimeter()
{
    float scale = this->getScale();
    return scale * 2 * (side1 + side2);
}

float FigureRectangle::findSquare()
{
    float scale = this->getScale();
    return scale * scale * side1 * side2;
}

void FigureRectangle::receiveValues(sidesValues &sides)
{
    side1 = sides.side1;
    side2 = sides.side2;
}

void FigureRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPointF topLeft(-side1 / 2.0, -side2 / 2.0);
    QPointF topRight(side1 / 2.0, -side2 / 2.0);
    QPointF bottomRight(side1 / 2.0, side2 / 2.0);
    QPointF bottomLeft(-side1 / 2.0, side2 / 2.0);
    QPolygonF polygon;
    polygon << topLeft << topRight << bottomRight << bottomLeft;
    painter->drawPolygon(polygon);
}
