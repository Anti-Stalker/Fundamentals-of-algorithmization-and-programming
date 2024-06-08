//
// Created by darina on 5/27/24.
//

#ifndef TASK2_MAINWINDOW_H
#define TASK2_MAINWINDOW_H

#include <QWidget>

#include "../AVLTree/Tree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    int cur = 0;

    Ui::mainwindow *ui;
    Tree *tree;

private slots:
    void next_node_add_clicked();
    void add_node_clicked();
    void find_in_tree();
    void delete_in_tree();
    void Info_1_clicked();
    void Info_2_clicked();
    void Info_3_clicked();
};


#endif //TASK2_MAINWINDOW_H
