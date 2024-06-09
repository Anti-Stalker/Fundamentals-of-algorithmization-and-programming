#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}
void MainWindow::showTable()
{
    ui->tableWidget->clear();

    QVector<QVector<int>> res = t.displayHash();

    ui->tableWidget->setRowCount(res.size());
    for (int i = 0; i < res.size(); ++i)
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem());

    for (int i = 0; i < res.size(); ++i)
        for (auto el : res[i])
            ui->tableWidget->item(i, 0)->setText(ui->tableWidget->item(i, 0)->text() + " " + QString::number(el));
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    t.insertItem(ui->spinBox->value(), ui->spinBox_2->value());

    showTable();
}


void MainWindow::on_pushButton_2_clicked()
{
    t.deleteItem(ui->spinBox->value());
    showTable();
}


void MainWindow::on_pushButton_3_clicked()
{
    t.clear();
    showTable();
}



void MainWindow::on_pushButton_4_clicked()
{
    ui->label_3->setText(QString::number(t.findMaxKey() + 1));

}

