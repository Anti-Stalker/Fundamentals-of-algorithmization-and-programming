#include "figuresquare.h"

FigureSquare::FigureSquare() {}

float FigureSquare::findPerimeter()
{
    float scale = this->getScale();
    return 4 * side * scale;
}

float FigureSquare::findSquare()
{
    float scale = this->getScale();
    return side * side * scale * scale;
}

void FigureSquare::receiveValues(int s)
{
    side = s;
}

void FigureSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPointF topLeft(-side / 2.0, -side / 2.0);
    QPointF topRight(side / 2.0, -side / 2.0);
    QPointF bottomRight(side / 2.0, side / 2.0);
    QPointF bottomLeft(-side / 2.0, side / 2.0);
    QPolygonF polygon;
    polygon << topLeft << topRight << bottomRight << bottomLeft;
    painter->drawPolygon(polygon);
}
