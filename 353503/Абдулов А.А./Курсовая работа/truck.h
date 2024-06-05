#ifndef TRUCK_H
#define TRUCK_H

#include <QGraphicsEllipseItem>
#include <QPoint>
#include <QColor>

class Truck : public QGraphicsEllipseItem{
public:
    Truck(int maxSpeed, int maxLoadCapacity, QPointF baseCenter, QColor color, int num);
    Truck();

    void setPos(QPointF pos);
    QPointF getPos();
    QColor getColor();
    int getNum();
    int getMaxSpeed();
    int getMaxLoadCapacity();
    void setNum(int num);
    bool getStatus();
    void setStatus(bool isBusy);
    void addKM(float km);
    void addKG(int kg);
    float getKM();
    float getKG();
    bool equals(Truck* truck);

private:
    float km = 0;
    int kg = 0;
    QColor color;
    QPointF pos;
    int num;
    int maxSpeed;
    int maxLoadCapacity;
    bool isBusy = false;
};

#endif // TRUCK_H
