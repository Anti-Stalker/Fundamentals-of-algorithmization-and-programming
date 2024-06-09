#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stack.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addValue);
    connect(ui->delButton, &QPushButton::clicked, this, &MainWindow::delValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addValue()
{
    ui->table->insert(ui->addBox->value(), ui->addEdit->text());
    ui->table->showTable();
}

void MainWindow::delValue()
{
    ui->table->remove(ui->delBox->value());
    ui->table->showTable();
}


