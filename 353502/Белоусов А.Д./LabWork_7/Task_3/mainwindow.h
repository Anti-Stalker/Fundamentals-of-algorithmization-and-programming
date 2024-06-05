#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>
#include <QTreeWidgetItem>
#include "mhash_table.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

const int TICK_TIME = 500;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QRandomGenerator* rng;
    QTimer* timer;
    mhash_table<int> allTable {100};
    mhash_table<int> posTable {100};
    mhash_table<int> negTable {100};
};
#endif // MAINWINDOW_H
