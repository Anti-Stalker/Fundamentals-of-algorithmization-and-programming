//
// Created by darina on 5/27/24.
//

#ifndef TASK1_MAINWINDOW_H
#define TASK1_MAINWINDOW_H

#include <QWidget>

#include "../Queue/Queue.h"

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
    Queue <std::string> q;
    std::vector<std::string> v;

    void ShowQueue();

private slots:
    void previousElement();
    void NextElement();
    void DoDequeue();
    void DoEnqueue();
    void GetSize();
    void ShowFront();
    void ShowBack();
    void DoClear();
};


#endif //TASK1_MAINWINDOW_H
