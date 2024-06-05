#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer (new QTimer)
    , rng(new QRandomGenerator)
{
    ui->setupUi(this);

    timer->setInterval(TICK_TIME);
    timer->start();

    for (int i = 0;i<100;i++)
    {
        allTable.insertItem((static_cast<qint64>(rng->generate())%100)-50, rng->generate());
    }

    auto vec = allTable.toQVector();
    QString plain = "";

    for (auto curr : vec)
    {
        for (auto instance : curr)
        {
            plain += "(" + QString::number(instance.first) + ";" + QString::number(instance.second) + "), ";
            if (instance.first < 0) negTable.insertItem(instance.first, instance.second);
            else posTable.insertItem(instance.first, instance.second);
        }

        plain += '\n';
    }

    ui->textEdit->setText(plain);

    vec = posTable.toQVector();
    plain="";

    for (auto curr : vec)
    {
        for (auto instance : curr)
        {
            plain += "(" + QString::number(instance.first) + ";" + QString::number(instance.second) + "), ";
        }

        plain += '\n';
    }

    ui->textEdit_2->setText(plain);

    vec = negTable.toQVector();
    plain="";

    for (auto curr : vec)
    {
        for (auto instance : curr)
        {
            plain += "(" + QString::number(instance.first) + ";" + QString::number(instance.second) + "), ";
        }

        plain += '\n';
    }

    ui->textEdit_3->setText(plain);
}

MainWindow::~MainWindow()
{
    delete ui;
}

