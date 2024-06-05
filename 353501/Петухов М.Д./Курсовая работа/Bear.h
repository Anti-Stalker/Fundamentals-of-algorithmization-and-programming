#pragma once

#include <QGraphicsObject>
#include <QPixmap>
#include "CustomGraphicsScene.h"
#include <QPropertyAnimation>
#include <QTimer>
#include <QMouseEvent>
#include "Animal.h"
#include "xorshiftplus.h"

class Bear : public QGraphicsObject
{
    Q_OBJECT
private:

    XORShiftPlusPlus* rng;

    CustomGraphicsScene* scene;

    QVector<QString> pathes;
    QString currentPath;
    QPixmap m_image;
    short frameNumber = 0;
    QTimer* animationTimer;
    QVector<QString> pathesToCagePictures;

    QTimer* timerToChangeDirection;
    QTimer* timerToCheckCollidingHens;
    int health = 4;
    int damage = -1;
    double coefSlowdown = 1;

public:
    Bear(CustomGraphicsScene* sceneArg, QGraphicsItem* parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    qreal findDist(qreal animPosX, qreal animPosY, qreal posX, qreal posY);
private:
    void changeAnimationFrame();
    void setImage(int frameNumber);
    void changeDirection();
    void checkCollidingHens();
    void startTimerToChangeDirection();

    void mousePressEvent(QGraphicsSceneMouseEvent *aEvent) override; 
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent*) override;
public:
    bool isMouseOnThisBear;
signals:
    void bearWasRemoved();
};