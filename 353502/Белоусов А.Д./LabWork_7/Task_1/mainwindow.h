#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>
#include "mqueue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

const size_t TICK_TIME = 100;

struct test
{
    char _a;
    bool _b;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    mqueue<test>* queue;
    QRandomGenerator* gen;
};
#endif // MAINWINDOW_H
