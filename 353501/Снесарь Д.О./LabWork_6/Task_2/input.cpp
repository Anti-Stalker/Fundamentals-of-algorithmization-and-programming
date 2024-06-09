#include "input.h"
#include "ui_input.h"

input::input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::input)
{
    ui->setupUi(this);
}

input::~input()
{
    delete ui;
}
void input::createByUser()
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
    a = second;
    b = secondStr;
    emit enter(b, a);

}

void input::on_pushButton_clicked()
{
    createByUser();
    this->close();
}

