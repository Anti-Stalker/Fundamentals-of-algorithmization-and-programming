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
#include "Treap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private:
    QStandardItem *buildTree(Treap<int>::Node *cur);

private slots:
    void on_add_clicked();
    void on_erase_clicked();
    void on_find_clicked();
    void on_direct_clicked();
    void on_back_clicked();
    void on_byKey_clicked();
    void on_leaves_clicked();
    void on_eraseSubTree_clicked();
    void on_findPar_clicked();

public:

    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

private:
    Treap<int> t;
    Ui::main_window *ui;
};


#endif //TASK2_MAIN_WINDOW_H
