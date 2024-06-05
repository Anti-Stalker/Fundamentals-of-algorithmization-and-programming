#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_On_insert_2_clicked()
{
    std::string str = ui->inValue->text().toStdString();
    int key = ui->inBox_2->value();
    map.insert(key,str);
}


void MainWindow::on_On_delete_clicked()
{
    map.erase(ui->inBox_2->value());
}

void MainWindow::on_On_contains_clicked()
{

    QString str = "The table ";
    str += map.contains(ui->inBox_2->value())? " is contains " : " is not contains ";
    str += "the key " + QString::number(ui->inBox_2->value());
    ui->label->setText(str);
}

void MainWindow::on_On_print_clicked()
{
    ui->textEdit->setText(QString::fromStdString(map.toString()));
}

void MainWindow::on_On_clear_2_clicked()
{
    map.clear();
    ui->textEdit->clear();
}
