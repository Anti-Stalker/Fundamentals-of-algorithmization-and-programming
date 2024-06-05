#ifndef PRODUCTSORT_H
#define PRODUCTSORT_H

#include "product.h"

class ProductSort
{
public:
    ProductSort();
    static void timsortIncrease(QVector<Product*> *array);
    static void timsortDecrease(QVector<Product*> *array);
    static void threeWayQuickSortIncrease(QVector<Product*> *array, int low, int high);
    static void threeWayQuickSortDecrease(QVector<Product*> *array, int low, int high);
private:
    static void insertionSortIncrease(QVector<Product*> *array, int start_index, int end_index);
    static void insertionSortDecrease(QVector<Product*> *array, int start_index, int end_index);
    static void mergeIncrease(QVector<Product*> *array, int start_index, int mid, int end_index);
    static void mergeDecrease(QVector<Product*> *array, int start_index, int mid, int end_index);
    static const int RUN = 64;
};

#endif // PRODUCTSORT_H
