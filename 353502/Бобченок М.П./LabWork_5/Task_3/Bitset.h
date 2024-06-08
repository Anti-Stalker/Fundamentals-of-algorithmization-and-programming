//
// Created by u on 29.05.24.
//

#ifndef TASK3_BITSET_H
#define TASK3_BITSET_H

#include <iostream>
#include <climits>

template <size_t N>
class Bitset
{
private:
    u_int64_t *data;

public:
    size_t size()
    {
        return N;
    }

    bool all()
    {
        for (size_t i = 0; i < (N + 63) / 64 - 1; i++)
            if (data[i] != ULLONG_MAX)
                return false;

        return (data[(N + 63) / 64 - 1] & ((1ULL << (N % 64)) - 1)) == ((1ULL << (N % 64)) - 1);
    }

    bool any() const
    {
        for (size_t i = 0; i < (N + 63) / 64; ++i)
            if (data[i] != 0)
                return true;

        return false;
    }

    bool none() const
    {
        return !any();
    }

    size_t count() const
    {
        size_t cnt = 0;
        for (size_t i = 0; i < (N + 63) / 64; ++i)
            cnt += __builtin_popcount(data[i]);

        return cnt;
    }

    void flip()
    {
        for (size_t i = 0; i < (N + 63) / 64; ++i)
            data[i] = ~data[i];
    }

    void flip(size_t i)
    {
        if (i >= N)
            throw std::out_of_range("Index out of range");

        data[i / 64] ^= (1ULL << (i % 64));
    }

    void reset()
    {
        for (size_t i = 0; i < (N + 63) / 64; ++i)
            data[i] = 0;
    }

    void reset(size_t i)
    {
        if (i >= N)
            throw std::out_of_range("Index out of range");

        data[i / 64] &= ~(1ULL << (i % 64));
    }

    void set()
    {
        for (size_t i = 0; i < (N + 63) / 64 - 1; ++i)
            data[i] = ULLONG_MAX;

        data[(N + 63) / 64 - 1] = ULLONG_MAX;
    }

    void set(size_t i)
    {
        if (i >= N)
            throw std::out_of_range("Index out of range");

        data[i / 64] |= (1ULL << (i % 64));
    }

    bool test(size_t i) const
    {
        if (i >= N)
            throw std::out_of_range("Index out of range");

        return (data[i / 64] & (1ULL << (i % 64))) != 0;
    }

    std::string to_string() const
    {
        std::string result;
        result.reserve(N);
        for (size_t i = 0; i < N; ++i)
            result += (test(i)) ? '1' : '0';

        return result;
    }

    u_int64_t to_ullong() const
    {
        u_int64_t result = 0;
        for (size_t i = 0; i < (N < 64 ? N : 64); ++i)
            if (test(i))
                result |= (1ULL << i);

        return result;
    }

    u_int32_t to_ulong() const
    {
        u_int32_t result = 0;
        for (size_t i = 0; i < (N < 32 ? N : 32); ++i)
            if (test(i))
                result |= (1UL << i);

        return result;
    }

    Bitset &operator =(const Bitset &other) noexcept
    {
        if (this != &other)
        {
            for (size_t i = 0; i < (N + 63) / 64; ++i)
                data[i] = other.data[i];
        }

        return *this;
    }

    Bitset &operator =(Bitset &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }

        return *this;
    }

    bool operator[](size_t i)
    {
        if (i >= N)
            throw std::out_of_range("out of range");

        return (data[i / 64] & (1ULL << (i % 64))) != 0;
    }

    Bitset &operator-()
    {
        for (size_t i = 0; i < (N + 63) / 64; i++)
            data[i] = ~data[i];

        return *this;
    }

    Bitset operator&(const Bitset &other)
    {
        Bitset result;
        for (size_t i = 0; i < (N + 63) / 64; ++i)
            result.data_[i] = data[i] & other.data_[i];

        return result;
    }

    Bitset() : data(new u_int64_t[(N + 63) / 64])
    {
        reset();
    }

    Bitset(const Bitset &other) : data(new u_int64_t[(N + 63) / 64])
    {
        for (size_t i = 0; i < (N + 63) / 64; ++i)
            data[i] = other.data_[i];
    }

    Bitset(Bitset &&other) noexcept : data(other.data_)
    {
        other.data_ = nullptr;
    }

    ~Bitset()
    {
        delete[] data;
    }
};

#endif //TASK3_BITSET_H
