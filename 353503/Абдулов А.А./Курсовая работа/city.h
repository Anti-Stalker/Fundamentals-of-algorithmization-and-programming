#ifndef CITY_H
#define CITY_H

#include "truck.h"
#include <QColor>
#include <QPoint>
#include <QColor>
#include <QString>
#include <QGraphicsEllipseItem>
#include <QPen>

class City : public QGraphicsEllipseItem{
    QString name;
    QPoint centre;
public:    
    City(QString name, QPoint centre);

    virtual std::vector<Truck*> getTrucks();
    virtual void addTruck(Truck* truck);
    virtual void deleteTruck(int ind);
    virtual void changeTruck(Truck* truck);
    virtual void setTruckList(std::vector<Truck*>);

    QPoint getCentre();
    QString getName();
};

#endif // CITY_H
