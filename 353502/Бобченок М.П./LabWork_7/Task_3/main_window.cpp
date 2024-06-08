//
// Created by u on 31.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"


void main_window::on_pushButton_clicked()
{
    table.insertItem(ui->spinBox->value(), ui->spinBox_2->value());
    showTable();
}

void main_window::on_pushButton_2_clicked()
{
    table.deleteItem(ui->spinBox->value());
    showTable();
}


void main_window::on_pushButton_3_clicked()
{
    table.deleteEvenKeys();
    showTable();
}


void main_window::showTable()
{
    ui->tableWidget->clear();

    QVector<QVector<int>> res = table.displayHash();

    ui->tableWidget->setRowCount(res.size());
    for (int i = 0; i < res.size(); ++i)
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem());

    for (int i = 0; i < res.size(); ++i)
        for (auto el : res[i])
            ui->tableWidget->item(i, 0)->setText(ui->tableWidget->item(i, 0)->text() + " " + QString::number(el));
}

main_window::main_window(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::main_window)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    showTable();
}

main_window::~main_window()
{
    delete ui;
}

