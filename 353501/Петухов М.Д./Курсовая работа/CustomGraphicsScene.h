#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include "Grass.h"

class CustomGraphicsScene : public QGraphicsScene
{
private:
    QPointF pos;    
public:
    int waterToGrowGrass = 7;   
    QVector<QGraphicsRectItem* > rectVector; 
public:
    CustomGraphicsScene(QObject* parent = nullptr);
    QVector<Grass* > grassVec;
    void drawWaterInWell();
    bool grassWasGrowed = false;
    bool checkIfSuchGrassAlreadyExist();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};