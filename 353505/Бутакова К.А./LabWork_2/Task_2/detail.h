#ifndef DETAIL_H
#define DETAIL_H

#include <QString>

class Detail
{
public:
    Detail() : coast(0.0), avaliable(false) {}
    Detail(QString, QString, QString, QString, double, bool);
    QString GetType();
    QString GetCompany();
    QString GetModel();
    QString GetParameters();
    double GetCoast();
    bool isAvaliable();
private:
    QString type;
    QString company;
    QString model;
    QString parameters;
    double coast;
    bool avaliable;
};

#endif // DETAIL_H
