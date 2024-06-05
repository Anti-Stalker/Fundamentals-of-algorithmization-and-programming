#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer)
    , queue(new mqueue<test>)
    , gen(new QRandomGenerator)
{
    ui->setupUi(this);

    timer->setInterval(TICK_TIME);

    connect(timer, &QTimer::timeout, this, [&]() {
        if (gen->generate() % 2 == 0)
        {
            queue->push(test({static_cast<char>(gen->generate()), static_cast<bool>(gen->generate())}));
            ui->listWidget->addItem(QString(queue->back()._a));
        }
        else if (!queue->empty())
        {
            if (ui->listWidget->takeItem(0)->text() != QString(queue->front()._a))
            {
                qDebug() << "Bad queue :(";
            }
            queue->pop();
        }
    });

    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
