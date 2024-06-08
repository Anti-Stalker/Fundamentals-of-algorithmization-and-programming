#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette p(ui->centralwidget->palette());
    p.setColor(QPalette::Window, QColor(219, 243, 246));
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(p);
    ui->plainTextEdit->setPalette(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_On_front_clicked()
{
    if(!queue.empty())
    {
        qint64 value = queue.front();
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(QString::number(value));

    }
}

void MainWindow::on_On_back_clicked()
{
    if(!queue.empty())
    {
        qint64 value = queue.back();
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(QString::number(value));
    }
}


void MainWindow::on_On_Empty_clicked()
{
    bool isEmpty = queue.empty();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(QString(isEmpty ? "Is Empty!" : "Is not Empty!"));
}


void MainWindow::on_On_Sort_clicked()
{
    if(!queue.empty())
    {
        ui->plainTextEdit->clear();
        queue.bubbleSort();
        ui->plainTextEdit->setPlainText(queue.print());
    }
}


void MainWindow::on_On_Print_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(queue.print());
}


void MainWindow::on_On_clear_clicked()
{
    ui->plainTextEdit->clear();
    queue.clear();
}


void MainWindow::on_On_push_back_clicked()
{
    long long rand = QRandomGenerator::global()->bounded(100);
    queue.push_back(rand);
    ui->plainTextEdit->setPlainText(queue.print());
}


void MainWindow::on_On_push_front_clicked()
{
    long long rand = QRandomGenerator::global()->bounded(100);
    queue.push_front(rand);
    ui->plainTextEdit->setPlainText(queue.print());
}


void MainWindow::on_On_pop_back_clicked()
{
    if(!queue.empty())
    {
        qint64 value = queue.pop_back();
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(queue.print());
    }
}


void MainWindow::on_On_pop_front_clicked()
{
    if(!queue.empty())
    {
        qint64 value = queue.pop_front();
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(queue.print());
    }
}

