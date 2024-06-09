#ifndef BITSET_H
#define BITSET_H
#include "cstdint"
#include "cstddef"
#include "QString"



template <int N>
class BitSet
{
private:
    uint64_t data;

    uint64_t get_data() {
        return data & ((1 << N) - 1);
    }

public:
    BitSet() {
        if (N > 64) {
              throw std::out_of_range("Index out from range");
            }
        else {
            data = 0;
        }
    };

    explicit BitSet(uint64_t c) {
        if (N > 64) {
              throw std::out_of_range("Index out from range");
            }
        else {
            data = c;
        }
    };

    bool all() {
        return get_data() == ((1<<N) - 1);
    }

    bool any () {
        return get_data();
    }

    int count() {
        int count = 0;
        uint64_t d = get_data();
        for (int i = 0; i < N; i++) {
            count += d&1;
            d = d >> 1;
        }
        return count;
    }

    void flip () {
        data = ~get_data();
    }

    void flip (size_t pos) {
        uint64_t mask = 1<<pos;
        if (get_data() & mask) {
            reset(pos);
        }
        else {
            set(pos);
        }
    }

    bool none() {
        return get_data();
    }

    void reset () {
        data = 0;
    }

    void reset (size_t pos) {
        uint64_t mask = ~(1<<pos);
        data = get_data() & mask;
    }

    void set() {
        data = (1<<N) - 1;
    }

    void set(size_t pos) {
        uint64_t mask = (1<<pos);
        data = get_data() | mask;
    }

    int size() {
        return N;
    }

    bool test(size_t pos) {
        return data & (1<<N);
    }

    QString to_string() {
        QString res = "";
        uint64_t d = get_data();
        for (int i = 0; i < N; i++) {
            res += (d&1?"1":"0");
            d = d >> 1;
        }
        return res;
    }

    uint64_t to_ullong() {
        uint64_t count = 0;
        uint64_t d = get_data();
        for (int i = 0; i < N; i++) {
            count += d&1;
            d = d >> 1;
        }
        return count;
    }

    uint32_t to_ulong() {
        uint32_t count = 0;
        uint64_t d = get_data();
        for (int i = 0; i < N; i++) {
            count += d&1;
            d = d >> 1;
        }
        return count;
    }

    bool operator[](int pos) {
        return get_data() & (1<<pos);
    }

    BitSet<N> operator&(BitSet<N> &other) {
        return BitSet<N>(get_data() & other.get_data());
    }

    BitSet<N> operator|(BitSet<N> &other) {
        return BitSet<N>(get_data() | other.get_data());
    }

    BitSet<N> operator~() {
        return BitSet<N>(~get_data());
    }
};

#endif // BITSET_H
