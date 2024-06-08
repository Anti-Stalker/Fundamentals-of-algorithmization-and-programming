#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

struct Motorcycle {
    int engineCapacity;
    double fuelConsumption;
    char category;
    bool is_electric;
    char brand[20];
    int mileageByYear[5];
};

#endif // MOTORCYCLE_H
