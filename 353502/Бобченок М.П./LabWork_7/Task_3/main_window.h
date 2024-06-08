//
// Created by u on 31.05.24.
//

#ifndef TASK3_MAIN_WINDOW_H
#define TASK3_MAIN_WINDOW_H

#include <QWidget>
#include <QRandomGenerator>
#include "TaskTable.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    void showTable();

    int size = 10;

    Ui::main_window *ui;

    TaskTable table = TaskTable(size);

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();

};


#endif //TASK3_MAIN_WINDOW_H
