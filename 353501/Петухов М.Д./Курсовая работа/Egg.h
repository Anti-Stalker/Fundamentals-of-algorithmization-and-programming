#ifndef EGG_H
#define EGG_H

#pragma once
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsObject>
#include <QGraphicsSceneHoverEvent>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPropertyAnimation>

class Egg : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
private:    
    int y = 0;
    int x = 0;
    QTimer* timer;
    QPointF coord;  
    QPixmap m_image;
    bool isMouseOnThisEgg;


public:
    Egg();

    QRectF boundingRect() const override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent*) override;
//------------------------------------------------------------------------------
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *aEvent) override;

    void move();

    //------------------------------------------------------------------------------
    //------------------------------------------------------------------------------
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *aEvent) override;
    
    bool wasEggCollectedBool = false;
signals:
    void eggWasCollected(Egg* thisEgg);
};


#endif // EGG_H