#ifndef INTERPOLATIONSORT_H
#define INTERPOLATIONSORT_H

#include <QtWidgets>

class InterpolationSort : public QObject
{
    Q_OBJECT
public:
    InterpolationSort();
    void sort(QVector<int> &Array);
    void interpolationSort(QVector<int> &Array, int l, int h, int min, int max);
signals:
    void ArrayChanged();
};


#endif // INTERPOLATIONSORT_H
