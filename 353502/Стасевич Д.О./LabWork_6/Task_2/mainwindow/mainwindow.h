//
// Created by darina on 5/25/24.
//

#ifndef TASK_2_MAINWINDOW_H
#define TASK_2_MAINWINDOW_H

#include <QWidget>


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

    int current_subtask = 0;

public slots:
    void do_subtask_clicked(int type);
    void enter_clicked();
    void save_array_clicked();
};


#endif //TASK_2_MAINWINDOW_H
