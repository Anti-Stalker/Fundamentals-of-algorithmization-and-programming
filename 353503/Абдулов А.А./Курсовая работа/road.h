#ifndef ROAD_H
#define ROAD_H

#include <QPoint>
#include "city.h"
#include <QGraphicsLineItem>

class Road : public QGraphicsLineItem{
private:
    City* s1;
    City* s2;

    QPoint p1;
    QPoint p2;

    double distance;
    int maxSpeed;
public:
    Road(City* s1, City* s2, int maxSpeed);
    City* getNextCity(City* city);
    QPoint getP1();
    QPoint getP2();
    City* getS1();
    City* getS2();
    double getDistance();
    int getMaxSpeed();
    double getTime(int speed);
};

#endif // ROAD_H
