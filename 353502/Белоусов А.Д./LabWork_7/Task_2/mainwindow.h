#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>
#include <QTreeWidgetItem>
#include "mtree.h"

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

    void UpdateTreeWidget(QTreeWidgetItem* item, vertex *curr, int depth = 1);

private:
    Ui::MainWindow *ui;
    QRandomGenerator* rng;
    QTimer* timer;
    mtree* tree;
};
#endif // MAINWINDOW_H
