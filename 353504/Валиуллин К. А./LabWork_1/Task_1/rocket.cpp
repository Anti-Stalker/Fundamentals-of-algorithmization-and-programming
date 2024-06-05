#include "rocket.h"

Rocket::Rocket() {}

void Rocket::moveLineUp()
{
    animationUp = new QPropertyAnimation(this, "y");
    animationUp->setDuration(timeUp);
    animationUp->setStartValue(startY);
    animationUp->setEndValue(targetY);
    animationUp->start();
}

void Rocket::moveLineDown()
{
    animationDown = new QPropertyAnimation(this, "y");
    animationDown->setDuration(timeDown);
    animationDown->setStartValue(targetY);
    animationDown->setEndValue(startY);
    animationDown->start();
}

void Rocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);

    QPolygonF rocketBody;
    rocketBody << QPointF(0, 0) << QPointF(-30, 110) << QPointF(30, 110);

    QPolygonF soploBody;
    soploBody << QPointF(-30, 120) << QPointF(30, 120) << QPointF(30, 110) << QPointF(-30, 110);

    painter->setBrush(Qt::gray);
    painter->drawPolygon(rocketBody);
    painter->setBrush(Qt::black);
    painter->drawPolygon(soploBody);
    QPixmap flag("//home/konstantin/QTProjects/OAIP_LABS/LAB1/TASK1/belarus_flag.jpg");
    QRectF flagRect(-15, 70, 30, 20);
    painter->drawPixmap(QRectF(flagRect).toRect(), flag);
}

QRectF Rocket::boundingRect() const
{
    return QRectF(-30, 0, 60, 120);
}
