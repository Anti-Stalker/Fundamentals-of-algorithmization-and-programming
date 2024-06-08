#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    queue = new Queue<int>();

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,99);

    for (int i = 0; i < 10; ++i) {
        int randomValue = distribution(generator);  // Генерация случайного числа от 0 до 99
        queue->push(randomValue);
    }

    ui->lineEdit->setText(queue->toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_push_clicked()
{
    queue->push(ui->spinBox_push->value());
    ui->lineEdit->setText(queue->toString());
}

void MainWindow::on_pushButton_insertAt_clicked()
{
    queue->insertAt(ui->spinBox_insertValue->value(), ui->spinBox_insertPos->value());
    ui->lineEdit->setText(queue->toString());
}

void MainWindow::on_pushButton_size_clicked()
{
    ui->label_ans->setText("Size: " + QString::number(queue->size()));
}

void MainWindow::on_pushButton_front_clicked()
{
    ui->label_ans->setText("First: " + QString::number(queue->front()));
}

void MainWindow::on_pushButton_back_clicked()
{
    ui->label_ans->setText("Last:  " + QString::number(queue->back()));
}

void MainWindow::on_pushButton_empty_clicked()
{
    ui->label_ans->setText("isEmpty:  " + QString::number(queue->isEmpty()));
}

void MainWindow::on_pushButton_pop_clicked()
{
    queue->pop();
    ui->lineEdit->setText(queue->toString());
}

void MainWindow::on_pushButton_makeMinFirst_clicked()
{
    queue->makeMinFirst();
    ui->lineEdit->setText(queue->toString());
}

void MainWindow::on_pushButton_deleteAt_clicked()
{
    queue->deleteAt(ui->spinBox_deleteAt->value());
    ui->lineEdit->setText(queue->toString());
}
