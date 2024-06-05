#include "city.h"

City::City(QString name, QPoint centre) : QGraphicsEllipseItem(centre.x(), centre.y(), 50, 50, nullptr){
    this->name=name;
    this->centre = centre;

    setRect(centre.x()-25, centre.y()-25, 50, 50);

    QPen pen(Qt::blue);
    setPen(pen);

    QBrush brush(Qt::darkGray);
    setBrush(brush);
}

QPoint City::getCentre(){
    return centre;
}

QString City::getName(){
    return name;
}

std::vector<Truck*> City::getTrucks(){
    std::vector<Truck*> emptyVector;
    return emptyVector;
}

void City::addTruck(Truck* truck){

}

void City::deleteTruck(int ind){

}

void City::changeTruck(Truck* truck){

}

void City::setTruckList(std::vector<Truck*> trucks){

}
