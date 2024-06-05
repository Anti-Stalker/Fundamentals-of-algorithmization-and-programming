#include "figurestar8.h"

FigureStar8::FigureStar8() {}

float FigureStar8::findPerimeter()
{
    float scale = this->getScale();
    return 16 * side * scale;
}

float FigureStar8::findSquare()
{
    float scale = this->getScale();
    float tangent = tan(M_PI / 8);  // Вычисляем тангенс угла π/8
    float area = (7.0 / 4.0) * pow(side, 2) * tangent;  // Вычисляем площадь звезды
    return scale * scale * area;
}

void FigureStar8::receiveValue(int sideOfStar)
{
    side = sideOfStar;
}

void FigureStar8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    float angle = 45.0; // Угол между лучами звезды (45 градусов для 8-конечной звезды)
    float outerRadius = side / 2.0; // Внешний радиус звезды (равен половине стороны)
    float innerRadius = outerRadius * 0.382; // Внутренний радиус звезды (пропорционально внешнему радиусу)
    QPointF center(0, 0);
    QPolygonF polygon;

    for (int i = 0; i < 8; ++i) {
        // Вычисляем координаты точек на внешнем и внутреннем круге
        float outerX = center.x() + outerRadius * cos(qDegreesToRadians(angle * i));
        float outerY = center.y() + outerRadius * sin(qDegreesToRadians(angle * i));
        float innerX = center.x() + innerRadius * cos(qDegreesToRadians(angle * i + angle / 2.0));
        float innerY = center.y() + innerRadius * sin(qDegreesToRadians(angle * i + angle / 2.0));

        // Добавляем точки в полигон
        polygon << QPointF(outerX, outerY);
        polygon << QPointF(innerX, innerY);
    }
    painter->drawPolygon(polygon);
}
