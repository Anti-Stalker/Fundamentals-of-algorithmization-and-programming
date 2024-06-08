//
// Created by darina on 5/29/24.
//

#ifndef TASK5_MAINWINDOW_H
#define TASK5_MAINWINDOW_H

#include <QWidget>

#include "../Deque/Deque.h"

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
    Deque<int> d;

private slots:
    void do_push_back();
    void do_pop_back();
    void do_push_front();
    void do_pop_front();
    void show_size();
    void show_empty();
    void do_at();
    void do_squares();
    void do_equales();
    void Display();
    void do_clear();
};


#endif //TASK5_MAINWINDOW_H
