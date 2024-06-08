#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QProgressBar>
#include <chrono>
#include <thread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::visualizeSort()
{
    QLayoutItem* item;
    while ((item = ui->verticalLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for (int i = 0; i < arr.size(); ++i) {
        QProgressBar* progressBar = new QProgressBar(this);
        progressBar->setValue(arr[i]);
        ui->verticalLayout->addWidget(progressBar);
    }
}



void MainWindow::bubbleSort()
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                visualizeSort();
                qApp->processEvents(); // Для обновления GUI
                std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Задержка для визуализации
            }
        }
    }
}

void MainWindow::mergeSort(int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        QVector<int> leftArr(n1);
        QVector<int> rightArr(n2);

        for (int i = 0; i < n1; ++i)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; ++j)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                ++i;
            } else {
                arr[k] = rightArr[j];
                ++j;
            }
            ++k;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            ++i;
            ++k;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            ++j;
            ++k;
        }

        visualizeSort();
        qApp->processEvents(); // Для обновления GUI
        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Задержка для визуализации
    }
}

int MainWindow::binarySearch(int digit)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == digit)
            return mid;

        if (arr[mid] < digit)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void MainWindow::on_bubbleSortButton_clicked()
{
    if (arr.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Массив пуст!");
        return;
    }

    auto start = std::chrono::steady_clock::now();
    bubbleSort();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    QString message = "Время сортировки пузырьком: " + QString::number(diff.count()) + " секунд";
    QMessageBox::information(this, "Информация", message);
}

void MainWindow::on_mergeSortButton_clicked()
{
    if (arr. isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Массив пуст!");
        return;
    }

    auto start = std::chrono::steady_clock::now();
    mergeSort(0, arr.size() - 1);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - start;
    QString message = "Время сортировки слиянием: " + QString::number(diff.count()) + " секунд";
    QMessageBox::information(this, "Информация", message);
}

void MainWindow::on_binarySearchButton_clicked()
{
    if (arr.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Массив пуст!");
        return;
    }

    bool ok;
    int digit = QInputDialog::getInt(this, "Введите число", "Число:", 0, INT_MIN, INT_MAX, 1, &ok);
    if (ok) {
        int index = binarySearch(digit);
        if (index != -1) {
            QMessageBox::information(this, "Результат", "Искомое число найдено на индексе: " + QString::number(index));
        } else {
            QMessageBox::information(this, "Результат", "Искомое число не найдено");
        }
    }
}

void MainWindow::on_sortBu_clicked()
{
    QString input = ui->arrayTextEdit->toPlainText();
    QStringList stringList = input.split(" ", Qt::SkipEmptyParts);
    arr.clear();
    for (const QString& str : stringList) {
        bool ok;
        int value = str.toInt(&ok);
        if (ok) {
            arr.append(value);
        } else {
            QMessageBox::warning(this, "Ошибка", "Некорректный ввод массива!");
            return;
        }
    }
}

void MainWindow::heapify(QVector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        visualizeSort();
        QTimer::singleShot(300, [this, &arr, n, largest]() {
            heapify(arr, n, largest);
        });
    }
}

void MainWindow::heapSort()
{
    auto start = std::chrono::steady_clock::now();

    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        visualizeSort();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));  // Задержка для визуализации
        heapify(arr, i, 0);
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    QMessageBox::information(this, "Время выполнения", QString("Время выполнения: %1 секунд").arg(duration.count()));
}
void MainWindow::on_heapsortButton_clicked()
{
    heapSort();
}


void MainWindow::on_pushButton_clicked()
{
  ui->arrayTextEdit->setPlainText("99 88 11 44 33 22 8 4 6  1 3 32 54 34 98 45");
    ui->arrayTextEdit->update();
}

