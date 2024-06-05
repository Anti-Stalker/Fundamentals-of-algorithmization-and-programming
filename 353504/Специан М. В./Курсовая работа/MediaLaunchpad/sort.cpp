#include "sort.h"
Sort::Sort(QObject* parent)
    : QObject(parent)
{
}
void heapify(double* nums, int n, int i){
    int largest = i; // Инициализируем largest как корень
    int left = 2 * i + 1; // Левый потомок
    int right = 2 * i + 2; // Правый потомок

    // Если левый потомок больше корня
    if (left < n && nums[left] > nums[largest])
        largest = left;

    // Если правый потомок больше, чем largest
    if (right < n && nums[right] > nums[largest])
        largest = right;

    // Если largest не является корнем
    if (largest != i) {
        double temp = nums[i];
        nums[i] = nums[largest];
        nums[largest] = temp;
        // Рекурсивно heapify затронутое поддерево
        heapify(nums, n, largest);
    }
}
void heapsort(double* nums, int n){
    // Построение кучи (переставляем элементы в порядке убывания)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        double temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;
        // Вызываем heapify на уменьшенной куче
        heapify(nums, i, 0);
    }
}
