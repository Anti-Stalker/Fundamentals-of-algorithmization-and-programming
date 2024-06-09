#include "sortes.h"
#include "qthread.h"
#include <iostream>
#include <ostream>

Sortes::Sortes() {}

void Sortes::QuickSort(QVector<QGraphicsRectItem*>& arr, int start, int end) {
    if (start == end) return;
    else if (end == start + 1 ) {
        return;
    }
    else if (end == start + 2) {
        if (arr[start]->rect().height() > arr[end - 1]->rect().height()) {
            ChangePosition(arr, start, end - 1);
        }
        return;
    }
    else {
        QGraphicsRectItem* x = arr[(start + end) / 2];
        int e = start, g = start, n = start + 1;
        bool firsttime = true;
        ChangePosition(arr, (start + end) / 2, start);

        for (; n < end; ++n) {
            if (arr[n]->rect().height() == x->rect().height()) {
                ChangePosition(arr, n, g);
                ++g;
            }
            else if (arr[n]->rect().height() < x->rect().height()) {
                ChangePosition(arr, e, g);
                ChangePosition(arr, e, n);
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
/*
void QuickSort(std::vector<int>& arr, int start, int end) {
    if (start == end) return;
    else if (end == start + 1 ) {
        return;
    }
    else if (end == start + 2) {
        if (arr[start] > arr[end - 1]) std::swap(arr[start], arr[end - 1]);
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
            else if (arr[n] < x) {
                std::swap(arr[e], arr[g]);
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

            for (int i = start; i < end; ++i) {
                std::cout << arr[i] << ' ';
            }
            std::cout << std::endl;
        }

        for (int i = start; i < end; ++i) {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;

        QuickSort(arr, start, e);
        QuickSort(arr, g, end);
    }
}
*/
void Sortes::Heapify(QVector<QGraphicsRectItem*>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        //emit swapItems(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void Sortes::HeapSort(QVector<QGraphicsRectItem*>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        //emit swapItems(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

void Sortes::MergeSort(QVector<QGraphicsRectItem*>& arr, int start, int end) {
    if (start == end) return;
    else if (end == start + 1 ) {
        return;
    }
    else if (end == start + 2) {
        //if (arr[start]->rect().height() > arr[end - 1]->rect().height()) ChangePosition(arr[start], arr[end - 1]);
        return;
    }
    else {
        MergeSort(arr, start, (start + end) / 2);
        MergeSort(arr, (start + end) / 2, end);

        int f = start;
        int s = (start + end) / 2;
        QVector<QGraphicsRectItem*> parr = *new QVector<QGraphicsRectItem*>[end - start];

        for (int count = start; count < end; ++count) {
            if (f == (start + end) / 2) {
                parr[count - start]->setRect(arr[s]->rect().x(), arr[s]->rect().y(), arr[s]->rect().width(), arr[s]->rect().height());
                ++s;
            }
            else if (s == end) {
                parr[count - start]->setRect(arr[f]->rect().x(), arr[f]->rect().y(), arr[f]->rect().width(), arr[f]->rect().height());
                ++f;
            }
            else if (arr[f]->rect().height() < arr[s]->rect().height()) {
                parr[count - start]->setRect(arr[f]->rect().x(), arr[f]->rect().y(), arr[f]->rect().width(), arr[f]->rect().height());
                ++f;
            }
            else {
                parr[count - start]->setRect(arr[s]->rect().x(), arr[s]->rect().y(), arr[s]->rect().width(), arr[s]->rect().height());
                ++s;
            }
        }

        for (int count = start; count < end; ++count) {
            arr[count]->setRect(parr[count - start]->rect().x(), parr[count - start]->rect().y(), parr[count - start]->rect().width(), parr[count - start]->rect().height());
        }
    }
}

void Sortes::InterpolationSort(QVector<QGraphicsRectItem*>& arr) {
    int size = arr.size();
    if (size <= 1) return;

    int min = arr[0]->rect().height();
    int max = arr[0]->rect().height();
    for (int i = 1; i < size; i++) {
        if (arr[i]->rect().height() < min) min = arr[i]->rect().height();
        else if (arr[i]->rect().height() > max) max = arr[i]->rect().height();
    }

    if (min != max) {
        QVector<QVector<QGraphicsRectItem*>> buckets(size);
        int interpolation;
        for (int i = 0; i < size; i++) {
            interpolation = floor(((arr[i]->rect().height() - min) / static_cast<double>(max - min)) * (size - 1));
            buckets[interpolation].push_back(arr[i]);
        }

        int start = 0;
        for (int i = 0; i < size; i++) {
            if (buckets[i].size() > 1) {
                InterpolationSort(buckets[i]); // Recursion
            }
            for (int j = 0; j < buckets[i].size(); j++) {
                arr[start++]->rect().setHeight(buckets[i][j]->rect().height());
            }
        }
    }
}

int Sortes::InterpolationSearch(std::vector<int>& arr, int x) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right && x >= arr[left] && x <= arr[right]) {
        if (left == right) {
            if (arr[left] == x) return left;
            return -1;
        }
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            left = pos + 1;
        else
            right = pos - 1;
    }
    return -1; // элемент не найден
}

int Sortes::BinarySearch(std::vector<int>& arr, int x) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // элемент не найден
}

void Sortes::ChangePosition(QVector<QGraphicsRectItem*>& arr, int firstItem, int secondItem)
{
    std::swap(arr[firstItem], arr[secondItem]);
    arr[firstItem]->setPos(firstItem * 10, 0);
    arr[secondItem]->setPos(secondItem * 10, 0);
    arr[firstItem]->setBrush(Qt::red);
    arr[firstItem]->update();
    arr[secondItem]->setBrush(Qt::red);
    arr[secondItem]->update();
    QThread::msleep(100);
    arr[firstItem]->setBrush(Qt::black);
    arr[firstItem]->update();
    arr[secondItem]->setBrush(Qt::black);
    arr[secondItem]->update();
}
