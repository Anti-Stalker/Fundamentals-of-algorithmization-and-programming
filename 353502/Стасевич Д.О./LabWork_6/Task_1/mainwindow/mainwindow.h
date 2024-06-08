//
// Created by darina on 5/25/24.
//

#ifndef TASK1_MAINWINDOW_H
#define TASK1_MAINWINDOW_H

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

public slots:
    void add_user_struct();
    void display_clicked();
};


#endif //TASK1_MAINWINDOW_H
