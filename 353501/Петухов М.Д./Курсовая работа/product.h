#pragma once
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsObject>
#include <QGraphicsSceneHoverEvent>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPropertyAnimation>
#include <QPainter>

class Product : public QGraphicsObject
{
    Q_OBJECT
private:    
    int y = 0;
    int x = 0;
    QTimer* timer;
    QPointF coord;  
    QPixmap m_image;
    bool productWasCollectedBool = false;

public:
    Product();

    QRectF boundingRect() const override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent*) override;

    void hoverLeaveEvent(QGraphicsSceneHoverEvent*) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *aEvent) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *aEvent) override;

    void move();

signals:
    void productWasCollected();

};
