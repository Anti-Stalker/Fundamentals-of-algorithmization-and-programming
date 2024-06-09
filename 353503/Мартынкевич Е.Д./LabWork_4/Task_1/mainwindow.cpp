#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view = new QGraphicsView(this);
    view->setRenderHint(QPainter::Antialiasing);
    scene = new QGraphicsScene();
    view->setScene(scene);

    QGridLayout* layout = new QGridLayout();

    ui->centralwidget->setLayout(layout);
    layout->addWidget(view);

    label = new QLabel("1:\n2:");

    sortes = new Sortes();

    // Заполняем массив случайными значениями
    for(int i = 0; i < 150; i++) {
        bars.append(scene->addRect(i*10, 0, 10, -(rand() % 200)));
        bars[i]->setBrush(Qt::black);
    }

    QPushButton* button1 = new QPushButton("Быстрая сортировка");
    QPushButton* button2 = new QPushButton("Интерполяционая сортировка");
    QPushButton* button3 = new QPushButton("Кучей сортировка");
    QPushButton* button4 = new QPushButton("Слиянием сортировка");
    QPushButton* button5 = new QPushButton("новый массив");
    QPushButton* button6 = new QPushButton("Бинарный поиск");
    QPushButton* button7 = new QPushButton("Интерполяционный поиск");
    line_edit1 = new QLineEdit();
    line_edit2 = new QLineEdit();
    layout->addWidget(button1, 1, 1);
    layout->addWidget(button2, 2, 1);
    layout->addWidget(button3, 3, 1);
    layout->addWidget(button4, 4, 1);
    layout->addWidget(button5, 5, 1);
    layout->addWidget(line_edit1, 6, 1);
    layout->addWidget(button6, 7, 1);
    layout->addWidget(line_edit2, 8, 1);
    layout->addWidget(button7, 9, 1);
    layout->addWidget(label,1, 0);
    connect(button1, &QPushButton::clicked, this, &MainWindow::Button1_clicked);
    connect(button2, &QPushButton::clicked, this, &MainWindow::Button2_clicked);
    connect(button3, &QPushButton::clicked, this, &MainWindow::Button3_clicked);
    connect(button4, &QPushButton::clicked, this, &MainWindow::Button4_clicked);
    connect(button5, &QPushButton::clicked, this, &MainWindow::Button5_clicked);
    connect(button6, &QPushButton::clicked, this, &MainWindow::Button6_clicked);
    connect(button7, &QPushButton::clicked, this, &MainWindow::Button7_clicked);
    //connect(sortes, SIGNAL(swapItems(QGraphicsRectItem*, QGraphicsRectItem*)), this, SLOT(ChangePosition(QGraphicsRectItem*, QGraphicsRectItem*)));
}

void MainWindow::Button1_clicked() {
    for(int i = 0; i < 5; ++i) {
        QuickSort(bars, 0, bars.size() - 1);
    }
}
void MainWindow::Button2_clicked() {
    for(int i = 0; i < 8; ++i) {
        InterpolationSort(bars, 0, bars.size());
    }
}
void MainWindow::Button3_clicked() {
    HeapSort(bars, bars.size());
}
void MainWindow::Button4_clicked() {
    MergeSort(bars, 0, bars.size());
}
void MainWindow::Button5_clicked() {
    //bars.clear();
    //scene->update();
    for(int i = 0; i < 150; i++) {
        bars[i]->setRect(i*10, 0, 10, -(rand() % 200));
        bars[i]->setBrush(Qt::black);
    }
    scene->update();
}
void MainWindow::Button6_clicked() {
    int result = binsearch(bars, line_edit1->text().toInt());
    label->setText(QString::number(result));
}
void MainWindow::Button7_clicked() {
    int result = InterpolationSearch(bars, line_edit1->text().toInt());
    label->setText(QString::number(result));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MergeSort(QVector<QGraphicsRectItem*>& arr, int start, int end) {
    if (start == end) return;
    else if (end == start + 1 ) {
        return;
    }
    else if (end == start + 2) {
        if (arr[start]->rect().height() > arr[end - 1]->rect().height()) ChangePosition(arr[start], arr[end - 1]);
        return;
    }
    else {
        MergeSort(arr, start, (start + end) / 2);
        MergeSort(arr, (start + end) / 2, end);

        int f = start;
        int s = (start + end) / 2;
        QVector<QGraphicsRectItem*> parr(end - start);

        for (int count = start; count < end; ++count) {
            if (f == (start + end) / 2) {
                parr[count - start] = new QGraphicsRectItem(QRectF(arr[s]->rect().x(), arr[s]->rect().y(), arr[s]->rect().width(), arr[s]->rect().height()));
                ++s;
            }
            else if (s == end) {
                parr[count - start] = new QGraphicsRectItem(QRectF(arr[f]->rect().x(), arr[f]->rect().y(), arr[f]->rect().width(), arr[f]->rect().height()));
                ++f;
            }
            else if (arr[f]->rect().height() < arr[s]->rect().height()) {
                parr[count - start] = new QGraphicsRectItem(QRectF(arr[f]->rect().x(), arr[f]->rect().y(), arr[f]->rect().width(), arr[f]->rect().height()));
                ++f;
            }
            else {
                parr[count - start] = new QGraphicsRectItem(QRectF(arr[s]->rect().x(), arr[s]->rect().y(), arr[s]->rect().width(), arr[s]->rect().height()));
                ++s;
            }
        }

        QEventLoop loop;

        for (int count = start; count < end; ++count) {
            arr[count]->setBrush(Qt::red);
            arr[count]->setRect(arr[count]->rect().x(), arr[count]->rect().y(), arr[count]->rect().width(), parr[count - start]->rect().height());
            scene->update();

            QTimer::singleShot(10, &loop, SLOT(quit())); // Задержка 100 мс
            loop.exec();

            arr[count]->setBrush(Qt::black);
            scene->update();
        }
    }
}

void MainWindow::ChangePosition(QGraphicsRectItem* firstItem, QGraphicsRectItem* secondItem)
{
    QRectF rect1 = firstItem->rect();
    QRectF rect2 = secondItem->rect();

    double h1 = rect1.height();
    double h2 = rect2.height();

    rect1.setHeight(h2);
    rect2.setHeight(h1);

    firstItem->setRect(rect1);
    secondItem->setRect(rect2);

    firstItem->setBrush(Qt::red);
    secondItem->setBrush(Qt::red);
    scene->update();

    // Добавьте задержку здесь, чтобы увидеть анимацию
    QEventLoop loop;
    QTimer::singleShot(10, &loop, SLOT(quit())); // Задержка 100 мс
    loop.exec();

    firstItem->setBrush(Qt::black);
    secondItem->setBrush(Qt::black);
    scene->update();
}

void MainWindow::Heapify(QVector<QGraphicsRectItem*>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->rect().height() > arr[largest]->rect().height() )
        largest = left;

    if (right < n && arr[right]->rect().height()  > arr[largest]->rect().height() )
        largest = right;

    if (largest != i) {
        ChangePosition(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void MainWindow::HeapSort(QVector<QGraphicsRectItem*>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        ChangePosition(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

void MainWindow::QuickSort(QVector<QGraphicsRectItem*>& array, int left, int right) {
    if (left >= right)
        return;
    QGraphicsRectItem* pivot = array[(left + right) / 2];
    long long i = left;
    long long j = right;

    while(i <= j)
    {
        while(array[i]->rect().height() < pivot->rect().height())
        {
            i++;
        }
        while(array[j]->rect().height() > pivot->rect().height())
        {
            j--;
        }

        if(i <= j){
            ChangePosition(array[i], array[j]);
            ++i;
            --j;
        }
    }

    if(left < j)
        QuickSort(array, left , j);
    if(right > i)
        QuickSort(array, i, right);
}

void MainWindow::InterpolationSort(QVector<QGraphicsRectItem*>& arr, int first, int last) {
    if (last - first <= 1)
    {
        return;
    }
    int size = last - first;
    QVector<int> indexs(size);
    QVector<QGraphicsRectItem*> temp;
    for (int i = first; i < last; ++i)
    {
        temp.push_back(arr[i]);
    }
    QVector<bucket> buckets;

    int min = temp[0]->rect().height(), max = temp[0]->rect().height();
    for (int i = 0; i < size; i++)
    {
        if (temp[i]->rect().height() < min)
        {
            min = temp[i]->rect().height();
        }
        else if (temp[i]->rect().height() > max)
        {
            max = temp[i]->rect().height();
        }
    }

    if (max - min != 0)
    {
        for (int i = 0; i < size; ++i)
        {
            int interpolation = (size - 1) * (temp[i]->rect().height() - min) / (max - min);
            indexs[i] = interpolation;

            if (buckets.size() <= interpolation)
            {
                buckets.resize(interpolation + 1);
            }
            ++buckets[interpolation].size;
        }

        int bIndex = 0;
        for (int i = 0; i < buckets.size(); ++i)
        {
            buckets[i].first = bIndex;
            bIndex += buckets[i].size;
        }

        for (int i = 0; i < size; ++i)
        {
            int bIndex = indexs[i];
            int index = buckets[bIndex].first + buckets[bIndex].current;
            //arr.emitSignal(first + index, temp[i]);
            arr[first + index]->setRect(arr[first + index]->rect().x(), arr[first + index]->rect().y(), arr[first + index]->rect().width(), temp[i]->rect().height());
            arr[first + index]->setBrush(Qt::red);
            scene->update();

            QEventLoop loop;
            QTimer::singleShot(10, &loop, SLOT(quit())); // Задержка 100 мс
            loop.exec();

            arr[first + index]->setBrush(Qt::black);
            scene->update();

            ++buckets[bIndex].current;
        }

        for (int i = 0; i < buckets.size(); ++i)
        {
            InterpolationSort(arr, first + buckets[i].first, first + buckets[i].first + buckets[i].size);
        }
    }
}
int MainWindow::binsearch(QVector<QGraphicsRectItem*>& vec, int digit)
{
    int left = 0, right = vec.size() - 1;
    while (right > left)
    {
        int mid = (left + right) / 2;
        if (vec[mid]->rect().height() > digit)
        {
            right = mid - 1;
        }
        else if (vec[mid]->rect().height() < digit)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    if (vec[left]->rect().height() == digit)
    {
        return left;
    }
    else
    {
        return -1;
    }
}

int MainWindow::InterpolationSearch(QVector<QGraphicsRectItem*>& arr, int x) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right && x >= arr[left]->rect().height() && x <= arr[right]->rect().height()) {
        if (left == right) {
            if (arr[left]->rect().height() == x) return left;
            return -1;
        }
        int pos = left + (((double)(right - left) / (arr[right]->rect().height() - arr[left]->rect().height())) * (x - arr[left]->rect().height()));
        if (arr[pos]->rect().height() == x)
            return pos;
        if (arr[pos]->rect().height() < x)
            left = pos + 1;
        else
            right = pos - 1;
    }
    return -1; // элемент не найден
}
