#include "star.h"

star::star(int n, QPointF point, QObject *parent) : figures(point, parent){
}

void star::set_perimetr()
{
    double r1 = qAbs(startPoint().y() - endPoint().y());
    double r2 = qAbs(startPoint().y() - endPoint().y());
    m_perimetr = 2 * (r1 + r2);
}

void star::set_square()
{
    double r1 = qAbs(startPoint().y() - endPoint().y());
    double r2 = qAbs(startPoint().y() - endPoint().y());
    m_square = r1 * r2 / 5;
}

void star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    double xp = startPoint().x(),
        xn = endPoint().x(),
        yp = startPoint().y(),
        yn = endPoint().y();


    double b = (xn - xp) / 2,
        a = (yn - yp) / 2;

    double xc = (xp + xn) / 2,
        yc = (yp + yn) / 2;

    QPolygonF pol, ply;

    ply << QPoint(boundingRect().width()*0.500 + startPoint().x(), boundingRect().height()*0.000 + startPoint().y())
            << QPoint(boundingRect().width()*0.612 + startPoint().x(), boundingRect().height()*0.345 + startPoint().y())
            << QPoint(boundingRect().width()*0.976 + startPoint().x(), boundingRect().height()*0.345 + startPoint().y())
            << QPoint(boundingRect().width()*0.682 + startPoint().x(), boundingRect().height()*0.559 + startPoint().y())
            << QPoint(boundingRect().width()*0.794 + startPoint().x(), boundingRect().height()*0.905 + startPoint().y())
            << QPoint(boundingRect().width()*0.500 + startPoint().x(), boundingRect().height()*0.691 + startPoint().y())
            << QPoint(boundingRect().width()*0.206 + startPoint().x(), boundingRect().height()*0.905 + startPoint().y())
            << QPoint(boundingRect().width()*0.318 + startPoint().x(), boundingRect().height()*0.559 + startPoint().y())
            << QPoint(boundingRect().width()*0.024 + startPoint().x(), boundingRect().height()*0.345 + startPoint().y())
            << QPoint(boundingRect().width()*0.388 + startPoint().x(), boundingRect().height()*0.345 + startPoint().y())
            << QPoint(boundingRect().width()*0.500 + startPoint().x(), boundingRect().height()*0.000 + startPoint().y());


    painter->drawPolygon(ply);
    painter->drawEllipse(this->centre(), 1, 1);
}
