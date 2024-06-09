#ifndef BITSET_H
#define BITSET_H

#include <QString>

class Bitset
{
private:
    static const int BITS_IN_BLOCK = 16;
    static const int BLOCK_SIZE = sizeof(unsigned short) * BITS_IN_BLOCK;
    unsigned short* data;
    int capacity;

public:
    explicit Bitset(int);
    ~Bitset();

    bool operator[](int) const;
    bool &operator[](int);
    Bitset operator~() const;
    Bitset operator&(const Bitset& other) const;
    Bitset operator|(const Bitset& other) const;

    bool test(int) const;
    int size() const;
    void set(int position);
    void set();
    void reset(int position);
    void reset();
    void flip(int position);
    void flip();
    bool all() const;
    bool any() const;
    bool none() const;
    int count() const;

    QString to_string() const;
    unsigned long long to_ullong() const;
    unsigned long to_ulong() const;


};

#endif // BITSET_H
