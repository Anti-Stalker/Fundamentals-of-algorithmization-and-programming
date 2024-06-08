//
// Created by u on 30.05.24.
//

#ifndef TASK1_MAIN_WINDOW_H
#define TASK1_MAIN_WINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QRandomGenerator64>
#include "Queue.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget
{
Q_OBJECT

private slots:
    void on_pushButton_clicked();

    void on_popButton_clicked();

    void on_fillButton_clicked();

    void on_insertButton_clicked();

private:
    void showQueue(QListWidget* showingWidget, Queue<int>& showedQueue);

    Ui::main_window *ui;

    Queue<int> queue;
    Queue<int> queue1;

public:
    Queue<int> queue2;
    main_window(QWidget *parent = nullptr);
    ~main_window();
};


#endif //TASK1_MAIN_WINDOW_H
