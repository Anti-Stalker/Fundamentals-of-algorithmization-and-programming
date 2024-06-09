#include "visualizationsorts.h"
#include "QRandomGenerator"
#include "QPainter"

void VisualizationSorts::paintEvent()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::black);

    // Рисуем прямоугольник
    painter.drawRect(10, 10, 100, 100);

    // Рисуем эллипс
    painter.drawEllipse(150, 10, 100, 100);

    // Рисуем линию
    painter.drawLine(10, 150, 200, 150);
}

void VisualizationSorts::NewArr(int size, int randmax)
{
    arr.clear();
    for (int i = 0; i < size; i++) {
        arr.push_back(QRandomGenerator::global()->bounded(randmax));
    }
}

void VisualizationSorts::heapSort(int *arr, int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
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

void VisualizationSorts::heapify(int *arr, int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}
