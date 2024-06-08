#include "ArrayBH.h"

void ArrayBH::normalize() {
    for (int i = _size / 2; i >= 0; --i) {
        compare(array, i);
    }
}

void ArrayBH::compare(int *array, int root) {
    int maxElementIndex = root;
    int firstSubRoot = root * 2 + 1;
    int secondSubRoot = root * 2 + 2;

    if (firstSubRoot < _size && array[firstSubRoot] > array[maxElementIndex]) { maxElementIndex = firstSubRoot; }
    if (secondSubRoot < _size && array[secondSubRoot] > array[maxElementIndex]) { maxElementIndex = secondSubRoot; }

    if (root != maxElementIndex) {
        std::swap(array[root], array[maxElementIndex]);

        compare(array, maxElementIndex);
    }
}

ArrayBH::ArrayBH(int *array, int size) : _capacity(std::pow(2, static_cast<int>(std::log2(size)) + 1)) {
    this->array = new int[_capacity];
    for (int i = 0; i < size; ++i) {
        this->array[i] = array[i];
    }
    this->_size = size;
    this->array = array;
    normalize();
}

void ArrayBH::add(int num) {
    if (_size == _capacity) {
        resize(_capacity * 2);
    }
    array[_size++] = num;
    normalize();
}
