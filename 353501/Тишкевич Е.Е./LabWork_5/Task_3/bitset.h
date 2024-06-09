#ifndef BITSET_H
#define BITSET_H

#include <QString>

class BitSet {
private:
    static const int BITS_PER_BLOCK = 16;
    static const int BLOCK_SIZE = sizeof(unsigned short) * BITS_PER_BLOCK;

    unsigned short* data;
    int size;

public:
    explicit BitSet(int size);
    ~BitSet();

    int getSize() const;

    void set(int pos);
    void set();

    void reset(int pos);
    void reset();

    bool test(int pos) const;

    void flip(int pos);
    void flip();

    bool all() const;
    bool any() const;
    int count() const;
    bool none() const;
    QString to_string() const;
    unsigned long long to_ullong() const;
    unsigned long to_ulong() const;

    bool operator[](int pos) const;
    bool& operator[](int pos);
};

#endif // BITSET_H
