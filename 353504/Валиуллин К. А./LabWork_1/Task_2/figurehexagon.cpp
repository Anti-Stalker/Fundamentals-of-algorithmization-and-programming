#include "figurehexagon.h"

FigureHexagon::FigureHexagon() {}

float FigureHexagon::findPerimeter()
{
    float scale = this->getScale();
    return scale * 6 * side;
}

float FigureHexagon::findSquare()
{
    float scale = this->getScale();
    return scale * scale * (3.0 * sqrt(3.0) * pow(side, 2)) / 2.0;
}

void FigureHexagon::receiveValue(int side)
{
    this->side = side;
}

void FigureHexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPointF center(0, 0);
    QPolygonF polygon;

    for (int i = 0; i < 6; ++i) {
        // Вычисляем координаты вершин шестиугольника
        float x = center.x() + side * cos(qDegreesToRadians(60 * i));
        float y = center.y() + side * sin(qDegreesToRadians(60 * i));

        // Добавляем вершину в полигон
        polygon << QPointF(x, y);
    }

    painter->drawPolygon(polygon);
}
