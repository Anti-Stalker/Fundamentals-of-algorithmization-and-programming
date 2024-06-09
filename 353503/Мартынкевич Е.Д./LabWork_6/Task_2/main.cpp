#include "mainwindow.h"

#include <iostream>

void QuickSort(QVector<int>& arr, int start, int end) {
    if (start == end) return;
    else if (end == start + 1 ) {
        return;
    }
    else if (end == start + 2) {
        if (arr[start] > arr[end - 1]) {
            std::swap(arr[start], arr[end - 1]);
        }
        return;
    }
    else {
        int x = arr[(start + end) / 2];
        int e = start, g = start, n = start + 1;
        bool firsttime = true;
        std::swap(arr[(start + end) / 2], arr[start]);

        for (; n < end; ++n) {
            if (arr[n] == x) {
                std::swap(arr[n], arr[g]);
                ++g;
            }
            else if (arr[n] > x) {
                std::swap(arr[n], arr[g]);
                std::swap(arr[e], arr[n]);
                ++e;
                ++g;
            }
            else {
                if (firsttime) {
                    ++g;
                    firsttime = false;
                }
            }
        }

        QuickSort(arr, start, e);
        QuickSort(arr, g, end);
    }
}

int main()
{
    QVector<int> a{1, 4, 7, 2, 8, 6, 3, 7};
    QuickSort(a, 0, 8);
    QuickSort(a, 0, 8);
    for (int i = 0; i < 8; ++i) {
        std::cout << a[i] << ' ';
    }
}
