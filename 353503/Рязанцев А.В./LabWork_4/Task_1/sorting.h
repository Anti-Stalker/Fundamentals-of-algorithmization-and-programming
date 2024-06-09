#ifndef SORTING_H
#define SORTING_H

#include "funcsforheap.h"
#include "funcsforquick.h"
#include "vector"

void HeapSort(int *arr, int size, int& counter);
void QuickSort(int *arr, int l, int r, int& counter);
void MergeSort(int *arr, int l, int r, int size, int& counter);

#endif // SORTING_H
