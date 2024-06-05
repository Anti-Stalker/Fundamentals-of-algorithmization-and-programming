#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "interpolationsort.h"
#include "binpow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *e) override;
    void RandomArray(int size);

    void MergeSort(QVector<int> &Array, int l, int r);
    void merge(QVector<int> &Array, int l, int m, int r);

    void QuickSort(QVector<int> &Array, int low, int high);
    int partition(QVector<int> &Array, int low, int high);

    void heapify(QVector<int> &Array, int n, int i);
    void HeapSort(QVector<int> &, int n);

    bool isSorted();

    int binsearch(QVector<int> &, int size, int digit);

    void printArray();

private slots:
    void on_sort_clicked();
    void on_resulttart_clicked();
    void changeArraySize();
    void on_searchButton_clicked();
    void updateFunction();
    void on_pushButton_clicked();

    void on_restart_clicked();

private:
    int leftIndex;
    int rightIndex;
    int currentIndex;
    QElapsedTimer *timer;
    bool isPaintingGreen = false;
    int index;
    bool stop = false;
    QGraphicsScene *scene;
    QVector<int> Array;
    QVector<QGraphicsRectItem *> rects;
    Ui::MainWindow *ui;
    InterpolationSort *Isort;

};
#endif // MAINWINDOW_H
