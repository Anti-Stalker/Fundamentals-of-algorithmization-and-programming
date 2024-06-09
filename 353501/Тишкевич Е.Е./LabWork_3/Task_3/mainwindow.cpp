#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spin->setMinimum(-10000000);
     ui->spin->setMaximum(10000000);

     connect(ui->ansB, &QPushButton::pressed, this, &MainWindow::printRev);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::reversed(int num, int rev)
{
    if(num == 0)
        return rev;
    else
        return reversed(num / 10, rev * 10 + num % 10);
}

void MainWindow::printRev()
{
    int ans = reversed(ui->spin->value());
    ui->ans->setText(QString::number(ans));

}
