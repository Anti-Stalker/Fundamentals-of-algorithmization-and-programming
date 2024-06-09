#include "zakaz.h"

Zakaz::Zakaz(int number, QString adress, QDate data, QTime time, double massa) {
    this->number = number;
    this->adress = adress;
    this->data = data;
    this->time = time;
    this->massa = massa;
}

Zakaz::~Zakaz()
{

}

int Zakaz::getnumber() const
{
    return this->number;
}

void Zakaz::setnumber(int newnumber)
{
    this->number = newnumber;
}

QString Zakaz::getadress() const
{
    return this->adress;
}

void Zakaz::setadress(QString &newadress)
{
    this->adress = newadress;
}

QDate Zakaz::getdata() const
{
    return this->data;
}

void Zakaz::setdata(const QDate &newdata)
{
    this->data = newdata;
}

QTime Zakaz::gettime() const
{
    return this->time;
}

void Zakaz::settime(const QTime &newtime)
{
    this->time = newtime;
}

double Zakaz::getmassa() const
{
    return this->massa;
}

void Zakaz::setmassa(double newmassa)
{
    this->massa = newmassa;
}

int Zakaz::getcourier() const
{
    return this->courier;
}

void Zakaz::setcourier(int newcourier)
{
    this->courier = newcourier;
}
