#ifndef BITBUFFER_H
#define BITBUFFER_H


#include <cstdint>
#include <QVector>

class BitBuffer final : public QVector<bool>
{
public:
    BitBuffer();
    void appendBits(uint val, int len);
};

#endif // BITBUFFER_H
