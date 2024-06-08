#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    deque = new Deque<int>();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_push_clicked()
{
    deque->push_front(ui->spinBox_push->value());
    ui->lineEdit->setText(deque->toString());
}

void MainWindow::on_pushButton_push_back_clicked()
{
    deque->push_back(ui->spinBox_push_back->value());
    ui->lineEdit->setText(deque->toString());
}

void MainWindow::on_pushButton_size_clicked()
{
    ui->label_ans->setText("Size: " + QString::number(deque->size()));
}

void MainWindow::on_pushButton_first_clicked()
{
    ui->label_ans->setText("First: " + QString::number(deque->begin()));
}

void MainWindow::on_pushButton_last_clicked()
{
    ui->label_ans->setText("Last:  " + QString::number(deque->end()));
}

void MainWindow::on_pushButton_empty_clicked()
{
    ui->label_ans->setText("isEmpty:  " + QString::number(deque->isEmpty()));
}

void MainWindow::on_pushButton_pop_clicked()
{
    deque->pop_front();
    ui->lineEdit->setText(deque->toString());
}

void MainWindow::on_pushButton_pop_back_clicked()
{
    deque->pop_back();
    ui->lineEdit->setText(deque->toString());
}
