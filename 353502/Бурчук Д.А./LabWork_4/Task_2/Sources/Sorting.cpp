#include "../Headers/Sorting.h"

Sorting::Sorting(QObject *parent) : QObject(parent) {}

void Sorting::QuickSort(int *array, int start, int end) {
    int firstIndex = start;
    int secondIndex = end;

    int middle = array[(start + end) / 2];

    do {
        while (array[firstIndex] < middle) { ++firstIndex; }
        while (array[secondIndex] > middle) { --secondIndex; }

        if (firstIndex <= secondIndex) {
            std::swap(array[firstIndex], array[secondIndex]);
            emit sortingSetSelectedPosition(firstIndex);
            emit updateWiget();
            QCoreApplication::processEvents();
            emit sortingSetSelectedPosition(secondIndex);
            emit updateWiget();
            QCoreApplication::processEvents();
            QThread::msleep(10);
            ++firstIndex;
            --secondIndex;
        }

    } while (firstIndex <= secondIndex);

    if (start < secondIndex) { QuickSort(array, start, secondIndex); }
    if (firstIndex < end) { QuickSort(array, firstIndex, end); }
    // Использовал индексы начала и конца массива в рекурсивных вызовах
    emit sortingSetSelectedPosition(-1);
    emit updateWiget();
    QCoreApplication::processEvents();
    QThread::msleep(10);
}



void Sorting::ToBinaryHeap(int *array, int length, int root) {
    int maxElementIndex = root;
    int firstSubRoot = root * 2 + 1;
    emit sortingSetSelectedPosition(maxElementIndex);
    int secondSubRoot = root * 2 + 2;

    if (firstSubRoot < length && array[firstSubRoot] > array[maxElementIndex]) { maxElementIndex = firstSubRoot; }
    if (secondSubRoot < length && array[secondSubRoot] > array[maxElementIndex]) { maxElementIndex = secondSubRoot; }

    if (root != maxElementIndex) {
        std::swap(array[root], array[maxElementIndex]);

        ToBinaryHeap(array, length, maxElementIndex);
    } else {
        emit sortingSetSelectedPosition(maxElementIndex);
        emit updateWiget();
        QCoreApplication::processEvents();
        QThread::msleep(10);
    }
}


void Sorting::HeapSort(int *array, int length) {
    for (int i = length / 2 - 1; i >= 0; --i) {
        ToBinaryHeap(array, length, i);
        emit updateWiget();
        QCoreApplication::processEvents();
        QThread::msleep(10);
    }

    for (int i = length - 1; i >= 0; --i) {
        std::swap(array[0], array[i]);
        emit sortingSetSelectedPosition(i);
        emit updateWiget();
        QCoreApplication::processEvents();
        QThread::msleep(10);

        ToBinaryHeap(array, i, 0);
        emit sortingSetSelectedPosition(i);
        emit updateWiget();
        QCoreApplication::processEvents();
        QThread::msleep(10);
    }
    emit sortingSetSelectedPosition(-1);
    emit updateWiget();
    QCoreApplication::processEvents();
    QThread::msleep(10);
}

void Sorting::MergeSort(int *array, int length) {
    Partition(array, 0, length - 1);
    emit sortingSetSelectedPosition(-1);
    emit updateWiget();
    QCoreApplication::processEvents();
    QThread::msleep(10);
}

void Sorting::Partition(int *array, int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;
    Partition(array, left, middle);
    Partition(array, middle + 1, right);
    Merge(array, left, middle, right);
    emit sortingSetSelectedPosition(middle);
    emit updateWiget();
    QCoreApplication::processEvents();
    QThread::msleep(10);
}

void Sorting::Merge(int *array, int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int *leftPart = new int[leftSize];
    int *rightPart = new int[rightSize];

    for (int i = 0; i < leftSize; ++i) { leftPart[i] = array[left + i]; }
    for (int j = 0; j < rightSize; ++j) { rightPart[j] = array[middle + 1 + j]; }

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (leftPart[i] <= rightPart[j]) {
            array[k] = leftPart[i];
            ++i;
        } else {
            array[k] = rightPart[j];
            ++j;
        }
        ++k;
        emit sortingSetSelectedPosition(-1);
        emit updateWiget();
        QCoreApplication::processEvents();
        QThread::msleep(2);
    }
    emit sortingSetSelectedPosition(-1);
    emit updateWiget();
    QCoreApplication::processEvents();
    QThread::msleep(5);
    while (i < leftSize) {
        array[k] = leftPart[i];
        ++i;
        ++k;
    }
    emit sortingSetSelectedPosition(-1);
    emit updateWiget();
    QCoreApplication::processEvents();
    QThread::msleep(5);
    while (j < rightSize) {
        array[k] = rightPart[j];
        ++j;
        ++k;
    }

    delete[] leftPart;
    delete[] rightPart;
    emit sortingSetSelectedPosition(-1);
    emit updateWiget();
    QCoreApplication::processEvents();
    QThread::msleep(10);
}

void Sorting::Divide(int *&array, std::vector<int> &divideSize, int &end) {
    int size = divideSize.back();
    divideSize.pop_back();
    int start = end - size;
    int min = array[start];
    int max = array[start];
    for (int i = start + 1; i < end; i++) {
        if (array[i] < min) {
            min = array[i];
        } else if (array[i] > max) {
            max = array[i];
        }
        emit sortingSetSelectedPosition(i);
        emit updateWiget();
        QCoreApplication::processEvents();
        QThread::msleep(10);
    }
    if (min == max) {
        end = end - size;
    } else {
        std::vector<std::vector<int>> bucket(size, std::vector<int>());
        for (int i = start; i < end; i++) {
            int p = static_cast<int>((static_cast<double>(array[i] - min) / (max - min)) * size);
            if (p >= size) p = size - 1;  // Ограничиваем p максимальным значением size - 1
            bucket[p].push_back(array[i]);
        }
        int index = start;
        for (int i = 0; i < size; i++) {
            if (!bucket[i].empty()) {
                for (int j: bucket[i]) {
                    array[index++] = j;
                }
            }
        }
    }
}


void Sorting::InterpolationSort(int *array, int length) {
    if (length <= 1) return;

    std::vector<int> divideSize;
    divideSize.push_back(length);
    int end = length;

    while (!divideSize.empty()) {
        Divide(array, divideSize, end);
    }
    emit sortingSetSelectedPosition(-1);
    emit updateWiget();
    QCoreApplication::processEvents();
    QThread::msleep(10);
}

int Sorting::BinSearch(int *array, int start, int end, int number) {
    if (start > end) { return -1; }
    int middle = (start + end) / 2;
    emit sortingSetSelectedPosition(middle);
    emit updateWiget();
    QCoreApplication::processEvents();
    QThread::msleep(60);
    if (array[middle] == number) {
        return middle;
    } else if (array[middle] < number) {
        return BinSearch(array, middle + 1, end, number);
    } else {
        return BinSearch(array, start, middle - 1, number);
    }
}

long long Sorting::BinPow(long long number, long long power, int mod) {
    if (number < 0) number = -number;
    if (power == 0) {
        return 1;
    } else if (power == 1) {
        return number;
    }
    if (power % 2 == 1) {
        return (BinPow(number, power - 1, mod) * number) % mod;
    } else {
        long long temp = BinPow(number, power / 2, mod) % mod;
        return (temp * temp) % mod;
    }
}

