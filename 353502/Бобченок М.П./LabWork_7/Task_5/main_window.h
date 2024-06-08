//
// Created by u on 31.05.24.
//

#ifndef TASK5_MAIN_WINDOW_H
#define TASK5_MAIN_WINDOW_H

#include <QWidget>
#include "Deque.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private slots:
    void on_pushbackButton_clicked();

    void on_popbackButton_2_clicked();

    void on_pushfrontButton_clicked();

    void on_popfrontButton_clicked();

    void on_clearButton_clicked();

private:
    void printDeq();

    Ui::main_window *ui;
    Deque<int> deq;

public:
    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

};


#endif //TASK5_MAIN_WINDOW_H
