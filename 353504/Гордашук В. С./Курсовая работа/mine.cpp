#include "mine.h"

Mine::Mine() {}

void Mine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (hp <= 0)
    {
        QPixmap pixmap("://mineD.png");
        QPixmap ne = pixmap.scaled(75, 75, Qt::KeepAspectRatio);
        painter->drawPixmap(0, 10, ne);
    }
    else
    {
        QPixmap pixmap("://mine.png");
        QPixmap ne = pixmap.scaled(75, 75, Qt::KeepAspectRatio);
        painter->drawPixmap(0, 10, ne);
    }
}
