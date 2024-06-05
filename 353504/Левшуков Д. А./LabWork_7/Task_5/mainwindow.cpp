#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gen.seed(time(NULL));
    update_info();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_info()
{
    QString info;
    if(!q.empty())
    {
    auto it=q.begin();
    do
    {
        info+=QString::number(*it)+"  ";
        it++;
    }
    while(it!=q.end());

    ui->lineEdit->setText(info);
    }
    else ui->lineEdit->clear();
    ui->size->setText(QString::number(q.size()));
    if(q.empty())
        ui->empty->setText("True");
    else
        ui->empty->setText("False");

}

void MainWindow::on_pushButton_clicked()
{
    q.push_back(gen());
    update_info();
}


void MainWindow::on_pushButton_2_clicked()
{
    q.push_front(gen());
    update_info();
}


void MainWindow::on_pushButton_4_clicked()
{
    q.pop_back();
    update_info();
}


void MainWindow::on_pushButton_3_clicked()
{
    q.pop_front();
    update_info();
}


void MainWindow::on_pushButton_5_clicked()
{
    q.clear();
    update_info();
}

