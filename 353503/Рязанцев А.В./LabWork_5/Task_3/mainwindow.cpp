#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setInputMask("00");
    ui->lineEdit_2->setInputMask("00");
    ui->lineEdit_Test->setInputMask("00");

    BitSet* set = new BitSet(10, 0);

    set->set(1);

    set->reset(1);

    qDebug() << set->none();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished()
{
    size = ui->lineEdit->text().toInt();
}


void MainWindow::on_lineEdit_2_editingFinished()
{
    num = ui->lineEdit_2->text().toInt();
}


void MainWindow::on_pushButton_clicked()
{
    if(!size){
        return;
    }
    if(!num){
        return;
    }

    set = new BitSet(size, num);

    ui->label_Result->setText(set->to_string());
}

void MainWindow::on_All_clicked()
{
    ui->label_Answer->setText(QString(set->all() ? "True" : "False"));
}


void MainWindow::on_Count_clicked()
{
    ui->label_Answer->setText(QString().setNum(set->count()));
}


void MainWindow::on_Flip_clicked()
{
    set->flip();

    ui->label_Result->setText(set->to_string());
}


void MainWindow::on_None_clicked()
{
    ui->label_Answer->setText(QString(set->any() ? "True" : "False"));
}



void MainWindow::on_Reset_clicked()
{
    set->reset();

    ui->label_Result->setText(set->to_string());
}


void MainWindow::on_Set_clicked()
{
    set->set();

    ui->label_Result->setText(set->to_string());
}



void MainWindow::on_Size_clicked()
{
    ui->label_Answer->setText(QString().setNum(set->getSize()));
}


void MainWindow::on_Test_clicked()
{
    size_t a = ui->lineEdit_Test->text().toInt();

    ui->label_Answer->setText(QString().setNum(set->test(a)));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->To_Ullong->setText(QString().setNum(set->to_ullong()));
}



void MainWindow::on_pushButton_3_clicked()
{
    ui->To_Ulong->setText(QString().setNum(set->to_ulong()));
}


void MainWindow::on_pushButton_4_clicked()
{
    qDebug() << sizeof(int);
}

