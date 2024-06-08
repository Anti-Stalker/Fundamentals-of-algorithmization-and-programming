#ifndef CLOTH_H
#define CLOTH_H
#include <QChar>


struct Cloth{
    int year;
    double cost;
    QChar size;
    bool has;
    static const int MAX_NAME_SIZE = 16;
    static const int MAX_POST_SIZE = 4;
    QChar name[MAX_NAME_SIZE];
    int post[MAX_POST_SIZE] = {0,0,0,0};
};

#endif // CLOTH_H
