//
// Created by u on 04.06.24.
//

#include <QVector>

#ifndef TASK2_ARRAYHEAP_H
#define TASK2_ARRAYHEAP_H

class ArrayHeap
{
private:
    QVector<int> heap;

    void heapifyUp(int cur)
    {
        if (cur == 1)
            return;

        if (heap[cur] > heap[cur / 2])
        {
            std::swap(heap[cur], heap[cur / 2]);
            heapifyUp(cur / 2);
        }
    }

    void heapifyDown(int cur)
    {
        if (cur * 2 < heap.size() && heap[cur * 2] > heap[cur])
        {
            std::swap(heap[cur], heap[cur * 2]);
            heapifyUp(cur * 2);
            return;
        }

        if (cur * 2 + 1 < heap.size() && heap[cur * 2 + 1] > heap[cur])
        {
            std::swap(heap[cur], heap[cur * 2 + 1]);
            heapifyUp(cur * 2 + 1);
            return;
        }
    }

public:
    void push(long x)
    {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    };

    long pop()
    {
        if (empty())
            return 0;

        long res = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
        return res;
    };

    bool empty()
    {
        return heap.size() < 2;
    }

    void clear()
    {
        heap.clear();
        heap.push_back(0);
    }

    QVector<int> &getHeap()
    {
        return heap;
    }

    ArrayHeap()
    {
        heap.push_back(0);
    }

    ~ArrayHeap() = default;
};

#endif //TASK2_ARRAYHEAP_H
