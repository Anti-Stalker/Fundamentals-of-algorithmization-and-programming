#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "binarysearchtree.h"
#include "QString"
#include "treeview.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BinarySearchTree<QString> tree;

    connect(ui->AppendButton, &QPushButton::clicked, this, &MainWindow::appendValue);
    connect(ui->DeleteButton, &QPushButton::clicked, this, &MainWindow::deleteValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendValue()
{
    try {
        ui->tree_view->insert(ui->AppendBox->value(), ui->lineEdit->text());
        ui->tree_view->UpdateView();
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
        ui->tree_view->del(ui->DeleteBox->value());
        ui->tree_view->UpdateView();
    }
    catch (...) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Такого ключа нет");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }

}



