#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculate, &QPushButton::clicked, this, &MainWindow::revNum);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::revNum()
{
    QString N = ui->lineEdit->text();
    int n = N.toInt();
    int revN = recRev(n, 0);
    ui->resultLabel->setText(QString::number(revN));
}

int MainWindow::recRev(int n, int revN)
{
    if (n == 0)
        return revN;
    else
        return recRev(n / 10, revN * 10 + n % 10);
}
