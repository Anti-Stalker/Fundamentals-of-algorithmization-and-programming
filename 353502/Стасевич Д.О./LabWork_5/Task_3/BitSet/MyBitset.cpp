//
// Created by darina on 5/24/24.
//

#include "MyBitset.h"

MyBitset::MyBitset() {
    _bits.resize(1);
    sz = size();
    cap = _bits.size();
    _reversed_bits.resize(cap);
    reset();
}

MyBitset::MyBitset(int size) {
    sz = size;
    _bits.resize((size + 31) / 32);
    cap = _bits.size();
    _reversed_bits.resize(cap);
    for(int pos = sz; pos < size; pos ++)
    {
        reset(pos);
    }
}

MyBitset::MyBitset(const MyBitset &other) {
    _bits = other._bits;
    _reversed_bits = other._reversed_bits;
    sz = other.sz;
    cap = other.cap;
    cnt_1 = other.cnt_1;
    cnt_0 = other.cnt_0;
}


bool MyBitset::get(size_t pos) {
    pos = sz - 1 - pos;
    int t = pos / 32;
    int real_pos = pos - t * 32;
    return ((_bits[t] >> real_pos) & 1);
}

bool MyBitset::operator[](size_t pos) const {
    pos = sz - pos - 1;
    int t = pos / 32;
    int real_pos = pos - t * 32;
    return ((_bits[t] >> real_pos) & 1);
}

void MyBitset::resize(size_t newSize) {
    _bits.resize((newSize + 31) / 32);
    _reversed_bits.resize((newSize + 31) / 32);
    for(int i = cap; cap < _bits.size() / 32; i ++)
    {
        _bits[i] = 0;
        _reversed_bits[i] = 4294967295;
    }
    sz = newSize;
    cap = _bits.size();
}

bool MyBitset::all() {
    return (cnt_0 == 0);
}

bool MyBitset::any() {
    return (cnt_1 != 0);
}

size_t MyBitset::count() {
    return cnt_1;
}

void MyBitset::flip() {
    std::swap(_bits, _reversed_bits);
    std::swap(cnt_1, cnt_0);
}

bool MyBitset::none() {
    return (cnt_1 == 0);
}

void MyBitset::reset() {
    for(int i = 0; i < cap; i ++)
    {
        _bits[i] = 0;
        _reversed_bits[i] = 4294967295;
    }
    cnt_1 = 0;
    cnt_0 = sz;
}

void MyBitset::reset(size_t pos) {
    pos = sz - 1 - pos;
    int t = pos / 32;
    int real_pos = pos - t * 32;
    if(((_bits[t] >> real_pos) & 1) == 0 && ((_reversed_bits[t] >> real_pos) & 1) == 1)
        return;
    if(((_bits[t] >> real_pos) & 1) == 1)
    {
        _bits[t] -= (1 << real_pos);
        _reversed_bits[t] += (1 << real_pos);
        cnt_1 --;
        cnt_0 ++;
        return;
    }
    if(((_reversed_bits[t] >> real_pos) & 1) == 0)
    {
        _reversed_bits[t] += (1 << real_pos);
        cnt_0 ++;
        return;
    }
}

void MyBitset::set() {
    for(int i = 0; i < cap; i ++)
    {
        _bits[i] = 4294967295;
        _reversed_bits[i] = 0;
    }
    cnt_1 = sz;
    cnt_0 = 0;
}

void MyBitset::set(size_t pos) {
    pos = sz - 1 - pos;
    int t = pos / 32;
    int real_pos = pos - t * 32;
    if(((_bits[t] >> real_pos) & 1) == 0)
    {
        _bits[t] += (1 << real_pos);
        _reversed_bits[t] -= (1 << real_pos);
        cnt_1 ++;
        cnt_0 --;
    }
}

size_t MyBitset::size() {
    return sz;
}

bool MyBitset::test(size_t pos) {
    pos = sz - 1 - pos;
    int t = pos / 32;
    int real_pos = pos - t * 32;
    return (((_bits[t] >> real_pos) & 1) == 1);
}

std::string MyBitset::to_string() {
    std::string ans;
    for(int i = sz - 1; i >= 0; i --)
    {
        ans += std::to_string(test(i));
    }
    return ans;
}

unsigned long long MyBitset::to_ullong()
{
    return static_cast<unsigned long long>(count());
}

unsigned long MyBitset::to_ulong()
{
    return static_cast<unsigned long>(count());
}
