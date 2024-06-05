#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , moveCount(0)
{
    ui->setupUi(this);
    connect(ui->solveButton, &QPushButton::clicked, this, &MainWindow::solveHanoi);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clearOutput);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::solveHanoi()
{
    QString N = ui->lineEdit->text();
    int n = N.toInt();
    ui->textEdit->clear();
    moveCount = 0;
    hanoi(n, 'A', 'C', 'B');
}

void MainWindow::hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) {
        printMove(from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printMove(from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

void MainWindow::printMove(char from_rod, char to_rod)
{
    moveCount++;
    QString move = QString("%1) From %2 to %3").arg(moveCount).arg(from_rod).arg(to_rod);
    ui->textEdit->append(move);
}

void MainWindow::clearOutput()
{
    ui->textEdit->clear();
    moveCount = 0;
}
