#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <cstdint>
#include <iostream>

class Algorithms
{
public:
    Algorithms();
    static int64_t Hanoi(size_t from, size_t to, size_t count);
};

#endif // ALGORITHMS_H
