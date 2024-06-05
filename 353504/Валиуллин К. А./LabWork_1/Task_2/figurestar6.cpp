#include "figurestar6.h"

FigureStar6::FigureStar6() {}

float FigureStar6::findPerimeter()
{
    float scale = this->getScale();
    return scale * 12 * side;
}

float FigureStar6::findSquare()
{
    float scale = this->getScale();
    float tangent = tan(M_PI / 6);  // Вычисляем тангенс угла π/6
    float area = (3.0 / 2.0) * pow(side, 2) * tangent;  // Вычисляем площадь звезды
    return area * scale * scale;
}

void FigureStar6::receiveValue(int sideOfStar)
{
    side = sideOfStar;
}


void FigureStar6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << side;
    float angle = 60.0; // Угол между лучами звезды (60 градусов для 6-конечной звезды)
    float outerRadius = side / 2.0; // Внешний радиус звезды (равен половине стороны)
    float innerRadius = outerRadius * 0.382; // Внутренний радиус звезды (пропорционально внешнему радиусу)
    QPointF center(0, 0);
    QPolygonF polygon;

    for (int i = 0; i < 6; ++i) {
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
