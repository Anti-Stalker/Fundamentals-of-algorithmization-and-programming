#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 10; i++) {
        ui->textEdit->push(i);
    }
    ui->textEdit->updateView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

