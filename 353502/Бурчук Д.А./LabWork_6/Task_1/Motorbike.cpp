#include "Motorbike.h"


Motorbike::Motorbike(QString init_str) {
    QStringList list = init_str.split(" ");
    this->mileage = list[0].toInt();
    this->max_speed = list[1].toDouble();
    this->type = list[2].toStdString()[0];
    this->isWoundUp = (list[3].toInt() != 0);
    this->brand = new char[list[4].length()];
    for (int i = 0; i < list[4].length(); ++i) {
        this->brand[i] = list[4].toStdString()[i];

    }
    this->brand[list[4].length()] = '\0';
    this->lastModelNumber = (list[5].toInt());
}

Motorbike::~Motorbike() {
    delete[] this->brand;
}

QString Motorbike::print() {
    QString tmp;
    tmp.append("Mileage: " + QString::number(this->mileage) + " | ");
    tmp.append("Speed: " + QString(QString::number(this->max_speed, 'f', 3)) + " | ");
    tmp.append("Type: " + QString(this->type) + " | ");
    tmp.append("IsWoundUp: " +
               ((this->isWoundUp) ? QString("yes") : QString("no")) + " | ");
    tmp.append("Brand: " + QString(this->brand) + " | ");
    tmp.append("lastModelNumber: " + QString(QString::number(this->lastModelNumber)) + " | ");
    return tmp;
}

Motorbike &Motorbike::operator=(const Motorbike &motorbike) {
    if (this == &motorbike) {
        return *this;
    }

    this->mileage = motorbike.mileage;
    this->max_speed = motorbike.max_speed;
    this->type = motorbike.type;
    this->isWoundUp = motorbike.isWoundUp;
    this->lastModelNumber = motorbike.lastModelNumber;

    delete[] this->brand;

    if (motorbike.brand) {
        this->brand = new char[strlen(motorbike.brand) + 1];
        strcpy(this->brand, motorbike.brand);
    } else {
        this->brand = nullptr;
    }

    return *this;
}
