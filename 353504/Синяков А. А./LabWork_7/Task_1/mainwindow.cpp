#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->EnqueueFrontButton, &QPushButton::clicked, this, &::MainWindow::on_EnqueueFrontButton_clicked);
    connect(ui->EnqueueBackButton, &QPushButton::clicked, this, &::MainWindow::on_EnqueueBackButton_clicked);
    connect(ui->DequeueFrontButton, &QPushButton::clicked, this, &::MainWindow::on_DequeueFrontButton_clicked);
    connect(ui->DequeueBackButton, &QPushButton::clicked, this, &::MainWindow::on_DequeueBackButton_clicked);


    queue.display(ui->queueListWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ConvertToCircularButton_clicked()
{
    queue.convertToCircular();
    qDebug() << "Is queue circular? " << (queue.isCircular() ? "Yes" : "No");
}




void MainWindow::on_EnqueueFrontButton_clicked()
{
    QString item = ui->inputTextEdit->toPlainText();
    if (!item.isEmpty()) {
        queue.enqueue(item, true); // Добавляем элемент в начало очереди
        queue.display(ui->queueListWidget);
        ui->inputTextEdit->clear();
    }
}


void MainWindow::on_EnqueueBackButton_clicked()
{
    QString item = ui->inputTextEdit->toPlainText();
    if (!item.isEmpty()) {
        queue.enqueue(item, false); // Добавляем элемент в конец очереди
        queue.display(ui->queueListWidget);
        ui->inputTextEdit->clear();
    }
}


void MainWindow::on_DequeueFrontButton_clicked()
{
    queue.dequeue(true); // Удаляем элемент из начала очереди
    queue.display(ui->queueListWidget);
}


void MainWindow::on_DequeueBackButton_clicked()
{
    queue.dequeue(false); // Удаляем элемент из конца очереди
    queue.display(ui->queueListWidget);
}

