#include "rocket.h"
#include "line.h"
#include <QPolygon>

Rocket::Rocket() : Line()
{
    rect_ = QRectF(0, -225, 90, 225);
}

void Rocket::paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget * widget)
{

    QPolygon pol;
    pol << QPoint(0, 0) << QPoint(25, -25) << QPoint(25, -200) << QPoint(37, -225) << QPoint(49, -200)
        << QPoint(49, -25) << QPoint(74, 0) << QPoint(0, 0);

    painter->setBrush(Qt::red);

    painter->drawPolygon(pol);

    painter->setBrush(Qt::blue);
    painter->drawEllipse(30, -175, 15, 15);

    painter->setBrush(Qt::blue);
    //painter->
}
