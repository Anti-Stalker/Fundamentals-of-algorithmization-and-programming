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

void MainWindow::on_lineEdit_2_editingFinished()
{
    str2 = String(ui->lineEdit_2->text().toStdString().c_str());
}


void MainWindow::on_lineEdit_editingFinished()
{
    str1 = String(ui->lineEdit->text().toStdString().c_str());
}

void MainWindow::on_pushButton_clicked()
{
    str::memcpy(str1.begin(), str2.begin(), str2.size());

    ui->MemCpy_Label->setText(str1.begin());
}


void MainWindow::on_MemMove_clicked()
{
    str::memmove(str1.begin(), str2.begin(), str2.size());

    ui->MemMove_Label->setText(str1.begin());
}


void MainWindow::on_pushButton_2_clicked()
{
    str::strcpy(str1.begin(), str2.begin());

    ui->StrCopy_label->setText(str1.begin());
}


void MainWindow::on_StrCat_clicked()
{
    str::strcat(str1.begin(), str2.begin());

    ui->Strcat_Label->setText(str1.begin());
}


void MainWindow::on_MemCmp_clicked()
{
    int value = str::memcmp(str1.begin(), str2.begin(), str2.size());

    ui->Memcmp_Label->setNum(value);
}


void MainWindow::on_Strxfrm_clicked()
{
    int value = str::strxfrm(str1.begin(), str2.begin(), str2.size());

    ui->Strxfrm_Label->setNum(value);
    ui->Extra_Label->setText(str1.begin());
}


void MainWindow::on_Strtok_clicked()
{
    char* c = str::strtok(str1.begin(), str2.begin());

    ui->StrTok_Label->setText(c);
}

void MainWindow::on_Strlrn_clicked()
{
    int size = str::strlen(str1.begin());

    ui->Strlen_Label->setNum(size);
}

