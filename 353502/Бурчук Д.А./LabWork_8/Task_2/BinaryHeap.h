#ifndef LAB8TASK2_BINARYHEAP_H
#define LAB8TASK2_BINARYHEAP_H

#include <algorithm>
#include <cmath>

class BinaryHeap {
protected:
    int _size;
public:
    BinaryHeap() = default;

    virtual void normalize() = 0;


};


#endif //LAB8TASK2_BINARYHEAP_H
