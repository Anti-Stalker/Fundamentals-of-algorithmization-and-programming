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
#include <QVector>
#include "Treap.h"
#include "map.h"
#include "set.h"

QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private:
    QStandardItem *buildTree(Treap<int, int>::Node *cur);

private slots:
    void on_add_clicked();
    void on_erase_clicked();
    void on_get_clicked();
    void on_change_clicked();
    void on_output_clicked();

public:

    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

private:
    bool type = false;
    map<int, int> mp;
    set<int> st;
    Ui::main_window *ui;
};


#endif //TASK2_MAIN_WINDOW_H
