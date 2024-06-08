#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int t=rand();
    h.create(t);

    p.push_back(" "+QString::number(t));
    QString txt;
    for(int i=p.size()-1;i>-1;--i)
    {
        txt+=p[i];
    }
    ui->textEdit->setText(txt);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->setText( QString::number(h.fmin()));
}

