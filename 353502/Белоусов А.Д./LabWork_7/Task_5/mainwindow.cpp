#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mdeque<int> kek;

    kek.push_front(5);
    kek.push_front(4);
    kek.push_front(7);
    kek.push_front(9);
    kek.push_front(2);
    kek.push_front(10);
    kek.push_front(6);
    kek.push_front(0);

    kek.pop_front();

    while (!kek.empty())
    {
        qDebug() << kek.back();
        kek.pop_back();

        if (!kek.empty())
        {
            qDebug() << kek.front();
            kek.pop_front();
        }
    }

    qDebug() << "===============================";

    kek.push_front(5);
    kek.push_front(4);
    kek.push_front(7);
    kek.push_back(9);
    kek.push_front(2);
    kek.push_back(10);
    kek.push_front(6);
    kek.push_front(0);

    for (auto inst : kek)
    {
        qDebug() << inst;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

