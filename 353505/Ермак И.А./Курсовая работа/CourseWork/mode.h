#ifndef MODE_H
#define MODE_H

#include <QVector>
class Mode final
{
public:
    static const Mode NUMERIC;
    static const Mode ALPHANUMERIC;
    static const Mode BYTE;
    static const Mode KANJI;
    static const Mode ECI;
public:
    int getModeBits() const;
    int numCharCountBits(int) const;
private:
    int modeBits;
    int numBitsCharCount[3];
private:
    Mode(int, int, int, int);
};

#endif // MODE_H
