#ifndef SORT_H
#define SORT_H
#include <QObject>
class Sort : public QObject
{
public:
    Sort(QObject* parent = nullptr);
    void heapify(double* nums, int n, int i);
    void heapsort(double* nums, int n);
};

#endif // SORT_H
