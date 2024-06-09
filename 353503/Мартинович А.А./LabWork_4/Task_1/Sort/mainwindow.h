#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QGraphicsRectItem"
#include "QRandomGenerator"
#include "QVector"
#include "QDebug"
#include "QPushButton"
#include "QTimer"
#include "QThread"
#include "QEventLoop"
#include "QtMath"
#include "QGridLayout"
#include "QSpinBox"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const int32_t MAX_NUMBER = 500;
    const int32_t POST_WIDTH = 3;
    const int32_t ARR_SIZE = 400;
    const int32_t SKIP_TIME_SORT = 1;
    const int32_t SKIP_TIME_SEARCH = 100;

    explicit MainWindow(QWidget *parent = nullptr);
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGridLayout *layout;
    QWidget *central_widget;

    QVector<int32_t> arr;
    QEventLoop *loop;
    QElapsedTimer timer;

    bool is_now_sort;

    void shuffle();

    void showArr();
    void showArrSearch(int s, QColor const &col);

    void startHeapSort();
    void heapify(int n, int i);
    void heapSort();

    void startMergeSort();
    void merge(int left, int middle, int right);
    void mergeSort(int left, int right);

    void startQuickSort();
    int partQuickSort(int left, int right);
    void quickSort(int start, int end);

    void startInterpolSort();
    void interpolationSort(QVector<int>& arr, int start, int size);

    int interpolationSearch(QVector<int>& arr, int x);
    void startInterpolSearch();

    void startBinSearch();
    int binSearh(int search, int l, int r);

    bool isSorted();



    void skip(int ms);

    QSpinBox *search_spin_box;
    QPushButton *shuffle_button;
    QPushButton *heap_sort_button;
    QPushButton *merge_sort_button;
    QPushButton *quick_sort_button;
    QPushButton *interpol_sort_button;
    QPushButton *bin_search_button;
    QPushButton *interpol_search_button;

};
#endif // MAINWINDOW_H

