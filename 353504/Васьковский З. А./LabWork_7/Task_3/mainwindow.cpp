#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
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
    t.pair1.resize(0);
    t.pair2.resize(0);
    t.pair3.resize(0);
    t.pr_ord(t.n1());
    t.p_ord(t.n1());
    t.in_ord(t.n1());
    ui->textEdit->setText("значения ");
    QString tmp=ui->textEdit->toPlainText();
    for(int i=0;i<t.pair1.size();++i)
    {

        tmp+=t.pair1[i].first;
        tmp+=" ";
    }
    tmp+="\n ключи";
    for(int i=0;i<t.pair1.size();++i)
    {

        tmp+=QString::number(t.pair1[i].second);
        tmp+=" ";
    }
    ui->textEdit->setText(tmp);
    ui->textEdit_2->setText("значения ");
    tmp=ui->textEdit_2->toPlainText();
    for(int i=0;i<t.pair2.size();++i)
    {

        tmp+=t.pair2[i].first;
        tmp+=" ";
    }
    tmp+="\n ключи";
    for(int i=0;i<t.pair2.size();++i)
    {

        tmp+=QString::number(t.pair2[i].second);
        tmp+=" ";
    }
    ui->textEdit_2->setText(tmp);
    ui->textEdit_3->setText("значения ");
    tmp=ui->textEdit_3->toPlainText();
    for(int i=0;i<t.pair3.size();++i)
    {

        tmp+=t.pair3[i].first;
        tmp+=" ";
    }
    tmp+="\n ключи";
    for(int i=0;i<t.pair3.size();++i)
    {

        tmp+=QString::number(t.pair3[i].second);
        tmp+=" ";
    }
    ui->textEdit_3->setText(tmp);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit_4->clear();
    QString tmp=ui->textEdit_4->toPlainText();
    tmp=tmp+"ключ " + QString::number(tmp1)+ " значение " + v+"\n";
    t.ins(tmp1,v);
    tmp1=rand();
    v+="bg";
    ui->textEdit_4->setText(tmp);

}


void MainWindow::on_pushButton_3_clicked()
{
    t.del(t.n1(),tmp1);
    tmp1-=10;
}


void MainWindow::on_pushButton_4_clicked()
{
    t.find(t.n1(),tmp1);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit_4->clear();
    QString tmp;
    t.count();
    for(int i=0;i<t.ret().size();++i)
    {
        tmp+=t.ret()[i];
    }
    ui->textEdit_4->setText(tmp);
}
