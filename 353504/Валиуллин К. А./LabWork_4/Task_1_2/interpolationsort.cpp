#include "interpolationsort.h"

InterpolationSort::InterpolationSort() {}

void InterpolationSort::sort(QVector<int> &Array)
{
    int min = *std::min_element(Array.begin(), Array.end());
    int max = *std::max_element(Array.begin(), Array.end());
    interpolationSort(Array, 0, Array.size() - 1, min, max);
}

void InterpolationSort::interpolationSort(QVector<int> &Array, int l, int h, int min, int max)
{
    if (l < h) {
        int pos = (int) ((double) (Array[l] - min) / (max - min)) * (h - l);
        pos = std::max(0, std::min(pos, h - l));
        int temp = Array[l + pos];
        int first = l;
        int end = h;
        while (first <= end) {
            while (Array[first] < temp) {
                emit ArrayChanged();
                first++;
            }
            while (Array[end] > temp) {
                emit ArrayChanged();
                end--;
            }

            if (first <= end) {
                std::swap(Array[first], Array[end]);
                emit ArrayChanged();
                first++;
                end--;
            }
        }
        interpolationSort(Array, l, end, min, temp);
        interpolationSort(Array, first, h, temp, max);
    }
}
