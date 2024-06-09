#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::displ()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    vec1=h->hash_table_display1();
    vec2=h->hash_table_display2();
    QString tmp1="";
    QString tmp2="";
    for(int i=0;i<vec1.sizes();++i)
    {
        tmp1+=QString::number(vec1.find(i)->val);
        tmp2+=QString::number(vec2.find(i)->val);
        tmp2+="\n";
        tmp1+="\n";
    }
    ui->textEdit->setText(tmp1);
    ui->textEdit_2->setText(tmp2);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    h->insert((int)rand(),(int)rand());
    displ();
}


void MainWindow::on_pushButton_2_clicked()
{
    h->del(1);
    displ();
}


void MainWindow::on_pushButton_3_clicked()
{
    displ();
}


void MainWindow::on_pushButton_4_clicked()
{
    h->delete_ch();
    displ();
}

