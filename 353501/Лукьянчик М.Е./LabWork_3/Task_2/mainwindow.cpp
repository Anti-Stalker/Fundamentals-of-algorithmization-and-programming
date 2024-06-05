#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculate, &QPushButton::clicked, this, &MainWindow::calcAcker);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcAcker()
{
    QString M = ui->enterM->text();
    int m = M.toInt();
    QString N = ui->enterN->text();
    int n = N.toInt();
    /*if(m>n)
    {
        ui->answer->setText("Wrong input");
    }
    else*/
    {
    long long result = acker(m, n);
    ui->answer->setText(QString::number(result));
    }
}

int MainWindow::acker(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return acker(m - 1, 1);
    else
        return acker(m - 1, acker(m, n - 1));
}
