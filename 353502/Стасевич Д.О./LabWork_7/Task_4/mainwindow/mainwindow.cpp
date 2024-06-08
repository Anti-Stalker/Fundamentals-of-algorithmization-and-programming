//
// Created by darina on 5/28/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    srand(time(0));
    for(int i = 0; i < 200; i ++)
    {
        int sz = rand() % 30 + 1;
        std::string add;
        for(int j = 0; j < sz; j ++)
        {
            add = add + (char)(rand() % 26 + 'a');
        }
        h16->insert(add);
        h64->insert(add);
        h128->insert(add);
        h2048->insert(add);
    }
    DisplayCollisions();

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(add_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(remove_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(find_clicked()));

}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::DisplayCollisions() {
    auto v = h16->GetCollisions();
    ui->plainTextEdit->clear();
    for(int i = 0; i < v.size(); i ++)
    {
        ui->plainTextEdit->appendPlainText(QString::fromStdString(v[i].second) + " key " + QString::number(v[i].first));
    }
    v = h64->GetCollisions();
    ui->plainTextEdit_2->clear();
    for(int i = 0; i < v.size(); i ++)
    {
        ui->plainTextEdit_2->appendPlainText(QString::fromStdString(v[i].second) + " key " + QString::number(v[i].first));
    }
    v = h128->GetCollisions();
    ui->plainTextEdit_3->clear();
    for(int i = 0; i < v.size(); i ++)
    {
        ui->plainTextEdit_3->appendPlainText(QString::fromStdString(v[i].second) + " key " + QString::number(v[i].first));
    }
    v = h2048->GetCollisions();
    ui->plainTextEdit_4->clear();
    for(int i = 0; i < v.size(); i ++)
    {
        ui->plainTextEdit_4->appendPlainText(QString::fromStdString(v[i].second) + " key " + QString::number(v[i].first));
    }
}

void mainwindow::add_clicked() {
    std::string s = ui->plainTextEdit_5->toPlainText().toStdString();
    h16->insert(s);
    h64->insert(s);
    h128->insert(s);
    h2048->insert(s);
    ui->plainTextEdit_5->clear();
    DisplayCollisions();
}

void mainwindow::remove_clicked() {
    std::string s = ui->plainTextEdit_5->toPlainText().toStdString();
    bool t = h16->remove(s);
    h64->remove(s);
    h128->remove(s);
    h2048->remove(s);
    if(!t)
    {
        ui->plainTextEdit_5->setPlainText("Element not found");
    }
    else
    {
        ui->plainTextEdit_5->setPlainText("Deleted");
    }
    DisplayCollisions();
}

void mainwindow::find_clicked() {
    std::string s = ui->plainTextEdit_5->toPlainText().toStdString();
    int a, b, c, d;
    clock_t st = clock();
    a = h16->findItem(s);
    clock_t fin = clock();
    std::cout << fin << " " << st << " " << CLOCKS_PER_SEC << '\n';
    ui->label_2->setText(QString::number((fin - st) * 100 * 10000 / CLOCKS_PER_SEC) + " ms");
    st = clock();
    b = h64->findItem(s);
    fin = clock();
    ui->label_3->setText(QString::number((fin - st) * 100 * 10000 / CLOCKS_PER_SEC) + " ms");
    st = clock();
    c = h128->findItem(s);
    fin = clock();
    ui->label_4->setText(QString::number((fin - st) * 100 * 10000 / CLOCKS_PER_SEC) + " ms");
    st = clock();
    d = h2048->findItem(s);
    fin = clock();
    ui->label_5->setText(QString::number((fin - st) * 100 * 10000 / CLOCKS_PER_SEC) + " ms");
    ui->plainTextEdit_5->setPlainText(QString::number(a) + " " + QString::number(b) + " " + QString::number(c) + " " + QString::number(d));
}
