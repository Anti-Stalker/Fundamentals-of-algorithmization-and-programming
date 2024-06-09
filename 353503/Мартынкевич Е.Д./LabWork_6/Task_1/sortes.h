#ifndef SORTES_H
#define SORTES_H

#include "qgraphicsitem.h"
#include <vector>
#include <cmath>
#include <QPropertyAnimation>
#include <QBrush>

class Sortes
{
public:
    Sortes();
    void QuickSort(QVector<QGraphicsRectItem*>& arr, int start, int end);
    void HeapSort(QVector<QGraphicsRectItem*>& arr, int n);
    void Heapify(QVector<QGraphicsRectItem*>& arr, int n, int i);
    void MergeSort(QVector<QGraphicsRectItem*>& arr, int start, int end);
    void InterpolationSort(QVector<QGraphicsRectItem*>& arr);
    int InterpolationSearch(std::vector<int>& arr, int x);
    int BinarySearch(std::vector<int>& arr, int x);
    void ChangePosition(QVector<QGraphicsRectItem*>& arr, int firstItem, int secondItem);
signals:
    //void swapItems(QGraphicsRectItem* first, QGraphicsRectItem* second);
};

#endif // SORTES_H
