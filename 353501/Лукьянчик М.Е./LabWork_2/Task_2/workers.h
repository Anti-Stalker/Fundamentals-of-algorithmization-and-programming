#ifndef WORKERS_H
#define WORKERS_H

#include <QString>
#include <QDate>

class Workers
{
public:
    Workers(QString fName, QString pName, QString tName, QString cDate, QString sDate, QString fDate);
    QString getfName();
    QString getpName();
    QString gettName();
    QString getcDate();
    QString getsDate();
    QString getfDate();

    QString fName;
    QString pName;
    QString tName;
    QString cDate;
    QString sDate;
    QString fDate;
};

#endif
