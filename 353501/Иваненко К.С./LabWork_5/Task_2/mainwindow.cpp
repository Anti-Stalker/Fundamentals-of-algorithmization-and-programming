#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystring.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_3->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_strlenbutton_clicked()
{
    string s = ui->lineEdit->text().toStdString();
    ui->lineEdit_3->setText(QString::number(mstrlen(s.begin().def_it)));
}
void MainWindow::on_strcpybutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2 = s + ui->lineEdit_2->text().toStdString();
    ui->lineEdit_3->setText(QString(mstrcpy(s2.data(),s.data())));
}

void MainWindow::on_strncpybutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2 = s + ui->lineEdit_2->text().toStdString();
    ui->lineEdit_3->setText(mstrncpy(s.data(),s2.data(),ui->strncpyspinbox->value()));
}


void MainWindow::on_strcatbutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2 = s + ui->lineEdit_2->text().toStdString();
    qDebug()<<s.data()<<" "<<s2.data()<<" "<<s.length()<<" "<<s2.length();
    ui->lineEdit_3->setText(QString(mstrcat(s.data(),s2.data())));
}


void MainWindow::on_strncatbutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2 = s + ui->lineEdit_2->text().toStdString();
    ui->lineEdit_3->setText(QString(mstrncat(s.data(),s2.data(),ui->strncatspinbox->value())));
}



void MainWindow::on_strcmpbutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2 = ui->lineEdit_2->text().toStdString();
    ui->lineEdit_3->setText(QString::number(mstrcmp(s.data(),s2.data())));
}



void MainWindow::on_strncmpbutton_clicked()
{
    string s =  ui->lineEdit->text().toStdString();
    string s2 = ui->lineEdit_2->text().toStdString();
    ui->lineEdit_3->setText(QString::number(mstrncmp(s.data(),s2.data(),ui->strncmpspinbox->value())));
}



void MainWindow::on_strerrbutton_clicked()
{
    ui->lineEdit_3->setText(QString(mstrerror(ui->strerrspinbox->value())));
}
