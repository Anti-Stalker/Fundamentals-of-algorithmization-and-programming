//
// Created by darina on 5/31/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(map_insert()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(map_find()));
    //connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(map_clear()));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(map_size()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(map_value()));

    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(set_insert()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(set_erase()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(set_find()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(set_clear()));
    connect(ui->pushButton_9, SIGNAL(clicked(bool)), this, SLOT(set_size()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::map_insert() {
    auto key = ui->plainTextEdit->toPlainText().toInt();
    auto value = ui->plainTextEdit_2->toPlainText().toInt();
    mapa[key] = value;
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit->clear();
    Display();
}

void mainwindow::map_clear() {
    mapa.clear();
    Display();
}

void mainwindow::map_find() {
    auto key = ui->plainTextEdit->toPlainText().toInt();
    ui->plainTextEdit->setPlainText(QString::number(mapa.contains(key)));
    Display();
}

void mainwindow::map_size() {
    ui->plainTextEdit_3->setPlainText(QString::number(mapa.size()));
}

void mainwindow::set_insert() {
    auto key = ui->plainTextEdit->toPlainText().toInt();
    seta.insert(key);
    ui->plainTextEdit->clear();
    Display();
}

void mainwindow::set_erase() {
    auto key = ui->plainTextEdit->toPlainText().toInt();
    seta.erase_key(key);
    ui->plainTextEdit->clear();
    Display();

}

void mainwindow::set_find() {
    auto key = ui->plainTextEdit->toPlainText().toInt();
    ui->plainTextEdit->setPlainText(QString::number(seta.find(key)));
    Display();
}

void mainwindow::set_clear() {
    seta.clear();
    Display();
}

void mainwindow::set_size() {
    ui->plainTextEdit_3->setPlainText(QString::number(seta.size()));
}

void mainwindow::map_value() {
    auto key = ui->plainTextEdit->toPlainText().toInt();
    ui->plainTextEdit->clear();
    ui->plainTextEdit_3->setPlainText(QString::number(mapa[key]));
    Display();
}

void mainwindow::Display() {
    auto v = mapa.GetTree();
    ui->plainTextEdit_4->clear();
    for(auto x : v)
    {
        ui->plainTextEdit_4->appendPlainText("{" + QString::number(x.first.first) + " " + QString::number(x.first.second) + "}");
    }
    v = seta.GetTree();
    ui->plainTextEdit_5->clear();
    for(auto x : v)
    {
        ui->plainTextEdit_5->appendPlainText(QString::number(x.first.first));
    }
}
