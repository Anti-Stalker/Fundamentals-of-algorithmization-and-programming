#include "triangle.h"

triangle::triangle(QPointF point, QObject* parent) : figures(point, parent){}

triangle::~triangle()
{

}

void triangle::set_perimetr()
{
    double r2 = qAbs(startPoint().y() - endPoint().y());
    double r1 = qAbs(startPoint().x() - endPoint().x()) / 2;

    m_perimetr = 2 * (r1 + sqrt(r1 * r1 + r2 * r2));
}

void triangle::set_square()
{
   double r2 = qAbs(startPoint().y() - endPoint().y());
   double r1 = qAbs(startPoint().x() - endPoint().x()) / 2;

   m_square = r1 * r2;
}

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF pol;
    pol << QPointF((startPoint().x() + endPoint().x()) / 2, startPoint().y())
        << QPointF(startPoint().x(), endPoint().y())
        << QPointF(endPoint().x(), endPoint().y());

    painter->drawPolygon(pol);
    painter->drawEllipse(this->centre(), 1, 1);
}
