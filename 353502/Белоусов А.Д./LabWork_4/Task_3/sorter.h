#ifndef SORTER_H
#define SORTER_H

#include <cstdint>
#include <algorithm>

class Sorter
{
public:
    Sorter();
    static void HeapSort(int64_t* arr, int64_t size);
    static void QuickSort(int64_t* arr, int64_t size);
    static void MergeSort(int64_t* arr, int64_t size);
    static void InterpolationSort(int64_t* arr, int64_t size);
};

#endif // SORTER_H
