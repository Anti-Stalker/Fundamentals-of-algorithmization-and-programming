#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Car carInitList = {0, 1, 2, true, "5", "6", 7, 8};
    qDebug() << QString::fromStdString(carInitList.to_string('|'));

    Car* carPtr = new Car{8, 8.005, 5, true, "3", "5", 3, 5};
    qDebug() << QString::fromStdString(carPtr->to_string('|'));

    Car& ref = carInitList;
    qDebug() << QString::fromStdString(ref.to_string('|'));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Car currCar = Car();
    currCar._maxAcceleration = ui->lineEdit->text().toInt();
    currCar._velocity = ui->lineEdit_2->text().toDouble();
    currCar._acceleration = ui->lineEdit_2->text().toInt();
    currCar._isMoving = ui->lineEdit_3->text().toInt();
    currCar._namesOfPassengers[0] = ui->lineEdit_4->text().toStdString().c_str();
    currCar._namesOfPassengers[1] = ui->lineEdit_5->text().toStdString().c_str();
    currCar._agesOfPassengers[0] = ui->lineEdit_6->text().toInt();
    currCar._agesOfPassengers[1] = ui->lineEdit_8->text().toInt();

    ui->textEdit->setText(QString::fromStdString(currCar.to_string('|')));
}

