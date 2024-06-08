#ifndef LAB4TASK1_SORTING_H
#define LAB4TASK1_SORTING_H

#include <iostream>
#include <vector>
#include <cmath>
#include <QCoreApplication>

#include "QWidget"
#include "QThread"
#include "QDebug"


class Sorting : public QObject {
Q_OBJECT
    void Divide(int*& array, std::vector<int>& divideSize, int& end);

    void ToBinaryHeap(int *array, int length, int root);

    void Partition(int *array, int left, int right);

    void Merge(int *array, int left, int middle, int right);
public:
    Sorting(QObject *parent = nullptr);

    void QuickSort(int *array, int start, int end);

    void HeapSort(int *array, int length);

    void MergeSort(int *array, int length);

    void InterpolationSort(int *array, int length);

    int BinSearch(int *array, int start, int end, int number);

    long long BinPow(long long number, long long power, int mod);

signals:
    void updateWiget();

    void sortingSetSelectedPosition(int);
};




#endif //LAB4TASK1_SORTING_H
