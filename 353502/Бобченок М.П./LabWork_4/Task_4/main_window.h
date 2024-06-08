//
// Created by u on 27.05.24.
//

#ifndef TASK4_MAIN_WINDOW_H
#define TASK4_MAIN_WINDOW_H

#include <QWidget>
#include <QTimer>
#include <QString>
#include "Vector.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private slots:
    void at();
    void begin();
    void capacity();
    void clear();
    void empty();
    void end();
    void erase();
    void pop_back();
    void push_back();
    void resize();
    void size();
    void updateWindow();


public:
    Vector<int> v;

    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

private:
    Ui::main_window *ui;
};


#endif //TASK4_MAIN_WINDOW_H
