#pragma once

#ifndef BINARYHEAP_BINARY_HEAP_H
#define BINARYHEAP_BINARY_HEAP_H

#include "linkedlist.h"
#include <iostream>
#include <vector>

class binary_heap_list
{
private:
    linkedlist list;

public:
    size_t heap_size()
    {
        return list.size();
    }

    void add(int arg)
    {
        list.push_back(arg);
        int index = this->heap_size() - 1;
        int parent = (index - 1) / 2;
        while (index > 0 && list[parent] < list[index])
        {
            int tmp = list[index];
            list[index] = list[parent];
            list[parent] = tmp;
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void show_heap()
    {
        std::cout << "Heap:\n";
        for (int i = 0; i < list.size(); ++i)
        {
            std::cout << list[i] << " ";
        }
        std::cout << '\n';
    }

    void heapify(int i)
    {
        int leftChild;
        int rightChild;
        int largestChild;

        for (;;)
        {
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            largestChild = i;

            if (leftChild < heap_size() && list[leftChild] > list[largestChild])
            {
                largestChild = leftChild;
            }

            if (rightChild < heap_size() && list[rightChild] > list[largestChild])
            {
                largestChild = rightChild;
            }

            if (largestChild == i)
            {
                break;
            }

            int temp = list[i];
            list[i] = list[largestChild];
            list[largestChild] = temp;
            i = largestChild;
        }
    }

    int getMax()
    {
        int result = list[0];
        list[0] = list[this->heap_size() - 1];
        list.pop_back();
        heapify(0);
        return result;
    }
};

class binary_heap_array
{
private:
    int list[9999];
    size_t sz = 0;

public:
    size_t heap_size()
    {
        return sz;
    }

    void add(int arg)
    {
        list[sz] = arg;
        ++sz;
        int index = this->heap_size() - 1;
        int parent = (index - 1) / 2;
        while (index > 0 && list[parent] < list[index])
        {
            int tmp = list[index];
            list[index] = list[parent];
            list[parent] = tmp;
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void show_heap()
    {
        for (int i = 0; i < heap_size(); ++i)
        {
            std::cout << list[i] << " ";
        }
    }

    void heapify(int i)
    {
        int leftChild;
        int rightChild;
        int largestChild;

        for (;;)
        {
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            largestChild = i;

            if (leftChild < heap_size() && list[leftChild] > list[largestChild])
            {
                largestChild = leftChild;
            }

            if (rightChild < heap_size() && list[rightChild] > list[largestChild])
            {
                largestChild = rightChild;
            }

            if (largestChild == i)
            {
                break;
            }

            int temp = list[i];
            list[i] = list[largestChild];
            list[largestChild] = temp;
            i = largestChild;
        }
    }

    void heap_sort(std::vector<int> &vec)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            this->add(vec[i]);
        }
        for (int i = 0; i < vec.size(); ++i)
        {
            vec[i] = list[i];
        }
    }

    int getMax()
    {
        if (sz == 0)
        {
            throw std::runtime_error("no elements");
        }
        int result = list[0];
        list[0] = list[this->heap_size() - 1];
        --sz;
        heapify(0);
        return result;
    }
};

#endif // BINARYHEAP_BINARY_HEAP_H
