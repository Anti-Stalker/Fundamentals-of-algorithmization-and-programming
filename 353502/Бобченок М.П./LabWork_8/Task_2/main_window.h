//
// Created by u on 31.05.24.
//

#ifndef TASK2_MAIN_WINDOW_H
#define TASK2_MAIN_WINDOW_H

#include <QWidget>
#include <QString>
#include <QTreeWidgetItem>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTreeView>
#include <QString>
#include "Heaps/ArrayHeap.h"
#include "Heaps/PtrHeap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private:
    QStandardItem *buildPtr(std::shared_ptr<Node> cur);
    QStandardItem *buildArray(int cur);

private slots:
    void on_add_clicked();
    void on_erase_clicked();
    void on_changeType_clicked();

public:

    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

private:
    QVector<int> heap;
    bool type = 0;
    ArrayHeap ah;
    PtrHeap ph;
    Ui::main_window *ui;
};


#endif //TASK2_MAIN_WINDOW_H
