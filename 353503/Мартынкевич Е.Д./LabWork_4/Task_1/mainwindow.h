#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsitem.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGridLayout>
#include <QTimer>
#include <QThread>
#include <QPushButton>
#include "sortes.h"
#include <QLabel>
#include <QLineEdit>

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
    ~MainWindow();\

private slots:
    void Button1_clicked();
    void Button2_clicked();
    void Button3_clicked();
    void Button4_clicked();
    void Button5_clicked();
    void Button6_clicked();
    void Button7_clicked();
    void QuickSort(QVector<QGraphicsRectItem*>& arr, int start, int end);
    void ChangePosition(QGraphicsRectItem *firstItem, QGraphicsRectItem *secondItem );
    void HeapSort(QVector<QGraphicsRectItem*>& arr, int n);
    void Heapify(QVector<QGraphicsRectItem*>& arr, int n, int i);
    void MergeSort(QVector<QGraphicsRectItem*>& arr, int start, int end);
    void InterpolationSort(QVector<QGraphicsRectItem*>& arr, int first, int last);
    int binsearch(QVector<QGraphicsRectItem*>& vec, int digit);
    int InterpolationSearch(QVector<QGraphicsRectItem*>& arr, int x);

private:
    Ui::MainWindow *ui;
    QVector<QGraphicsRectItem*> bars;
    QGraphicsView *view;
    QGraphicsScene *scene;
    Sortes* sortes;
    QLabel* label;
    QLineEdit* line_edit1;
    QLineEdit* line_edit2;

    struct bucket
    {
        int first = 0;
        int size = 0;
        int current = 0;
    };

};
#endif // MAINWINDOW_H
