#ifndef BASETOWER_H
#define BASETOWER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPainter>
#include <QEventLoop>
#include <QTimer>

class BaseTower : public QObject, public QGraphicsPixmapItem
{
public:
    BaseTower();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int hp = 2000;
    void getDamage();
    QColor color = Qt::darkBlue;
    QColor baseColor = Qt::darkBlue;
};

#endif // BASETOWER_H
