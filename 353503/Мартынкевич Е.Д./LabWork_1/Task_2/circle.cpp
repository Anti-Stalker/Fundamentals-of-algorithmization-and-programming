#include "circle.h"

circle::circle(QPointF point, QObject* parent) : figures(point, parent){}

circle::~circle()
{

}

void circle::set_perimetr()
{
    double r = qAbs(startPoint().x() - endPoint().x()) / 2;
    m_perimetr = 2 * 3.14 * r;
}

void circle::set_square()
{
    double r = qAbs(startPoint().x() - endPoint().x()) / 2;
    m_square = 3.14 * r * r;
}

void circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(startPoint().x() < endPoint().x() ? startPoint().x() : endPoint().x()
                        , startPoint().y() < endPoint().y() ? startPoint().y() : endPoint().y(),
                         qAbs(startPoint().x() - endPoint().x()), qAbs(startPoint().y() - endPoint().y()));
    painter->drawEllipse(this->centre(), 1, 1);
}
