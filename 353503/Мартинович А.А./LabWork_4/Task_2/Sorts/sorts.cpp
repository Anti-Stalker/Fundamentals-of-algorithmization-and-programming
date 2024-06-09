#include "sorts.h"

void Sorts::heapSort(int *arr, int arrSize)
{
    // Построение кучи (перегруппируем массив)
    for (int i = arrSize / 2 - 1; i >= 0; i--) {
        heapify(arr, arrSize, i);
    }

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        // Перемещаем текущий корень в конец
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

void Sorts::heapify(int *arr, int arrSize, int index)
{
    int largest = inde;
    // Инициализируем наибольший элемент как корень
    int l = 2 * index + 1; // левый = 2*i + 1
    int r = 2 * index + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < arrSize && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < arrSize && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != index) {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, arrSize, largest);
    }
}
