//
// Created by darina on 5/29/24.
//

#ifndef TASK2_HEAPARRAY_H
#define TASK2_HEAPARRAY_H

#include <memory>
#include <vector>
#include "Heap.h"

class HeapArray : public Heap{
    int _capacity;
    int _size;
    std::unique_ptr<int[]> heap;

    void siftUp(int i);
    void siftDown(int i);
    void reserve();

    int findValue(int i, int value);

public:
    HeapArray();

    void add(int value) override;
    int getMax() override;
    void extractMax() override;
    void increaseElement(int i, int delta);
    void decreaseElement(int i, int delta);

    void increaseValue(int value, int delta) override;
    void decreaseValue(int value, int delta) override;

    int size() override;
    void clear() override;
    std::vector<int> getHeap() override;
};


#endif //TASK2_HEAPARRAY_H
