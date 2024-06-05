#include "figurestar5.h"

FigureStar5::FigureStar5() {}

float FigureStar5::findPerimeter()
{
    float scale = this->getScale();
    return 10 * side * scale;
}

float FigureStar5::findSquare()
{
    float scale = this->getScale();
    float cotangent = 1 / tan(M_PI / 5);  // Вычисляем котангенс угла π/5
    float area = (5.0 / 4.0) * pow(side, 2) * cotangent;
    return area * scale * scale;
}

void FigureStar5::receiveValue(int sideOfStar)
{
    side = sideOfStar;
}

void FigureStar5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << side;
    float angle = 72.0; // Угол между лучами звезды (72 градуса для 5-конечной звезды)
    float outerRadius = side / 2.0; // Внешний радиус звезды (равен половине стороны)
    float innerRadius = outerRadius * 0.382; // Внутренний радиус звезды (пропорционально внешнему радиусу)
            QPointF center(0, 0);
    QPolygonF polygon;

    for (int i = 0; i < 5; ++i) {
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
