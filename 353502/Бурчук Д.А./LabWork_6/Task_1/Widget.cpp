#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    QRegExp regex = QRegExp(R"((\d+)\s(\d+\.\d+)\s([A-Za-z])\s(\d+)\s(\S+)\s(\d+))");


    this->validator = new QRegExpValidator(regex);
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_evaluateButton_clicked() {
    QString input_text = ui->inputLineEdit->text();
    int pos = 0;
    if (this->validator->validate(input_text, pos) != QValidator::Acceptable) {
        ui->lineEdit_1->setText("Error");
        ui->lineEdit_2->setText("Error");
        ui->lineEdit_3->setText("Error");
        ui->lineEdit_4->setText("Error");
        QTimer::singleShot(600, this, SLOT(setSpace()));
        return;
    }
    Motorbike constructed_in_line(input_text);

    Motorbike motorbike_1;
    motorbike_1.mileage = 1000;
    motorbike_1.max_speed = 120;
    motorbike_1.type = 'L';
    motorbike_1.isWoundUp = false;
    motorbike_1.brand = new char[strlen("Sport") + 1];
    strcpy(motorbike_1.brand, "Sport");
    motorbike_1.lastModelNumber = 215623;

    Motorbike *motorbike_2 = new Motorbike;
    motorbike_2->mileage = 345;
    motorbike_2->max_speed = 200;
    motorbike_2->type = 'H';
    motorbike_2->isWoundUp = true;
    motorbike_2->brand = new char[strlen("Harley") + 1];
    strcpy(motorbike_2->brand, "Harley");
    motorbike_2->lastModelNumber = 666997;

    Motorbike motorbike_3;
    Motorbike &motorbike_3_1 = motorbike_3;
    motorbike_3_1.mileage = 4500;
    motorbike_3_1.max_speed = 70;
    motorbike_3_1.type = 'O';
    motorbike_3_1.isWoundUp = false;
    motorbike_3_1.brand = new char[strlen("Minsk") + 1];
    strcpy(motorbike_3_1.brand, "Minsk");
    motorbike_3_1.lastModelNumber = 969102;

    QString list[4];
    list[0] = constructed_in_line.print();
    list[1] = motorbike_1.print();
    list[2] = motorbike_2->print();
    list[3] = motorbike_3_1.print();
    print(list);
}

void Widget::setSpace() {
    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
}

void Widget::print(QString list[]) {

    ui->lineEdit_1->setText(list[0]);
    ui->lineEdit_2->setText(list[1]);
    ui->lineEdit_3->setText(list[2]);
    ui->lineEdit_4->setText(list[3]);
}
