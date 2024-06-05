#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelArray->setWordWrap(true);
    ui->searchEdit->setMaximum(600);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->sizeEdit->setText("200");
    index = 0;

    timer = new QElapsedTimer();
    for (int i = 0; i < 200; i++) {
        Array.push_back(QRandomGenerator::global()->bounded(50, 550));
    }
    printArray();
    connect(ui->sizeEdit, &QLineEdit::textChanged, this, &MainWindow::changeArraySize);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int sceneW = ui->graphicsView->width();
    int sceneH = ui->graphicsView->height();
    double rectW = static_cast<double>(sceneW) / Array.size();
    ui->graphicsView->scene()->clear();
    for (int i = 0; i < Array.size(); i++) {
        QRect rect(10 + i * rectW, sceneH - Array[i], rectW, Array[i]+50);
        QGraphicsRectItem *rectItem = scene->addRect(rect);
        rectItem->setBrush(Qt::red);
        rectItem->setPen(QPen(Qt::black));
    }
}

void MainWindow::RandomArray(int size)
{
    Array.clear();
    for (int i = 0; i < size; i++) {
        Array.push_back(QRandomGenerator::global()->bounded(50, 550));
    }
}

bool MainWindow::isSorted()
{
    for (int i = 1; i < Array.size(); i++) {
        if (Array[i] < Array[i - 1]) {
            return false;
        }
    }
    return true;
}

void MainWindow::changeArraySize()
{
    bool ok;

    int size = ui->sizeEdit->text().toInt(&ok);
    if (ok && size > 0 && size <= 400) {
        currentIndex = -1;
        ui->graphicsView->scene()->clear();
        ui->label->clear();
        ui->labelSearch->clear();
        ui->searchEdit->clear();
        RandomArray(size);
        printArray();
        ui->sort->setEnabled(true);
        update();
    } else {
        QMessageBox::warning(this, "Ошибка", "Введите положительное целое число до 400");
    }
}

void MainWindow::merge(QVector<int> &Array, int l, int m, int r)
{
    int n1 = m + 1 - l;
    int n2 = r - m;
    QVector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = Array[l + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = Array[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (stop) {
            return;
        }
        if (L[i] <= R[j]) {
            Array[k] = L[i];
            updateFunction();
            i++;
        } else {
            Array[k] = R[j];
            updateFunction();
            j++;
        }
        k++;
    }
    while (i < n1) {
        if (stop) {
            return;
        }
        Array[k++] = L[i++];
        updateFunction();
    }
    while (j < n2) {
        if (stop) {
            return;
        }
        Array[k++] = R[j++];
        updateFunction();
    }
}

void MainWindow::MergeSort(QVector<int> &, int l, int r)
{
    if (stop) {
        return;
    }
    if (l < r) {
        int m = (l + r) / 2;
        MergeSort(Array, l, m);
        MergeSort(Array, m + 1, r);
        merge(Array, l, m, r);
        updateFunction();
    }
}

void MainWindow::QuickSort(QVector<int> &Array, int low, int high)
{
    if (stop) {
        return;
    }
    if (low < high) {
        int pi = partition(Array, low, high);
        printArray();
        QuickSort(Array, low, pi - 1);
        QuickSort(Array, pi + 1, high);
        if (stop) {
            return;
        }
    }
}

int MainWindow::partition(QVector<int> &Array, int low, int high)
{
    int support_element = Array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (Array[j] < support_element) {
            i++;
            std::swap(Array[i], Array[j]);
            updateFunction();
        }
    }
    std::swap(Array[i + 1], Array[high]);
    printArray();
    return (i + 1);
}

void MainWindow::heapify(QVector<int> &Array, int n, int i)
{
    if (stop) {
        return;
    }
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && Array[l] > Array[largest]) {
        largest = l;
    }
    if (r < n && Array[r] > Array[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(Array[i], Array[largest]);
        updateFunction();
        heapify(Array, n, largest);
    }
}

void MainWindow::HeapSort(QVector<int> &Array, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(Array, n, i);
        if (stop) {
            return;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(Array[0], Array[i]);
        updateFunction();
        heapify(Array, i, 0);
        if (stop) {
            return;
        }
    }
    printArray();
}

void MainWindow::on_sort_clicked()
{
    timer->start();
    ui->sortBox->setEnabled(false);
    ui->sort->setEnabled(false);
    ui->searchButton->setEnabled(false);
    ui->searchEdit->setEnabled(false);
    stop = false;
    ui->sizeEdit->setEnabled(0);
    if (ui->sortBox->currentIndex() == 0) {
        MergeSort(Array, 0, Array.size() - 1);
    } else if (ui->sortBox->currentIndex() == 1) {
        QuickSort(Array, 0, Array.size() - 1);
    } else if (ui->sortBox->currentIndex() == 2) {
        HeapSort(Array, Array.size());
    } else if (ui->sortBox->currentIndex() == 3) {
        Isort = new InterpolationSort();
        connect(Isort, &InterpolationSort::ArrayChanged, this, &MainWindow::updateFunction);
        Isort->sort(Array);
    }
    ui->searchButton->setEnabled(true);
    ui->searchEdit->setEnabled(true);
    ui->sortBox->setEnabled(true);

    ui->sizeEdit->setEnabled(true);
    if (isSorted()) {
        qint64 Time = timer->elapsed();
        ui->label->setText(QString::number(Time) + " мс");
    }
}

void MainWindow::updateFunction()
{
    update();
    printArray();
    QThread::msleep(15);
    QCoreApplication::processEvents();
}

void MainWindow::on_resulttart_clicked()
{
    currentIndex = -1;
    stop = true;
    ui->label->clear();
    ui->searchEdit->clear();
    ui->labelSearch->clear();
    RandomArray(Array.size());
    printArray();
    ui->sortBox->setEnabled(true);
    ui->sort->setEnabled(true);
    updateFunction();
}

int MainWindow::binsearch(QVector<int> &Array, int size, int digit)
{
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        leftIndex = left;
        rightIndex = right;
        int mid = (left + right) / 2;
        if (Array[mid] == digit) {
            currentIndex = mid;
            return mid;
        }
        if (Array[mid] < digit) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void MainWindow::on_searchButton_clicked()
{
    int digit = ui->searchEdit->text().toInt();

    if (!isSorted()) {
        ui->searchEdit->setEnabled(false);
        QMessageBox::warning(this, "Ошибка", "Массив должен быть отсортирован!");
    } else if (digit == 0 && ui->searchEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите число!");
        return;
    } else {
        int index = binsearch(Array, Array.size(), digit);
        ui->labelSearch->setText(QString::number(index));
    }
}

void MainWindow::printArray(){
    QString ArrayString = "";
    for (int i = 0; i < Array.size(); i++) {
        ArrayString += QString::number(Array[i]);
        ArrayString += ", ";
    }
    ArrayString.chop(2);
    ui->labelArray->setText(ArrayString);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->labelSearch->text() == ""){
       QMessageBox::warning(this, "Ошибка", "Сначала найдите индекс");
        return;
    }
    long long answer = Binpow::binpow(ui->labelSearch->text().toLongLong(), Array.size(), ui->modulNumber->value());
    ui->labelSearchAfterBinPow->setText(QString::number(answer));
}


void MainWindow::on_restart_clicked()
{
    currentIndex = -1;
    stop = true;
    ui->label->clear();
    ui->searchEdit->clear();
    ui->labelSearch->clear();
    RandomArray(Array.size());
    ui->sortBox->setEnabled(true);
    ui->sort->setEnabled(true);
    updateFunction();
}

