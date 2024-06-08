#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    queue<int> a;

    for (int i = 0; i < 10; i++){
        a.push(i);
    }

    a[5] = 100;

    queue<int> b;

    for (int i = 0; i < 10; i++){
        b.push(i);
    }

    a.task(a, b);

    for (int i = 0; i < 20; i++){
        qDebug() << a[i] << " ";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

