#ifndef HOUSE_H
#define HOUSE_H

struct House {
    int rooms;
    double area;
    char letterOFHouse;
    bool isTheHouseRentable;
    static const int sizeForAddress = 10;
    static const int sizeForPayments = 5;
    static char addres[sizeForAddress];
    static int paymentsForTheLastMonths[sizeForPayments];
};

#endif // HOUSE_H
