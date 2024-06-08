//
// Created by u on 30.05.24.
//

#ifndef TASK1_MAIN_WINDOW_H
#define TASK1_MAIN_WINDOW_H

#include <QWidget>
#include <QString>
#include "task.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private slots:
    void set();
    void setFromConsole();
    void answer();
    void setByPtr();
    void setByLink();

public:
    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

private:
    int curQ = -1;
    athlete a = {45, 135, 'b', true};
    Ui::main_window *ui;
};


#endif //TASK1_MAIN_WINDOW_H
