#include "disk.h"
#include "mainwindow.h"
Detail::Detail(QString t, QString c, QString m, QString p, double coa, bool ava) {
    group= t;
    name = c;
    priznak = m;
    remark = p;
    amount = coa;
    avaliable = ava;
}

QString Detail::GetGroup(){
    return group;
}

QString Detail::GetName(){
    return name;
}

QString Detail::GetPriznak(){
    return priznak;
}

QString Detail::GetRemark(){
    return remark;
}

double Detail::GetAmount(){
    return amount;
}

bool Detail::isAvaliable(){
    return avaliable;
}

