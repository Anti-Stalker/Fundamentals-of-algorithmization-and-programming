#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QInputDialog>
#include <QStringList>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void heapSort();
    void heapify(QVector<int>& , int , int );
private slots:
    void on_bubbleSortButton_clicked();
    void on_mergeSortButton_clicked();
    void on_binarySearchButton_clicked();

    void on_sortBu_clicked();

    void on_heapsortButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<int> arr;

    void visualizeSort();
    void bubbleSort();
    void mergeSort(int left, int right);
    int binarySearch(int digit);
};

#endif // MAINWINDOW_H
