#include "archer.h"

Archer::Archer() : Unit()
{
    range = 5;
}

void Archer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPixmap pixmap("://archer.png");
    QPixmap ne = pixmap.scaled(25, 25, Qt::KeepAspectRatio);
    painter->drawPixmap(0, 0, ne);
    if (isEnemy)
    {
        baseColor = Qt::black;
        color = Qt::black;
    }
    if (selected)
    {
        painter->setPen(Qt::red);
    }
    else if (!selected)
    {
        painter->setPen(color);
    }
    painter->drawEllipse(0, 0, 25, 25);

    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
    painter->drawRect(0, 20, 25, 5);
    painter->setBrush(Qt::green);
    painter->setPen(Qt::green);
    painter->drawRect(0, 20, (double)health / 100.0 * 25.0, 5);
}
