#ifndef CLOTH_H
#define CLOTH_H
#include <QChar>


struct Cloth{
    int year;
    double cost;
    QChar size;
    bool has;
    static const int MAX_STORE_SIZE = 16;
    static const int MAX_POST_SIZE = 4;
    QChar store[MAX_STORE_SIZE];
    int post[MAX_POST_SIZE] = {0,0,0,0};
};

#endif // CLOTH_H
