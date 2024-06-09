//
// Created by volodya-petarda on 5/14/24.
//

#ifndef LAB4_1_MAINWINDOW_H
#define LAB4_1_MAINWINDOW_H

#include <QTimer>
#include <QDebug>
#include <QWidget>
#include <vector>
#include <QGraphicsScene>
#include <QGraphicsRectItem>


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    bool isSwapping = false;
    int n = 400;
    QGraphicsScene *scene;

    std::vector<QGraphicsRectItem*> rects;
    std::vector<int> vect;

    Ui::mainwindow *ui;

    void heapify(int n, int i);
    int partition(int start, int end);
    void swap(int i, int j);
    void setTo(int ind, int val);
    void quickSort(int start, int end);
    std::vector<int> mergeSort(int s, std::vector<int> &vector);

private slots:
    void mergeSort();
    void heapSort();
    void quickSort();
    void interpolationSort();
    void shuffle();
    void showVector();
    void setTrueIsSwapping();
    void setFalseIsSwapping();
};


#endif //LAB4_1_MAINWINDOW_H
