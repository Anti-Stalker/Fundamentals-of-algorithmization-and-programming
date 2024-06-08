#include "bitbuffer.h"

BitBuffer::BitBuffer()
    : QVector<bool>() {}


void BitBuffer::appendBits(uint val, int len) {
    for (int i = len - 1; i >= 0; i--)
        this->push_back(((val >> i) & 1) != 0);
}

