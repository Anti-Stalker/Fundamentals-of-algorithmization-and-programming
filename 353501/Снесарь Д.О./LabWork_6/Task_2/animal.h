#ifndef ANIMAL_H
#define ANIMAL_H

#include <QChar>

struct Animal {
    int age;
    double weight;
    static const int nameLength = 32767;
    QChar type[32767];
    static const int daysInWeek = 7;
    int foodPerDay[7];
    bool wasFeedToday;
    QChar aClass;




};

#endif // ANIMAL_H
