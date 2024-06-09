#include "mainwindow.h"
#include "./ui_mainwindow.h"

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


void MainWindow::on_pushButton_4_clicked()
{
    String s1, s2;
    s1 = ui->lineEdit->text().toLatin1().data();
    s2 = ui->lineEdit_2->text().toLatin1().data();
    ui->label_3->setText(QString::number(s1.length()));
    ui->label_4->setText(QString::number(s2.length()));
}


void MainWindow::on_pushButton_5_clicked()
{
    String s1, s2;
    s1 = ui->lineEdit->text().toLatin1().data();
    s2 = ui->lineEdit_2->text().toLatin1().data();
    ui->label_3->setText(QString::fromUtf8((s1 + s2).getData()));
    ui->label_4->setText(QString::fromUtf8((s2 + s1).getData()));
}


void MainWindow::on_pushButton_6_clicked()
{
    String s1, s2;
    s1 = ui->lineEdit->text().toLatin1().data();
    s2 = ui->lineEdit_2->text().toLatin1().data();
    ui->label_3->setText(QString::number(s1.compare(s2)));
    ui->label_4->setText(QString::number(s2.compare(s1)));

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label_3->setText((char *)memset(ui->lineEdit->text().toUtf8().data(),
                                         (int)'a', ui->lineEdit->text().size()));
    ui->label_4->setText((char *)memset(ui->lineEdit_2->text().toUtf8().data(),
                                         (int)'a', ui->lineEdit_2->text().size()));

}


void MainWindow::on_pushButton_clicked()
{

    ui->label_3->setText((char *)memcpy(ui->lineEdit->text().toUtf8().data(),
                                         ui->lineEdit_2->text().toUtf8().data(), std::min(ui->lineEdit->text().size(),ui->lineEdit_2->text().size())));
    ui->label_4->setText((char *)memcpy(ui->lineEdit_2->text().toUtf8().data(),
                                         ui->lineEdit->text().toUtf8().data(), std::min(ui->lineEdit->text().size(),ui->lineEdit_2->text().size())));
}


