#include "rect.h"

rect::rect(QPointF point, QObject* parent) : figures(point, parent){}

rect::~rect()
{

}

void rect::set_perimetr()
{
    double r1 = qAbs(startPoint().y() - endPoint().y());
    double r2 = qAbs(startPoint().y() - endPoint().y());
    m_perimetr = 2 * (r1 + r2);
}

void rect::set_square()
{
    double r1 = qAbs(startPoint().y() - endPoint().y());
    double r2 = qAbs(startPoint().y() - endPoint().y());
    m_square = r1 * r2;
}

void rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF pol;
    pol << QPointF(startPoint().x(), startPoint().y())
        << QPointF(startPoint().x(), endPoint().y())
        << QPointF(endPoint().x(), endPoint().y())
        << QPointF(endPoint().x(), startPoint().y());

    painter->drawPolygon(pol);
    painter->drawEllipse(this->centre(), 1, 1);
}
