#ifndef BASE_H
#define BASE_H

#include "city.h"
#include "truck.h"
#include <QGraphicsEllipseItem>

class Base : public City{
public:
    Base(QString name, QPoint centre);
    std::vector<Truck*> getTrucks() override;
    void addTruck(Truck* truck) override;
    void deleteTruck(int ind) override;
    void changeTruck(Truck* truck) override;
    void setTruckList(std::vector<Truck*>) override;
private:
    std::vector<Truck*> trucks;
};

#endif // BASE_H
