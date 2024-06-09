#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox_9->setRange(0, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    createByStr();
    createByVal();
    createByPtr();
    createByRef();
    createByUser();
}

void MainWindow::createByStr()
{
    Animal first = {13, 88.50, {'d', 'o', 'g'},{10, 10, 10, 10, 10, 20, 25}, 0, 'A'};
    QString firstStr(QString::number(first.age)  + " | " + QString::number(first.weight)  + " | " + QString(first.type)+ " | " + QString::number(first.wasFeedToday)  +  " | " + QString(first.aClass) +  " | " +  "[ ");
    for(int i = 0; i < first.daysInWeek; i++){
        firstStr += QString::number(first.foodPerDay[i]);
        firstStr += " ";
    }
    firstStr += ']';
    ui->textBrowser->append(firstStr);
}

void MainWindow::createByVal()
{
    Animal second;
    second.age = 11;
    second.weight = 6;
    second.type[0] = 'c';
    second.type[1] = 'a';
    second.type[2] = 't';
    second.wasFeedToday = true;
    for(int i = 0; i < second.daysInWeek; i++){
        second.foodPerDay[i] = 1;
    }
    second.aClass = 'B';
    QString secondStr(QString::number(second.age)  + " | " + QString::number(second.weight)  + " | " + QString(second.type)+ " | " + QString::number(second.wasFeedToday)  +  " | " + QString(second.aClass) +  " | "  + "[ ");
    for(int i = 0; i < second.daysInWeek; i++){
        secondStr += QString::number(second.foodPerDay[i]);
        secondStr += " ";
    }
    secondStr += ']';
    ui->textBrowser->append(secondStr);
}

void MainWindow::createByPtr()
{
    third = new Animal;
    third->age = 2;
    third->weight = 123;
    third->type[0] = 'r';
    third->type[1] = 'a';
    third->type[2] = 't';
    third->wasFeedToday = true;
    for(int i = 0; i < third->daysInWeek; i++){
        third->foodPerDay[i] = i % 2;
    }
    third->aClass = 'A';
    QString secondStr(QString::number(third->age)  + " | " + QString::number(third->weight)  + " | " + QString(third->type)+ " | " + QString::number(third->wasFeedToday)  +  " | " + QString(third->aClass) +  " | "  + "[ ");
    for(int i = 0; i < third->daysInWeek; i++){
        secondStr += QString::number(third->foodPerDay[i]);
        secondStr += " ";
    }
    secondStr += ']';
    ui->textBrowser->append(secondStr);

}

void MainWindow::createByRef()
{
    Animal first;
    Animal& second = first;
    second.age = 1;
    second.weight = 100;
    second.type[0] = 'c';
    second.type[1] = 'o';
    second.type[2] = 'w';
    second.wasFeedToday = true;
    for(int i = 0; i < second.daysInWeek; i++){
        second.foodPerDay[i] = 100;
    }
    second.aClass = 'B';
    QString secondStr(QString::number(second.age)  + " | " + QString::number(second.weight)  + " | " + QString(second.type)+ " | " + QString::number(second.wasFeedToday)  +  " | " + QString(second.aClass) +  " | "  + "[ ");
    for(int i = 0; i < second.daysInWeek; i++){
        secondStr += QString::number(second.foodPerDay[i]);
        secondStr += " ";
    }
    secondStr += ']';
    ui->textBrowser->append(secondStr);
}

void MainWindow::createByUser()
{
    Animal second;
    second.age = ui->spinBox_8->value();
    second.weight = ui->spinBox_9->value();
    QString str = ui->lineEdit->text();
    for(int i = 0; i < str.length(); i++)
    {
        second.type[i] = str[i];
    }
    second.wasFeedToday = true;
    for(int i = 0; i < second.daysInWeek; i++){
        second.foodPerDay[i] = 1;
    }
    second.aClass = ui->comboBox->currentIndex() == 0 ? 'A' : 'B';
    QString secondStr(QString::number(second.age)  + " | " + QString::number(second.weight)  + " | " + QString(second.type)+ " | " + QString::number(second.wasFeedToday)  +  " | " + QString(second.aClass) +  " | "  + "[ ");
    for(int i = 0; i < second.daysInWeek; i++){
        secondStr += QString::number(second.foodPerDay[i]);
        secondStr += " ";
    }
    secondStr += ']';
    ui->textBrowser->append(secondStr);
}

