//
// Created by volodya-petarda on 5/30/24.
//

#ifndef LAB7_2_MAINWINDOW_H
#define LAB7_2_MAINWINDOW_H

#include <QDebug>
#include <QWidget>
#include "Map.h"
#include "BinaryTree.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Map<int, std::string> *tree;

    Ui::mainwindow *ui;

private slots:
    void selectTree(int ind);
    void addElement();
    void showTree();
    void addRandom();
    void addSequence();
    void deleteKey();
    void findKey();
};


#endif //LAB7_2_MAINWINDOW_H
