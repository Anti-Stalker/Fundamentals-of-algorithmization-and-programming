#ifndef SORTS_H
#define SORTS_H

class Sorts
{
public:
    static void heapSort();
    static void quickSort();
    static void mergeSort();

private:
    static void hepify();
    static void partition();
    static void merge();
};

#endif // SORTS_H
