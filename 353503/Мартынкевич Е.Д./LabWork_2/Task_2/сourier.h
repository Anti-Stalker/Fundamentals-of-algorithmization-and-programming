#ifndef COURIER_H
#define COURIER_H

#include "qdatetime.h"
#include <QString>

class Courier
{
public:
    Courier(int number, QString fio, QTime begin_time, QTime end_time, double min_mass);
    ~Courier();

    int getnumber() const;

    void setnumber(int newnumber);

    QString getfio() const;

    void setfio(QString& newfio);

    QTime getbegin_time() const;

    void setbegin_time(const QTime& newbegin_time);

    QTime getend_time() const;

    void setend_time(const QTime& newend_time);

    double getmin_mass() const;

    void setmin_mass(double newmin_mass);

private:
    int number;
    QString fio;
    QTime begin_time;
    QTime end_time;
    double min_mass;
};

#endif // COURIER_H
