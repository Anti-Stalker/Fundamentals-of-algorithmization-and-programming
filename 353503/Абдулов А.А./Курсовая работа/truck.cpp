#include "truck.h"
#include <QPen>

Truck::Truck(int maxSpeed, int maxLoadCapacity, QPointF pos, QColor color, int num)
    : QGraphicsEllipseItem(pos.x(), pos.y(), 20, 20, nullptr) {

    this->pos = pos;
    this->maxSpeed = maxSpeed;
    this->maxLoadCapacity = maxLoadCapacity;
    this->color = color;
    this->num = num;

    setRect(pos.x()-10, pos.y()-10, 20, 20);

    QPen pen(Qt::black);
    setPen(pen);

    QBrush brush(color);
    setBrush(brush);
}

int Truck::getNum(){
    return num;
}

QColor Truck::getColor(){
    return color;
}

void Truck::setPos(QPointF pos){
    this->pos = pos;
    setRect(pos.x()-10, pos.y()-10, 20, 20);
}

void Truck::setNum(int num){
    this->num = num;
}

int Truck::getMaxLoadCapacity(){
    return maxLoadCapacity;
}

int Truck::getMaxSpeed(){
    return maxSpeed;
}

bool Truck::getStatus(){
    return isBusy;
}

void Truck::setStatus(bool isBusy){
    this->isBusy = isBusy;
}

QPointF Truck::getPos(){
    return pos;
}

bool Truck::equals(Truck* truck){
    return maxLoadCapacity == truck->maxLoadCapacity && maxSpeed == truck->maxSpeed && num == truck->getNum();
}

void Truck::addKM(float km){
    this->km += km;
}

float Truck::getKM(){
    return km;
}

void Truck::addKG(int kg){
    this->kg += kg;
}

float Truck::getKG(){
    return kg;
}






