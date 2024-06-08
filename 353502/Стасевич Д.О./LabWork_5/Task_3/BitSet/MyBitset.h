//
// Created by darina on 5/24/24.
//

#ifndef TASK3_MYBITSET_H
#define TASK3_MYBITSET_H

#include <vector>
#include <string>
#include <iostream>

class MyBitset {
private:
    std::vector<int> _bits;
    std::vector<int> _reversed_bits;
    size_t sz = 1;
    size_t cap = 32;
    int cnt_0, cnt_1;

public:
    MyBitset();
    explicit MyBitset(int size);
    MyBitset(MyBitset const &other);

    void set(size_t pos);
    bool get(size_t pos);

    bool operator[](size_t pos) const;

    void resize(size_t newSize);
    bool all();
    bool any();
    size_t count();
    void flip();
    bool none();
    void reset();
    void reset(size_t pos);
    void set();
    size_t size();
    bool test(size_t pos);
    std::string to_string();
    unsigned long long to_ullong();
    unsigned long to_ulong();

    MyBitset operator~() const {
        auto res = MyBitset(*this);
        res.flip();
        return res;
    }

    MyBitset operator& (const MyBitset &other) const {
        auto res = MyBitset(other);
        res.cnt_0 = 0;
        res.cnt_1 = 0;
        for (int i = 0; i < res.cap; i++)
        {
            res._bits[i] = res._bits[i] & this->_bits[i];
            res._reversed_bits[i] = res._reversed_bits[i] | this->_reversed_bits[i];
            res.cnt_1 += __builtin_popcount(res._bits[i]);
        }
        res.cnt_0 = res.sz - res.cnt_1;
        return res;
    }

    MyBitset operator| (const MyBitset &other) const {
        auto res = MyBitset(other);
        res.cnt_0 = 0;
        res.cnt_1 = 0;
        for (int i = 0; i < res.cap; i++)
        {
            std::cout << res._bits[i] << " " << this->_bits[i] << std::endl;
            res._bits[i] = res._bits[i] | this->_bits[i];
            res._reversed_bits[i] = res._reversed_bits[i] & this->_reversed_bits[i];
            res.cnt_1 += __builtin_popcount(res._bits[i]);
            std::cout << "res i " << res._bits[i] << std::endl;
        }
        res.cnt_0 = res.sz - res.cnt_1;
        return res;
    }

    MyBitset operator^ (const MyBitset &other) const {
        auto res = MyBitset(other);
        res.cnt_0 = 0;
        res.cnt_1 = 0;
        for (int i = 0; i < res.cap; i++)
        {
            res._bits[i] = res._bits[i] ^ this->_bits[i];
            res._reversed_bits[i] = (res._reversed_bits[i] + this->_reversed_bits[i] + 1) % 2;
            res.cnt_1 += __builtin_popcount(res._bits[i]);
        }
        res.cnt_0 = res.sz - res.cnt_1;

        return res;
    }
};


#endif //TASK3_MYBITSET_H
