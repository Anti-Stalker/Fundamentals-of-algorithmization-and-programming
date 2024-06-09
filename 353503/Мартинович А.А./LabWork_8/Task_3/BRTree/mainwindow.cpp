#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "rbtree.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->treeView->UpdateView();

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::appendValue);
    connect(ui->delButton, &QPushButton::clicked, this, &MainWindow::deleteValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendValue()
{
    try {
        ui->treeView->insert(ui->addBox->value(), 0);
        ui->treeView->UpdateView();
    }
    catch (...) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Такой ключ уже существует");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}

void MainWindow::deleteValue()
{
    try {
        ui->treeView->erase(ui->delBox->value());
        ui->treeView->UpdateView();
    }
    catch (...) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Такого ключа нет");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }

}

