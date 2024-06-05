#include "workers.h"

Workers::Workers(QString fName, QString pName, QString tName, QString cDate, QString sDate, QString fDate) : fName(fName), pName(pName),tName(tName),cDate(cDate),sDate(sDate),fDate(fDate){};

QString Workers::getfName(){
    return fName;
};

QString Workers::getpName(){
    return pName;
}

QString Workers::gettName(){
    return tName;
};


QString Workers::getcDate(){
    return cDate;
};


QString Workers::getsDate(){
    return sDate;
};


QString Workers::getfDate(){
    return fDate;
};
