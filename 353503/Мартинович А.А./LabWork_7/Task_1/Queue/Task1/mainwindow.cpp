#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Queue<int> queue;

    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.pop();

    qDebug() << queue.front() << queue.back() << queue.size();

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::pushElement);
    connect(ui->popButton, &QPushButton::clicked, this, &MainWindow::popElement);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushElement()
{
    int value = ui->spinBox->value();
    ui->listWidget->addItem(QString::number(value));
    try {
        queue.push(value);
    }
    catch (...) {
        qDebug() << "out of range";
    }

    findMax();
    ui->label->setText("Максимальный элемент: " + QString::number(_max));


}

void MainWindow::popElement()
{
    ui->listWidget->takeItem(0);
    try {
        queue.pop();
    }
    catch (...) {
        qDebug() << "out of range";
    }

    findMax();
    ui->label->setText("Максимальный элемент: " + QString::number(_max));
}

void MainWindow::findMax()
{
    int size = queue.size();
    int64_t max = INT64_MIN;
    for (int i = 0; i < size; i++) {
        if (queue.back() > max) {
            qDebug() << queue.back();
            max = queue.back();
        }
        queue.push(queue.front());
        queue.pop();
    }
    _max = (max==INT64_MIN)?0:max;
}
