#ifndef HOUSE_H
#define HOUSE_H

struct House
{
    int rooms;
    double area;
    char letterOFHouse;
    bool isTheHouseRentable;
    char addres[12];
    int paymentsForTheLastMonths[3];
};

#endif // HOUSE_H
