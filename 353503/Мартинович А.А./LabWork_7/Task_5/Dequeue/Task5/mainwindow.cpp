#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dequeue.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushBackButton, &QPushButton::clicked, this, &MainWindow::pushBack);
    connect(ui->popBackButton, &QPushButton::clicked, this, &MainWindow::popBack);

    connect(ui->pushFrontButton, &QPushButton::clicked, this, &MainWindow::pushFront);
    connect(ui->popFrontButton, &QPushButton::clicked, this, &MainWindow::popFront);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushBack()
{
    ui->view->push_back(ui->backBox->value());
    ui->view->showDeque();
}

void MainWindow::popBack()
{
    try {
        ui->view->pop_back();
        ui->view->showDeque();
    }
    catch (...) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("В очереди нет элементов");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }

}

void MainWindow::pushFront()
{
    ui->view->push_front(ui->frontBox->value());
    ui->view->showDeque();
}

void MainWindow::popFront()
{
    try {
        ui->view->pop_front();
        ui->view->showDeque();
    }
    catch (...) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("В очереди нет элементов");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }

}

