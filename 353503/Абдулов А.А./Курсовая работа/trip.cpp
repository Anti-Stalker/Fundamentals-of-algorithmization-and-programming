#include "trip.h"

Trip::Trip(int kg, std::vector<Truck*> trucks, std::vector<Road*> roads, bool isMinTime) {
    this->trucks = trucks;
    this->roads = roads;
    this->kg = kg;
    this->isMinTime = isMinTime;

    if(isMinTime){
        info = " MinTimeTrip, ";
    }else
        info = " MinDistanceTrip, ";

    info += "Count of Trucks:" + QString::number(trucks.size()) + ", kg:" + QString::number(kg) +
            " to " + roads[roads.size()-1]->getS2()->getName();
}

std::vector<Truck*> Trip::getTrucks(){
    return trucks;
}

std::vector<Road*> Trip::getRoads(){
    return roads;
}

QString Trip::getInfo(){
    return info;
}

void Trip::setStatusOfTrucks(bool status){
    for(int i = 0; i < trucks.size(); i++){
        trucks[i]->setStatus(status);
    }
}

void Trip::updateTruckDistance(float dist){
    for(Truck* truck : trucks){
        truck->addKM(dist);
    }
}

int Trip::getKg(){
    return kg;
}

