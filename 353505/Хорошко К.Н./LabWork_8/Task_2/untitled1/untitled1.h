#ifndef UNTITLED1_H
#define UNTITLED1_H

#include <cmath>
#include <algorithm>
#include <QString>

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    void siftUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            std::swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void siftDown(int index) {
        int maxIndex = index;
        int left = leftChild(index);
        if (left < size && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        int right = rightChild(index);
        if (right < size && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }
        if (index != maxIndex) {
            std::swap(heap[index], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    int getLevel(int index) const {
        return static_cast<int>(std::log2(index + 1)) + 1;
    }

    void resize(int newCapacity) {
        int* newHeap = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
        capacity = newCapacity;
    }

public:
    MaxHeap(int cap) : capacity(cap), size(0) {
        heap = new int[capacity];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        heap[size] = value;
        siftUp(size);
        size++;
    }

    int extractMax() {
        if (size == 0) {
            throw std::out_of_range("Heap is empty");
        }
        int result = heap[0];
        heap[0] = heap[size - 1];
        size--;
        siftDown(0);
        return result;
    }

    bool isEmpty() const {
        return size == 0;
    }

    QString out = "";

    QString printHeap() const {
        out = "";
        for (int i = 0; i < size; ++i) {
            out = out + "Value: " + QString::number(heap[i]) + ", Level: " + QString::number(getLevel(i)) + "\n";
        }
        return out;
    }
};



#endif // UNTITLED1_H
