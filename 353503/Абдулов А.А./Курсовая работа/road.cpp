#include "road.h"
#include <cmath>
#include <QPen>

Road::Road(City* s1, City* s2, int maxSpeed)
    : QGraphicsLineItem(s1->getCentre().x(), s1->getCentre().y(), s2->getCentre().x(), s2->getCentre().y(), nullptr){

    QPen pen(Qt::white);
    pen.setWidth(1);
    setPen(pen);

    this->s1 = s1;
    this->s2 = s2;
    p1 = s1->getCentre();
    p2 = s2->getCentre();
    this->distance = sqrt(pow((p1.x()-p2.x()), 2) + pow((p1.y()-p2.y()), 2));
    this->maxSpeed = maxSpeed;
}

QPoint Road::getP1(){
    return p1;
}

QPoint Road::getP2(){
    return p2;
}

int Road::getMaxSpeed(){
    return maxSpeed;
}

double Road::getDistance(){
    return distance;
}

City* Road::getS1(){
    return s1;
}

City* Road::getS2(){
    return s2;
}

double Road::getTime(int speed){
    return distance/speed;
}

City* Road::getNextCity(City* city){
    if(city->getCentre() != s1->getCentre()){
        return s1;
    }
    return s2;
}
