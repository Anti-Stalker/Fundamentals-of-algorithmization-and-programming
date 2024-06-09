#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    coolBitset = new Bitset(129);
    for(int i = 0; i < coolBitset->size(); i++){

        if (QRandomGenerator::global()->generate() % 2)
        coolBitset->set(i);
    }

    ui->textBrowser->setText(coolBitset->to_string());
  //  ui->textBrowser->setStyleSheet("text-align: center;");
    ui->spinBox->setRange(0, 127);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(coolBitset->all())
        ui->label->setText("true");
    else
        ui->label->setText("false");
}


void MainWindow::on_pushButton_2_clicked()
{
    if(coolBitset->any())
        ui->label->setText("true");
    else
        ui->label->setText("false");
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText(QString::number(coolBitset->count()));

}


void MainWindow::on_pushButton_4_clicked()
{
    coolBitset->flip(ui->spinBox->value());
    ui->textBrowser->setText(coolBitset->to_string());
}


void MainWindow::on_pushButton_5_clicked()
{
    if(coolBitset->none())
        ui->label->setText("true");
    else
        ui->label->setText("false");
}


void MainWindow::on_pushButton_6_clicked()
{
    coolBitset->reset(ui->spinBox->value());
    ui->textBrowser->setText(coolBitset->to_string());
}


void MainWindow::on_pushButton_7_clicked()
{
    coolBitset->set(ui->spinBox->value());
    ui->textBrowser->setText(coolBitset->to_string());
}


void MainWindow::on_pushButton_8_clicked()
{
    int gg = coolBitset->size();
    ui->label->setText(QString::number(gg));
}


void MainWindow::on_pushButton_9_clicked()
{
    if(coolBitset->test(ui->spinBox->value()))
        ui->label->setText("true");
    else
        ui->label->setText("false");
}


void MainWindow::on_pushButton_12_clicked()
{
    coolBitset->reset();
    ui->textBrowser->setText(coolBitset->to_string());
}


void MainWindow::on_pushButton_10_clicked()
{
    coolBitset->flip();
    ui->textBrowser->setText(coolBitset->to_string());

}


void MainWindow::on_pushButton_11_clicked()
{
    coolBitset->set();
    ui->textBrowser->setText(coolBitset->to_string());
}

