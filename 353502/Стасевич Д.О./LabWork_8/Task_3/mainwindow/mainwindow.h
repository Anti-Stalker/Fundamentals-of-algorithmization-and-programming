//
// Created by darina on 5/31/24.
//

#ifndef TASK3_MAINWINDOW_H
#define TASK3_MAINWINDOW_H

#include <QWidget>

#include "../RBTree/RBTree.h"
#include "../RBTree/map.h"
#include "../RBTree/set.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Ui::mainwindow *ui;

    map<int, int> mapa;
    set<int> seta;

    void Display();

private slots:
    void map_insert();
    void map_clear();
    void map_find();
    void map_size();
    void map_value();
    void set_insert();
    void set_erase();
    void set_find();
    void set_clear();
    void set_size();
};


#endif //TASK3_MAINWINDOW_H
