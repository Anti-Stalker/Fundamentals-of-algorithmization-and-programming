#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 5; ++i)
    {
        deq.push_back(QRandomGenerator::global()->bounded(1000));
        ui->listWidget->addItem(QString::number(deq.back()));
    }
    makeCyclicList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeCyclicList()
{
    MyCyclicList list1;
    MyCyclicList list2;
    ui->list1->clear();
    ui->list2->clear();

    int min = deq.indexOf(deq.minValue());
    int max = deq.indexOf(deq.maxValue());
    if (min > max) std::swap(min, max);

    for (int i = min + 1; i < max; ++i)
    {
        list1.push_back(deq.at(i));
        ui->list1->addItem(QString::number(deq.at(i)));
    }
    for (int i = 0; i <= min; ++i)
    {
        list2.push_back(deq.at(i));
        ui->list2->addItem(QString::number(deq.at(i)));
    }
    for (int i = max; i <= deq.lastIndex(); ++i)
    {
        list2.push_back(deq.at(i));
        ui->list2->addItem(QString::number(deq.at(i)));
    }
}

void MainWindow::on_addBack_clicked()
{
    deq.push_back(QRandomGenerator::global()->bounded(1000));
    ui->listWidget->addItem(QString::number(deq.back()));
    makeCyclicList();
}


void MainWindow::on_addFront_clicked()
{
    deq.push_back(QRandomGenerator::global()->bounded(1000));
    ui->listWidget->insertItem(0, QString::number(deq.back()));
    makeCyclicList();
}


void MainWindow::on_removeBack_clicked()
{
    deq.pop_back();
    ui->listWidget->takeItem(ui->listWidget->count() - 1);
    makeCyclicList();
}


void MainWindow::on_removeFront_clicked()
{
    deq.pop_front();
    ui->listWidget->takeItem(0);
    makeCyclicList();
}


void MainWindow::on_pushButton_clicked()
{
    int index = ui->listWidget->currentRow();
    deq.removeAt(index);
    ui->listWidget->takeItem(index);
    makeCyclicList();
}

