#include "figuretriangle.h"

FigureTriangle::FigureTriangle() {}

void FigureTriangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    qreal centerX = (x1 + x2 + x3) / 3.0;
    qreal centerY = (y1 + y2 + y3) / 3.0;
    qreal shiftedX1 = x1 - centerX;
    qreal shiftedY1 = y1 - centerY;
    qreal shiftedX2 = x2 - centerX;
    qreal shiftedY2 = y2 - centerY;
    qreal shiftedX3 = x3 - centerX;
    qreal shiftedY3 = y3 - centerY;
    QPolygon polygon;
    polygon << QPoint(shiftedX1, shiftedY1) << QPoint(shiftedX2, shiftedY2) << QPoint(shiftedX3, shiftedY3);
    painter->drawPolygon(polygon);
}
void FigureTriangle::receiveTriangleValues(const TriangleCoordinates& coordinates)
{
    x1 = coordinates.x1;
    y1 = coordinates.y1;
    x2 = coordinates.x2;
    y2 = coordinates.y2;
    x3 = coordinates.x3;
    y3 = coordinates.y3;
}

float FigureTriangle::findSquare() {
    float scale = this->getScale();
    float a = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    float b = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
    float c = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));
    float s = (a + b + c) / 2;
    float square = std::sqrt(s * (s - a) * (s - b) * (s - c));
    return square * scale * scale;;
}

float FigureTriangle::findPerimeter() {
    float scale = this->getScale();
    float a = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    float b = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
    float c = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));
    float perimeter = a + b + c;
    return perimeter * scale;
}



