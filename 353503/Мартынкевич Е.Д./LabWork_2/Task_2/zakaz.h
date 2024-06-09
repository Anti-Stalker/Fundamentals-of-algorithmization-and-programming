#ifndef ZAKAZ_H
#define ZAKAZ_H

#include "qdatetime.h"
#include <QString>

class Zakaz
{
public:
    Zakaz(int number, QString adress, QDate data, QTime time, double massa);
    ~Zakaz();

    int getnumber() const;

    void setnumber(int newnumber);

    QString getadress() const;

    void setadress(QString& newadress);

    QDate getdata() const;

    void setdata(const QDate& newdata);

    QTime gettime() const;

    void settime(const QTime& newtime);

    double getmassa() const;

    void setmassa(double newmassa);

    int getcourier() const;

    void setcourier(int newcourier);

private:
    int number;
    QString adress;
    QDate data;
    QTime time;
    double massa;
    int courier;
};

#endif // ZAKAZ_H
