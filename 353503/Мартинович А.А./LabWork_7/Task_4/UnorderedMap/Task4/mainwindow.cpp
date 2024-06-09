#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    UnorderedMap<QString> t(100);
    t.insert(10, "sdhh");
    qDebug() << t.get(10);


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
    ui->table->showMap();
}

void MainWindow::delValue()
{
    ui->table->remove(ui->delBox->value());
    ui->table->showMap();
}

