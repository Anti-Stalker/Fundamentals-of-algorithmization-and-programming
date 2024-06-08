//
// Created by u on 31.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"


main_window::main_window(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::main_window)
{
    ui->setupUi(this);

    setWindowTitle("Двусторонняя очередь");
}

main_window::~main_window()
{
    delete ui;
}

void main_window::on_pushbackButton_clicked()
{
    deq.push_back(ui->spinBox->value());
    printDeq();
}


void main_window::on_popbackButton_2_clicked()
{
    deq.pop_back();
    printDeq();
}


void main_window::on_pushfrontButton_clicked()
{
    deq.push_front(ui->spinBox->value());
    printDeq();
}


void main_window::on_popfrontButton_clicked()
{
    deq.pop_front();
    printDeq();
}


void main_window::on_clearButton_clicked()
{
    deq.clear();
    printDeq();
}

void main_window::printDeq()
{
    ui->label->clear();
    for (auto el : deq) {
        ui->label->setText(ui->label->text() + " " + QString::number(el));
    }
}