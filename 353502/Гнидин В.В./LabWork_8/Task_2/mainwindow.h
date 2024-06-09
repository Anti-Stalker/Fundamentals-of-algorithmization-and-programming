//
// Created by volodya-petarda on 5/31/24.
//

#ifndef LAB8_2_MAINWINDOW_H
#define LAB8_2_MAINWINDOW_H

#include <QWidget>
#include "heap/Heap.h"
#include "heap/HeapArray.h"
#include "heap/HeapList.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Heap *heap;

    Ui::mainwindow *ui;
private slots:
    void setHeapType(int type);

    void showHeap();

    void add();

    void getMax();

    void deleteMax();

    void increaseElement();

    void decreaseElement();
};


#endif //LAB8_2_MAINWINDOW_H
