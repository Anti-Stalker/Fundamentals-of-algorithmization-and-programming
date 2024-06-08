//
// Created by darina on 5/25/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

struct Continent {
    int population;
    double area;
    char climate;
    bool hasMountains;
    static const int maxnameContinentLength = 200;
    char nameContinent[maxnameContinentLength];
    static const int maxCities = 10000;
    int cities;
};

mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    Continent Europe = {741000, 10180000.0, 'C', true, "Европа", 35};
    ui->label->setText("Континент 1. " + QString::number(Europe.population) + "|" + QString::number(Europe.area) + "|" + Europe.climate + "|" + QString::number(Europe.hasMountains) + "|" + Europe.nameContinent + "|" + QString::number(Europe.cities));

    Continent America;
    America.population = 1002000000;
    America.area = 42549000.0;
    America.climate = 'D';
    America.hasMountains = true;
    strcpy(America.nameContinent, "Аме́рика");
    America.cities = 44;
    ui->label_2->setText("Континент 2. " + QString::number(America.population) + "|" + QString::number(America.area) + "|" + America.climate + "|" + QString::number(America.hasMountains) + "|" + America.nameContinent + "|" + QString::number(America.cities));

    Continent Antarctida;
    Continent* ptr = &Antarctida;
    ptr->population = 1000;
    ptr->area = 14107000.0;
    ptr->climate = 'C';
    ptr->hasMountains = true;
    strcpy(ptr->nameContinent, "Антарктика");
    ptr->cities = 0;
    ui->label_3->setText("Континент 3. " + QString::number(ptr->population) + "|" + QString::number(ptr->area) + "|" + ptr->climate + "|" + QString::number(ptr->hasMountains) + "|" + ptr->nameContinent + "|" + QString::number(ptr->cities));


    Continent Australia;
    Continent &add = Australia;
    add.population = 26010000;
    add.area = 7700000.0;
    add.climate = 'H';
    add.hasMountains = true;
    strcpy(add.nameContinent, "Австралия");
    add.cities = 5;
    ui->label_4->setText("Континент 4. " + QString::number(add.population) + "|" + QString::number(add.area) + "|" + add.climate + "|" + QString::number(add.hasMountains) + "|" + add.nameContinent + "|" + QString::number(add.cities));

    ui->pushButton_2->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->plainTextEdit->hide();
    ui->plainTextEdit_2->hide();
    ui->plainTextEdit_3->hide();
    ui->plainTextEdit_4->hide();
    ui->plainTextEdit_5->hide();
    ui->plainTextEdit_6->hide();

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(add_user_struct()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(display_clicked()));

}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::add_user_struct() {
    ui->pushButton->hide();
    ui->pushButton_2->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->label_10->show();
    ui->label_11->show();
    ui->label_12->show();
    ui->plainTextEdit->show();
    ui->plainTextEdit_2->show();
    ui->plainTextEdit_3->show();
    ui->plainTextEdit_4->show();
    ui->plainTextEdit_5->show();
    ui->plainTextEdit_6->show();

}

void mainwindow::display_clicked() {
    Continent new_continent;
    new_continent.population = ui->plainTextEdit->toPlainText().toInt();
    new_continent.area = ui->plainTextEdit_2->toPlainText().toDouble();
    new_continent.climate = ui->plainTextEdit_3->toPlainText().toStdString()[0];
    new_continent.hasMountains = ui->plainTextEdit_4->toPlainText().toInt();
    std::string a = ui->plainTextEdit_5->toPlainText().toStdString();
    char b[a.size() + 1];
    for(int i = 0; i < a.size(); i ++)
        b[i] = a[i];
    b[a.size()] = '\0';
    strcpy(new_continent.nameContinent, b);
    new_continent.cities = ui->plainTextEdit_6->toPlainText().toInt();

    ui->pushButton->show();
    ui->pushButton_2->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->plainTextEdit->hide();
    ui->plainTextEdit_2->hide();
    ui->plainTextEdit_3->hide();
    ui->plainTextEdit_4->hide();
    ui->plainTextEdit_5->hide();
    ui->plainTextEdit_6->hide();

    ui->label_5->setText("Континент 5. " + QString::number(new_continent.population) + "|" + QString::number(new_continent.area) + "|" + new_continent.climate + "|" + QString::number(new_continent.hasMountains) + "|" + new_continent.nameContinent + "|" + QString::number(new_continent.cities));



}
