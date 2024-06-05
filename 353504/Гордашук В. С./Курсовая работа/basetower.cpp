#include "basetower.h"

BaseTower::BaseTower()
{
}

QRectF BaseTower::boundingRect() const
{
    return QRectF(0, 0, 200, 200);
}

void BaseTower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (hp <= 0)
    {
        QPixmap pixmap("://end.png");
        QPixmap ne = pixmap.scaled(150, 150, Qt::KeepAspectRatio);
        painter->drawPixmap(0, 0, ne);
    }
    else
    {
        QPixmap pixmap("://tower.png");
        QPixmap ne = pixmap.scaled(150, 150, Qt::KeepAspectRatio);
        painter->drawPixmap(0, 0, ne);
        painter->setPen(color);
        painter->drawRect(0, 0, 150, 150);

        painter->setBrush(Qt::red);
        painter->setPen(Qt::red);
        painter->drawRect(0, 145, 150, 5);

        painter->setBrush(Qt::green);
        painter->setPen(Qt::green);
        painter->drawRect(0, 145, (double)hp / 2000.0 * 150.0, 5);
    }
}

void BaseTower::getDamage()
{
    color = Qt::red;
    update();
    QEventLoop loop;
    QTimer::singleShot(10, &loop, SLOT(quit()));
    loop.exec();
    color = baseColor;
    update();
}
