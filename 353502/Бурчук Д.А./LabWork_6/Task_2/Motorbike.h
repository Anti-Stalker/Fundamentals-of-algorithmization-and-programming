#ifndef LAB6TASK1_MOTORBIKE_H
#define LAB6TASK1_MOTORBIKE_H

#include "QString"
#include "QStringList"

struct Motorbike {
    int mileage;
    double max_speed;
    char type;
    bool isWoundUp;
    char *brand;
    size_t lastModelNumber;
    explicit Motorbike(QString init_str);
    Motorbike() = default;
    ~Motorbike();
    QString print();

    Motorbike& operator=(const Motorbike& motorbike);
};


#endif //LAB6TASK1_MOTORBIKE_H
