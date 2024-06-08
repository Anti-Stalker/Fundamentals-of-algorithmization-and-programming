#ifndef PLANT_H
#define PLANT_H

#include <QString>

constexpr short MAX_ANOUNT_PLANT = 10;

struct Plant
{
    int age;
    double height;
    char vitamin;
    bool isFlowering;
    static QString name[MAX_ANOUNT_PLANT];
    static int nutrients[MAX_ANOUNT_PLANT];

    Plant();
    Plant(int age, double height, char vitamin, bool isFlowering);
    QString plantToString();
    void clear();
};

#endif // PLANT_H
