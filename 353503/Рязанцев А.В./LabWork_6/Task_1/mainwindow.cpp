#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineName->setVisible(false);
    ui->lineModel->setVisible(false);
    ui->linePrice->setVisible(false);
    ui->lineNewness->setVisible(false);

    ui->CreateButton->setVisible(false);

    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonTask_1_clicked()
{
    Toy Car = Toy(1,10,true, "Car");

    Toy Plane;

    Plane._age = 19;
    Plane._price = 1231.23;
    Plane._isForChildern = false;
    Plane._name = "Plane";

    qDebug() << PrintInfo(Car);
    qDebug() << PrintInfo(Plane);
}

QString MainWindow::PrintInfo(const Toy &item)
{
    QString Line = "Name: " + item._name +
                   " | Model: " + QString::number(item._age) +
                   " | Price: " + QString::number(item._price) +
                   " | Is for kids: ";

    if(item._isForChildern){
        Line += "true";
    }else{
        Line += "false";
    }

    return Line;
}

bool MainWindow::CheckNum(QLineEdit *line)
{
    for(auto &el : line->text()){
        if(!el.isDigit()){
            return false;
        }
    }

    return true;
}


void MainWindow::on_pushButton_clicked()
{
    ui->lineName->setVisible(true);
    ui->lineModel->setVisible(true);
    ui->linePrice->setVisible(true);
    ui->lineNewness->setVisible(true);

    ui->CreateButton->setVisible(true);

    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);
}


void MainWindow::on_CreateButton_clicked()
{
    if(!CheckNum(ui->lineModel)){
        return;
    }
    if(!CheckNum(ui->linePrice)){
        return;
    }
    if(ui->lineNewness->text() != "True" && ui->lineNewness->text() != "true" && ui->lineNewness->text() != "False" && ui->lineNewness->text() != "false"
        && ui->lineNewness->text() != "Yes" && ui->lineNewness->text() != "yes" && ui->lineNewness->text() != "No" && ui->lineNewness->text() != "no"){
        return;
    }

    Toy item;
    item._age = ui->lineModel->text().toInt();
    item._price = ui->linePrice->text().toInt();
    item._name = ui->lineName->text();

    if(ui->lineNewness->text() == "True" || ui->lineNewness->text() == "true" ||ui->lineNewness->text() == "Yes" || ui->lineNewness->text() == "yes"){
        item._isForChildern = true;
    }
    else if(ui->lineNewness->text() != "False" || ui->lineNewness->text() != "false" || ui->lineNewness->text() != "No" || ui->lineNewness->text() != "no"){
        item._isForChildern = false;
    }


    qDebug() << PrintInfo(item);
}


void MainWindow::on_Task_3_clicked()
{
    Toy item;
    Toy *pt = &item;

    pt->_age = 10;
    pt->_price = 50.6;
    pt->_name = "Cube";
    pt->_isForChildern = true;

    qDebug() << PrintInfo(*pt);
}


void MainWindow::on_Task_4_clicked()
{
    Toy item;
    Toy &ref = item;

    ref._name = "Truck";
    ref._age = 1;
    ref._price = 9.99;
    ref._isForChildern = "false";

    qDebug() << PrintInfo(ref);
}

