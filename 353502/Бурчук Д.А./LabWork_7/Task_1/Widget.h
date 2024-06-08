#ifndef LAB7TASK1_WIDGET_H
#define LAB7TASK1_WIDGET_H

#include <QWidget>

#include <ctime>
#include <iostream>

#include "Deque.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

    Deque d;

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget() override;

private:
    Ui::Widget *ui;

    void doTask();

    void showList();

private slots:
    void on_frontPushButton_clicked();
    void on_backPushButton_clicked();
    void on_popPushButton_clicked();
    void on_pushPushButton_clicked();
    void on_doTaskPushButton_clicked();
    void on_showPushButton_clicked();
};


#endif //LAB7TASK1_WIDGET_H
