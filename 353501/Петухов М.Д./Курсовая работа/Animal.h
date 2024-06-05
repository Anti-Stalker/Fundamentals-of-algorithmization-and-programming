#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QVector2D>
#include <QtMath>
#include <QGraphicsObject>
#include <QPixmap>
#include <QRandomGenerator>
#include "CustomGraphicsScene.h"
#include <QPropertyAnimation>
#include "Egg.h"
#include "xorshiftplus.h"
#include <random>

class Animal : public QGraphicsObject
{
    Q_OBJECT
private:
    XORShiftPlusPlus* rng;

    bool wasAnyGrassEaten = false;

    int indexOfGrassToRemove = NO_SUCH_GRASS_INDEX;

    CustomGraphicsScene* scene;

    QVector<QString> pathes;
    QString currentPath;

    static const int NO_SUCH_GRASS_INDEX = 100;
    
    QVector<Egg*>* _ptrToEggVec;
public:
    qreal closestDistance;
    qreal distX;
    qreal distY;
    
    QTimer* timerToRandomMoving;
    QTimer* timerToFindGrass;
    QTimer* timerChangeAnimationPictures;   
    QTimer* timeForDurationAnimation;
    QTimer* timerForMinusEatenGrass;
    QTimer* timerToMakeEgg;

    Animal(CustomGraphicsScene* sceneArg, QVector<Egg*>* _myEggVector, QGraphicsItem* parent = nullptr);
    ~Animal();


    QRectF boundingRect() const override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
public:
    int countEatenGrass{8};
    QPixmap m_image;
    void stopEatingAnimation();
    void minusEatenGrass();
    void findClosestGrass(QPointF animPos);
    void findGrass();
    void finishedFindingGrass();
    void stopAnimation();
    void startRandomMoving();
    void startRandomTimer();
    void startTimeToMakeEgg();
    void makeEgg();

    int detectGrassIndexByPos(qreal posXOfCollidingGrass, qreal posYOfCollidingGrass);
    qreal findDist(qreal animPosX, qreal animPosY, qreal posX, qreal posY);
public slots:
    void startEatingAnimation();
    void collectedEggsIncrement(Egg* eggToRemoveFromScene);
signals:
    void updateCollectedEggsLabelSignal();
    void deleteHenSignal(Animal* hen);
};