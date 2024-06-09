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

void MainWindow::updateInfo()
{
    ui->textBrowser->clear();
    for(int i = 0; i < dq.size(); i++ )
    {
        ui->textBrowser->append(QString::number(dq[i]));
    }
}
void MainWindow::on_pushButton_clicked()
{
    if(!dq.empty())
        dq.pop_back();
    updateInfo();
    on_pushButton_6_clicked();
}


void MainWindow::on_pushButton_2_clicked()
{
    dq.push_back(ui->spinBox->value());
    updateInfo();
    on_pushButton_6_clicked();
}


void MainWindow::on_pushButton_3_clicked()
{
    if(!dq.empty())
        dq.pop_front();
    updateInfo();
    on_pushButton_6_clicked();
}


void MainWindow::on_pushButton_4_clicked()
{
    dq.push_front(ui->spinBox->value());
    updateInfo();
    on_pushButton_6_clicked();
}


void MainWindow::on_pushButton_5_clicked()
{
    dq.clear();
    updateInfo();
    on_pushButton_6_clicked();
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->label->setText(dq.empty() ? "empty " : "not empty " + QString::number(dq.size())) ;
}


void MainWindow::on_pushButton_7_clicked()
{
    on_pushButton_6_clicked();
}

