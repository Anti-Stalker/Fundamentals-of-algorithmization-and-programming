#include "rhombus.h"

rhombus::rhombus(QPointF point, QObject* parent) : figures(point, parent){}

rhombus::~rhombus()
{

}

void rhombus::set_perimetr()
{
    double r1 = qAbs(startPoint().x() - endPoint().x());
    double r2 = qAbs(startPoint().y() - endPoint().y());
    m_perimetr = 4 * (sqrt(r1 * r1 + r2 * r2));
}

void rhombus::set_square()
{
    double r1 = qAbs(startPoint().x() - endPoint().x());
    double r2 = qAbs(startPoint().y() - endPoint().y());
    m_square = r1 * r2 / 2;
}

void rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF pol;
    pol << QPointF((startPoint().x() + endPoint().x()) / 2, startPoint().y())
        << QPointF(startPoint().x(), (startPoint().y() + endPoint().y()) / 2)
        << QPointF((startPoint().x() + endPoint().x()) / 2, endPoint().y())
        << QPointF(endPoint().x(), (startPoint().y() + endPoint().y()) / 2);

    painter->drawPolygon(pol);
    painter->drawEllipse(this->centre(), 1, 1);
}
