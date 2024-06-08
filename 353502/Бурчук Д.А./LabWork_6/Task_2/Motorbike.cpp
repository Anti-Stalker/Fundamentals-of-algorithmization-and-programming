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
    //delete[] this->brand;
}

QString Motorbike::print() {
    QString tmp;
    tmp.append(QString::number(this->mileage) + "!");
    tmp.append(QString(QString::number(this->max_speed, 'f', 3)) + "!");
    tmp.append(QString(this->type) + "!");
    tmp.append(QString(this->isWoundUp ? "yes" : "no") + "!");
    tmp.append(QString(this->brand) + "!");
    tmp.append(QString(QString::number(this->lastModelNumber)) + "!");
    return tmp;
}
