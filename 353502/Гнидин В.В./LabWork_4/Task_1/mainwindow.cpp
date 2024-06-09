//
// Created by volodya-petarda on 5/14/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include <thread>
#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    rects = std::vector<QGraphicsRectItem*>(n);
    vect = std::vector<int>(n);
    for(int i = 0; i < n; i++) {
        vect[i] = i + 1;
        rects[i] = new QGraphicsRectItem(0, 0, 3, -(i + 1) * 2);
        int r = 255 * (double)i / n;
        int b = 255 - r;
        rects[i]->setBrush(QColor(r, 0, b));
        rects[i]->setPen(Qt::NoPen);
        scene->addItem(rects[i]);
        rects[i]->setPos(-700 + i * 3, 400);
    }

    connect(this->ui->pushButton_5, SIGNAL(clicked()), this, SLOT(shuffle()));
    connect(this->ui->pushButton, SIGNAL(clicked()), this, SLOT(heapSort()));
    connect(this->ui->pushButton_3, SIGNAL(clicked()), this, SLOT(quickSort()));
    connect(this->ui->pushButton_2, SIGNAL(clicked()), this, SLOT(mergeSort()));
    connect(this->ui->pushButton_4, SIGNAL(clicked()), this, SLOT(interpolationSort()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::showVector() {

}

void mainwindow::heapSort() {

    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(0, i);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(i, 0);
    }
}

void mainwindow::heapify(int n, int i) {
    int largest = i;
// Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && vect[l] > vect[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && vect[r] > vect[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(i, largest);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(n, largest);
    }

}

void mainwindow::swap(int i, int j) {
    QPointF temp = rects[vect[i] - 1]->pos();
    rects[vect[i] - 1]->setPos(rects[vect[j] - 1]->pos());
    rects[vect[j] - 1]->setPos(temp);
    rects[vect[i] - 1]->update();
    rects[vect[j] - 1]->update();
    scene->update();
    std::swap(vect[i], vect[j]);
    qApp->processEvents();
}

void mainwindow::shuffle() {
    int iter = n;
    while(iter--){
        int i = rand() % n;
        int j = rand() % n;
        swap(i, j);
    }
}

void mainwindow::setTrueIsSwapping() {
    isSwapping = true;
}

void mainwindow::setFalseIsSwapping() {
    qDebug()<<"hi";
    isSwapping = false;
}

int mainwindow::partition(int start, int end) {
    int pivot = vect[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (vect[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(pivotIndex, start);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (vect[i] <= pivot) {
            i++;
        }

        while (vect[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(i++, j--);
        }
    }

    return pivotIndex;
}

void mainwindow::quickSort() {
    quickSort(0, n - 1);
}

void mainwindow::quickSort(int start, int end) {
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(start, end);

    // Sorting the left part
    quickSort(start, p - 1);

    // Sorting the right part
    quickSort(p + 1, end);
}

void mainwindow::setTo(int ind, int val) {
    int ind2 = ind;
    for(int i = 0; i < n; i++){
        if(vect[i] == val)
            ind2 = i;
    }
    swap(ind, ind2);
}

std::vector<int> mainwindow::mergeSort(int s, std::vector<int> &avector) {
    if (avector.size()>1) {
        int mid = avector.size()/2;
        std::vector<int> lefthalf(avector.begin(),avector.begin()+mid);
        std::vector<int> righthalf(avector.begin()+mid,avector.begin()+avector.size());

        lefthalf = mergeSort(s, lefthalf);
        righthalf = mergeSort(s + mid, righthalf);

        unsigned i = 0;
        unsigned j = 0;
        unsigned k = 0;
        while (i < lefthalf.size() && j < righthalf.size()) {
            if (lefthalf[i] < righthalf[j]) {
                avector[k]=lefthalf[i];
                setTo(s + k, lefthalf[i]);
                i++;
            } else {
                avector[k] = righthalf[j];
                setTo(s + k, righthalf[j]);
                j++;
            }
            k++;
        }

        while (i<lefthalf.size()) {
            avector[k] = lefthalf[i];
            setTo(s + k, lefthalf[i]);
            i++;
            k++;
        }

        while (j<righthalf.size()) {
            avector[k]=righthalf[j];
            setTo(s + k, righthalf[j]);
            j++;
            k++;
        }

    }

    return avector;
}

void mainwindow::mergeSort() {
    std::vector<int> v(vect.begin(), vect.end());
    mergeSort(0, v);
}

void mainwindow::interpolationSort() {
    for(int i = 0; i < n; i++){
        setTo(i, i + 1);
    }
}
