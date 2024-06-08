//
// Created by darina on 5/29/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(do_push_back()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(do_push_front()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(do_pop_back()));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(do_pop_front()));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(do_at()));
    connect(ui->pushButton_6, SIGNAL(clicked(bool)), this, SLOT(do_squares()));
    connect(ui->pushButton_7, SIGNAL(clicked(bool)), this, SLOT(do_equales()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(do_clear()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::do_push_back() {
    auto t = ui->plainTextEdit->toPlainText().toInt();
    d.push_back(t);
    ui->plainTextEdit->clear();
    Display();
}

void mainwindow::do_pop_back() {
    auto t = d.pop_back();
    ui->plainTextEdit_2->setPlainText(QString::number(t));
    Display();
}

void mainwindow::do_push_front() {
    auto t = ui->plainTextEdit->toPlainText().toInt();
    d.push_front(t);
    ui->plainTextEdit->clear();
    Display();
}

void mainwindow::do_pop_front() {
    auto t = d.pop_front();
    ui->plainTextEdit_2->setPlainText(QString::number(t));
    Display();
}

void mainwindow::show_size() {
    ui->plainTextEdit_4->setPlainText(QString::number(d.size()));
}

void mainwindow::show_empty() {
    if(d.empty())
    {
        ui->plainTextEdit_5->setPlainText("true");
    }
    else
    {
        ui->plainTextEdit_5->setPlainText("false");
    }
}

void mainwindow::do_at() {
    auto t = ui->spinBox->value();
    ui->plainTextEdit_3->setPlainText(QString::number(d.at(t)));
}

void mainwindow::do_squares() {
    auto t = ui->spinBox->value();
    std::cout << t << " " << d[t] << '\n';
    ui->plainTextEdit_3->setPlainText(QString::number(d[t]));
}

void mainwindow::do_equales() {
    auto i = ui->spinBox->value();
    auto value = ui->plainTextEdit_3->toPlainText().toInt();
    d[i] = value;
    Display();
    ui->plainTextEdit_3->clear();
}

void mainwindow::Display() {
    QString s;
    for(int i = 0; i < d.size(); i ++)
    {
        s = s + QString::number(d[i]) + " ";
    }
    ui->label_3->setText(s);
    show_empty();
    show_size();
}

void mainwindow::do_clear() {
    d.clear();
    Display();
}
