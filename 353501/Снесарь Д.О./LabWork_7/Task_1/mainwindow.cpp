#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setRange(-100, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::on_pushButton_6_clicked()
{
    dq.pushBack(ui->spinBox->value());
    ui->textBrowser->clear();
    ui->textBrowser->append(QString::fromStdString(dq.toString()));


}


void MainWindow::on_pushButton_7_clicked()
{
    dq.clear();
    dqP.clear();
    dqM.clear();
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_3->clear();

}


void MainWindow::on_pushButton_8_clicked()
{
    dq.popBack();
    ui->textBrowser->clear();
    ui->textBrowser->append(QString::fromStdString(dq.toString()));

}


void MainWindow::on_pushButton_10_clicked()
{
    while(!dq.isEmpty())
    {
        if(dq.tail->data >= 0)
        {
            dq.popFromBackToBackQ(dqP);
            qDebug()<<"p"<<dq.Size();

        }
        else
        {
            dq.popFromBackToBackQ(dqM);
              qDebug()<<"m";
        }
    }
    ui->textBrowser->clear();
    ui->textBrowser->append(QString::fromStdString(dq.toString()));

    ui->textBrowser_2->clear();
    ui->textBrowser_2->append(QString::fromStdString(dqP.toString()));

    ui->textBrowser_3->clear();
    ui->textBrowser_3->append(QString::fromStdString(dqM.toString()));

}

