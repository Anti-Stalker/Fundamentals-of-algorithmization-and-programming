#ifndef BINCONVERTER_H
#define BINCONVERTER_H

#include <QString>

class BinConverter {

    union Bits {
        double value;
        struct {
            unsigned long long mantissa : 52;
            unsigned long long exponent : 11;
            unsigned long long sign : 1;
        } raw;
    };

public:
    BinConverter(double val);

    QString getSign();
    QString getMantissa();
    QString getExponent();
    QString getBinary();

private:
    QString sign;
    QString mantissa;
    QString exponent;
    QString s_Value;
    QString getBinaryString(unsigned long long n, int bits);
};

#endif // BINCONVERTER_H
