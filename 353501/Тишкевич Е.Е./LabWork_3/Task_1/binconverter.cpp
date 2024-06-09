#include "binconverter.h"

QString BinConverter::getSign() { return sign; }
QString BinConverter::getExponent() { return exponent; }
QString BinConverter::getMantissa() { return mantissa; }
QString BinConverter::getBinary() { return s_Value; }

BinConverter::BinConverter(double val){
    Bits bits;
    bits.value = val;

    sign = QString::number(bits.raw.sign);
    exponent = getBinaryString(bits.raw.exponent, 11);
    mantissa = getBinaryString(bits.raw.mantissa, 52);

    s_Value = sign + exponent + mantissa;
}

QString BinConverter::getBinaryString(unsigned long long n, int bits) {
    if (bits == 0)
    {
        return "";
    }
    else
    {
        return getBinaryString(n >> 1, bits - 1) + QString::number(n & 1);
    }
}
