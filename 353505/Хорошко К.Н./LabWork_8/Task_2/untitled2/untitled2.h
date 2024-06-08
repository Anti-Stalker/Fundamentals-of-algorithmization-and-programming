#ifndef UNTITLED2_H
#define UNTITLED2_H

#include "untitled2_global.h"

#include <iostream>
#include <vector>
#include <cmath>

class MaxHeap {
private:
    std::vector<int> heap;

    void siftUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            std::swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void siftDown(int index) {
        int maxIndex = index;
        int left = leftChild(index);
        if (left < heap.size() && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        int right = rightChild(index);
        if (right < heap.size() && heap[right] > heap[maxIndex]) {
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

    int getLevel(int index) {
        return (std::floor(std::log2(index + 1)) + 1);
    }
public:
    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    int extractMax() {
        int result = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
        return result;
    }

    bool isEmpty() const {
        return heap.empty();
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

#endif // UNTITLED2_H
