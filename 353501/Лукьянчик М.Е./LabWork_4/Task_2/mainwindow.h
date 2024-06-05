#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QInputDialog>
#include <QStringList>
#include <QTimer>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_bubbleSortButton_clicked();
    void on_mergeSortButton_clicked();
    void on_binarySearchButton_clicked();

    void on_sortBu_clicked();

    void on_heapsortButton_clicked();

    void on_pushButton_clicked();

    void on_interpolationSortButton_clicked();



private:
    Ui::MainWindow *ui;
    QVector<int> arr;

    void visualizeSort();
    void bubbleSort();
    void mergeSort(int left, int right);
    int binarySearch(int digit);
    void heapSort();
    void interpolationSort();
    void displayIndexPowMod(int qwe, QVector<int> arr);
    int binpow(int qwe, int asd , int zxc);
    void heapify(QVector<int>& , int asd , int  asdf);
};

#endif // MAINWINDOW_H
