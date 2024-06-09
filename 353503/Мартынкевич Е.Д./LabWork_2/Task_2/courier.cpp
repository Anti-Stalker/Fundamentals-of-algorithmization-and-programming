#include "сourier.h"

Courier::Courier(int number, QString fio, QTime begin_time, QTime end_time, double min_mass) {
    this->number = number;
    this->fio = fio;
    this->begin_time = begin_time;
    this->end_time = end_time;
    this->min_mass = min_mass;
}

Courier::~Courier()
{

}

int Courier::getnumber() const
{
    return this->number;
}

void Courier::setnumber(int newnumber)
{
    this->number = newnumber;
}

QString Courier::getfio() const
{
    return this->fio;
}

void Courier::setfio(QString &newfio)
{
    this->fio = newfio;
}

QTime Courier::getbegin_time() const
{
    return this->begin_time;
}

void Courier::setbegin_time(const QTime &newbegin_time)
{
    this->begin_time = newbegin_time;
}

QTime Courier::getend_time() const
{
    return this->end_time;
}

void Courier::setend_time(const QTime &newend_time)
{
    this->end_time = newend_time;
}

double Courier::getmin_mass() const
{
    return this->min_mass;
}

void Courier::setmin_mass(double newmin_mass)
{
    this->min_mass = newmin_mass;
}
