#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    enemy* FirstEnemy = &firstEnemy;

    enemy& SecondEnemy = secondEnemy;

    nullEnemy.paws = 4;
    nullEnemy.weight = 15;
    nullEnemy.isHouse = true;
    nullEnemy.firstNameSymbol = 'd';
    array_age[i] = 10;
    array_gender[i] = 'm';
    i++;
    Enemy.push_back(nullEnemy);

    FirstEnemy->paws = 4;
    FirstEnemy->weight = 5;
    FirstEnemy->isHouse = true;
    FirstEnemy->firstNameSymbol = 'c';
    array_age[i] = 2;
    array_gender[i] = 'w';
    i++;
    Enemy.push_back(*FirstEnemy);

    SecondEnemy.paws = 2;
    SecondEnemy.weight = 2;
    SecondEnemy.isHouse = false;
    SecondEnemy.firstNameSymbol = 'h';
    array_age[i] = 0.5;
    array_gender[i] = 'w';
    i++;

    Enemy.push_back(SecondEnemy);

    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);

    for (int i = 0; i < 3; i++){
        QTableWidgetItem* itemPaws = new QTableWidgetItem(QString::number(Enemy[i].paws));
        QTableWidgetItem* itemWeight = new QTableWidgetItem(QString::number(Enemy[i].weight));
        QTableWidgetItem* itemIsHouse = new QTableWidgetItem(Enemy[i].isHouse ? "Да" : "Нет");
        QTableWidgetItem* itemFirst = new QTableWidgetItem(QString(Enemy[i].firstNameSymbol));
        QTableWidgetItem* itemGender = new QTableWidgetItem(QString::number(array_age[i]));
        QTableWidgetItem* itemAge = new QTableWidgetItem(QString(array_gender[i]));

        ui->tableWidget->setItem(i, 0, itemPaws);
        ui->tableWidget->setItem(i, 1, itemWeight);
        ui->tableWidget->setItem(i, 2, itemIsHouse);
        ui->tableWidget->setItem(i, 3, itemFirst);
        ui->tableWidget->setItem(i, 4, itemAge);
        ui->tableWidget->setItem(i, 5, itemGender);
    }

    connect(ui->Add, &QPushButton::clicked, this, &MainWindow::myclick);

}

QChar MainWindow::array_gender[100];
double MainWindow::array_age[100];

void MainWindow::myclick(){
    nullEnemy.paws = ui->Paws->value();
    nullEnemy.weight = ui->Weight->value();
    if (ui->isHouse->isChecked()){
        nullEnemy.isHouse = true;
    }
    else
    {
        nullEnemy.isHouse = false;
    }
    QString buf = ui->FirstSymbol->text();
    if (buf.size() > 0){
    nullEnemy.firstNameSymbol = buf[0];
    }
    else {
    nullEnemy.firstNameSymbol = ' ';
    }
    array_age[i] = ui->Age->value();
    if (ui->m->isChecked()){
        array_gender[i+1] = 'm';
    }
    else {
        array_gender[i+1] = 'w';
    }
    i++;
    Enemy.push_back(nullEnemy);

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    QTableWidgetItem* itemPaws = new QTableWidgetItem(QString::number(Enemy[i].paws));
    QTableWidgetItem* itemWeight = new QTableWidgetItem(QString::number(Enemy[i].weight));
    QTableWidgetItem* itemIsHouse = new QTableWidgetItem(Enemy[i].isHouse ? "Да" : "Нет");
    QTableWidgetItem* itemFirst = new QTableWidgetItem(QString(Enemy[i].firstNameSymbol));
    QTableWidgetItem* itemGender = new QTableWidgetItem(QString::number(array_age[i]));
    QTableWidgetItem* itemAge = new QTableWidgetItem(QString(array_gender[i]));

    ui->tableWidget->setItem(i, 0, itemPaws);
    ui->tableWidget->setItem(i, 1, itemWeight);
    ui->tableWidget->setItem(i, 2, itemIsHouse);
    ui->tableWidget->setItem(i, 3, itemFirst);
    ui->tableWidget->setItem(i, 4, itemAge);
    ui->tableWidget->setItem(i, 5, itemGender);

    ui->tableWidget->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

