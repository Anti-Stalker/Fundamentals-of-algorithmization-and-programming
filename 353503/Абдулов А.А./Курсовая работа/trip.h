#ifndef TRIP_H
#define TRIP_H

#include "truck.h"
#include "road.h"

class Trip{
public:
    Trip(int kg, std::vector<Truck*> trucks, std::vector<Road*> roads, bool isMinTime);
    std::vector<Truck*> getTrucks();
    std::vector<Road*> getRoads();
    QString getInfo();
    void setStatusOfTrucks(bool status);
    void updateTruckDistance(float dist);
    int getKg();
private:
    std::vector<Truck*> trucks;
    std::vector<Road*> roads;
    int kg;
    bool isMinTime;
    QString info;

};

#endif // TRIP_H
