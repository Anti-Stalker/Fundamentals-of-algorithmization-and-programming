#include "base.h"

Base::Base(QString name, QPoint centre) : City::City(name, centre){
    setRect(centre.x()-25, centre.y()-25, 50, 50);

    QPen pen(Qt::green);
    setPen(pen);

    QBrush brush(Qt::darkGray);
    setBrush(brush);
}

void Base::addTruck(Truck* truck){
    trucks.push_back(truck);
}

void Base::deleteTruck(int ind){
    trucks.erase(trucks.begin() + ind);
}

std::vector<Truck*> Base::getTrucks(){
    return trucks;
}

void Base::changeTruck(Truck* truck){
    for(Truck* currentTruck : trucks){
        if(currentTruck->equals(truck)){
            currentTruck = truck;
        }
    }
}

void Base::setTruckList(std::vector<Truck*> trucks){
    this->trucks = trucks;
}


