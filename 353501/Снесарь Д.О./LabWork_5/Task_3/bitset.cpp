#include "bitset.h"
#include <QDebug>
Bitset::Bitset(int size): capacity(size)
{
    int arrSize = (BITS_IN_BLOCK + size - 1) / BITS_IN_BLOCK; //округление вверх
    data = new unsigned short[arrSize];

    for (int i = 0; i < arrSize; ++i)
        data[i] = 0;


}

Bitset::~Bitset()
{
    delete[] data;
}

bool Bitset::operator[](int pos) const
{
    return test(pos);
}

bool& Bitset::operator[](int pos) {

    if (pos < 0 || pos >= capacity) {
         throw std::out_of_range("Index out of range(gg wp)");
    }
    return (bool&)(data[pos / BITS_IN_BLOCK] |= (1 << (pos % BITS_IN_BLOCK)));
}

Bitset Bitset::operator~() const {
    Bitset result(capacity);
    int blockCapacity = (capacity + BITS_IN_BLOCK - 1) / BITS_IN_BLOCK;
    for (int i = 0; i < blockCapacity; ++i) {
        result.data[i] = ~data[i];
    }
    return result;
}

Bitset Bitset::operator&(const Bitset& other) const {
    if (other.size() != this->size())
         throw std::out_of_range("Invalid size(gg wp)");
    Bitset result(capacity);
    int blockCount = (capacity + BITS_IN_BLOCK - 1) / BITS_IN_BLOCK;
    for (int i = 0; i < blockCount; ++i) {
        result.data[i] = data[i] & other.data[i];
    }
    return result;
}

Bitset Bitset::operator|(const Bitset& other) const {
    if (other.size() != this->size())
        throw std::out_of_range("Invalid size(gg wp)");
    Bitset result(capacity);
    int blockCount = (capacity + BITS_IN_BLOCK - 1) / BITS_IN_BLOCK;
    for (int i = 0; i < blockCount; ++i) {
        result.data[i] = data[i] | other.data[i];
    }
    return result;
}



bool Bitset::test(int pos) const {
    if (pos < 0 || pos >= capacity)
        throw std::out_of_range("Index out of range(gg wp)");
    return (data[pos / BITS_IN_BLOCK] & (1 << (pos % BITS_IN_BLOCK)));
}


int Bitset::size() const
{
    return capacity;
}


void Bitset::set(int pos) {
    if (pos >= 0 && pos < capacity)
        data[pos / BITS_IN_BLOCK] |= (1 << (pos % BITS_IN_BLOCK));
}

void Bitset::set() {
    for (int i = 0; i < capacity; ++i)
        data[i / BITS_IN_BLOCK] |= (1 << (i % BITS_IN_BLOCK));
}

void Bitset::reset(int pos) {
    if (pos >= 0 && pos < capacity)
        data[pos / BITS_IN_BLOCK] &= ~(1 << (pos % BITS_IN_BLOCK));
}

void Bitset::reset() {
    for (int i = 0; i < capacity; ++i)
        data[i / BITS_IN_BLOCK] &= ~(1 << (i % BITS_IN_BLOCK));
}



void Bitset::flip(int pos) {
    if (pos >= 0 && pos < capacity)
        data[pos / BITS_IN_BLOCK] ^= (1 << (pos % BITS_IN_BLOCK));
}

void Bitset::flip() {
    for (int i = 0; i <capacity; ++i) {
        data[i / BITS_IN_BLOCK] ^= (1 << (i % BITS_IN_BLOCK));
    }
}


bool Bitset::all() const {
    int fullSizedBlocks = capacity / BITS_IN_BLOCK;
    int partialSizedBlock = capacity % BITS_IN_BLOCK;
    unsigned short fullBlockMask = (1 << BITS_IN_BLOCK) - 1;
    unsigned short partialBlockMask = (1 << partialSizedBlock) - 1;

    for (int i = 0; i < fullSizedBlocks; ++i) {
        if (data[i] != fullBlockMask) {
            return false;
        }
    }

    if (partialSizedBlock > 0 && data[fullSizedBlocks] != partialBlockMask) {
        return false;
    }

    return true;
}

bool Bitset::any() const {
    int totalBlocks = (capacity + BITS_IN_BLOCK - 1) / BITS_IN_BLOCK;
    for (int i = 0; i < totalBlocks; ++i) {
        if (data[i] != 0) {
            return true;
        }
    }
    return false;
}

bool Bitset::none() const
{
    return !any();
}

int Bitset::count() const {
    int count = 0;
    int totalBlocks = (capacity + BITS_IN_BLOCK - 1) / BITS_IN_BLOCK;
    for (int i = 0; i < totalBlocks; ++i) {
        unsigned short value = data[i];
        while (value) {
            count += (value & 1);
            value >>= 1;
        }
    }
    return count;
}

QString Bitset::to_string() const {
    QString s;
    for (int i = 0; i < capacity; i++) {
        if (test(i)) {
            s += '1';
        } else {
            s += '0';
        }
    }
    //std::reverse(s.begin(), s.end());
    return s;
}

unsigned long Bitset::to_ulong() const {
    unsigned long value = 0;
    for (int i = capacity - 1; i >= 0; --i) {
        if (test(i)) {
            value |= (1UL << i);
        }
    }
    return value;
}

unsigned long long Bitset::to_ullong() const {
    unsigned long long value = 0;
    for (int i = capacity - 1; i >= 0; --i) {
        if (test(i)) {
            value |= (1ULL << i);
        }
    }
    return value;
}

