#ifndef LAB8TASK2_ARRAYBH_H
#define LAB8TASK2_ARRAYBH_H

#include "BinaryHeap.h"
#include <iostream>

class ArrayBH : public BinaryHeap {

    int *array;

    int _capacity;

    void compare(int *array, int root);

    void normalize() override;

    void resize(int new_size) {
        int *new_data = new int[new_size];
        for (int i = 0; i < _size; ++i) {
            new_data[i] = array[i];
        }
        array = new_data;
        _capacity = new_size;
    }

public:

    ArrayBH() : _capacity(1) {
        _size = 0;
        array = new int[1];
    };

    ArrayBH(int *array, int size);

    void add(int num);

    void print() {
        for (int i = 0; i < _size; ++i)
            std::cout << ' ' << array[i];
    }
};


#endif //LAB8TASK2_ARRAYBH_H
