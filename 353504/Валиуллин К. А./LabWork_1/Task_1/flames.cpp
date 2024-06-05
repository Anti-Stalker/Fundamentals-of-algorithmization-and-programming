#include "flames.h"

Flames::Flames() {}

void Flames::moveLineUp()
{
    animationUp = new QPropertyAnimation(this, "y");
    animationUp->setDuration(timeUp);
    animationUp->setStartValue(startY);
    animationUp->setEndValue(targetY);
    animationUp->start();
}

void Flames::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::yellow);

    QPolygonF flames;
    flames << QPointF(-10, 120) << QPointF(0, 160) << QPointF(10, 120);
    painter->drawPolygon(flames);

}

QRectF Flames::boundingRect() const
{
    return QRectF(-10, 120, 20, 40);
}
