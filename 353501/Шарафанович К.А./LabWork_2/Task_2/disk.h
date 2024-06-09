#ifndef DISK_H
#define DISK_H

#include <QString>

class Detail
{
public:
    Detail(QString, QString, QString, QString, double, bool);
    QString GetGroup();
    QString GetName();
    QString GetPriznak();
    QString GetRemark();
    double GetAmount();
    bool isAvaliable();
private:
    QString group;
    QString name;
    QString priznak;
    QString remark;
    double amount;
    bool avaliable;
};

#endif // DISK_H
