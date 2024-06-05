#ifndef MOVINGLINE_H
#define MOVINGLINE_H

#include <QGraphicsLineItem>
#include <QPropertyAnimation>
#include <QPainter>
#include <QPixmap>
#include <QObject>

class MovingLine : public QGraphicsObject
{

public:
    MovingLine();
    virtual void moveLineUp();
    virtual void moveLineDown();
    int startY = 500, targetY = 0, timeUp = 1000, timeDown = 2000;

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    virtual QRectF boundingRect() const override;
    QPropertyAnimation *animationUp, *animationDown;

};

#endif // MOVINGLINE_H
