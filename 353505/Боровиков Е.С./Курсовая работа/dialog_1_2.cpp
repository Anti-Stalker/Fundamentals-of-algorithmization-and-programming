#include "dialog_1_2.h"
#include "ui_dialog_1_2.h"

dialog_1_2::dialog_1_2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialog_1_2)
{
    ui->setupUi(this);
    razmer = ui->spinBoxForRazmer_1_2->value();
    rost = ui->spinBoxForRost_1_2->value();
    massa = ui->spinBoxForMassa_1_2->value();
    tolst = ui->doubleSpinBox->value();
    compressionStrength = ice.getCompressionStrength(tolst);
    this->setStyleSheet("background-color: #E6FAE6;");
}

dialog_1_2::~dialog_1_2()
{
    delete ui;
}

void dialog_1_2::rezult()
{
    int height = 0;
    if(tolst<0.15){
        height = tolst*1000;
    }else{
        height = 150;
    }

    double r = razmer/2 + rost;
    double S = pi*r*r/100000000;
    P = (massa*g)/(S);
    qDebug()<<S;
    qDebug()<<P;
    qDebug()<<compressionStrength;
    if(P<compressionStrength){
        Dialog_2_2_1 okno_2_2_1(height,this);
        okno_2_2_1.showFullScreen();
        okno_2_2_1.exec();
    }else if(P>=compressionStrength){
        Dialog_2_2_2 okno_2_2_2(height,this);
        okno_2_2_2.showFullScreen();
        okno_2_2_2.exec();
    }
}

void dialog_1_2::on_rezult_clicked()
{
    razmer = ui->spinBoxForRazmer_1_2->value();
    rost = ui->spinBoxForRost_1_2->value();
    massa = ui->spinBoxForMassa_1_2->value();
    tolst = ui->doubleSpinBox->value();
    compressionStrength = ice.getCompressionStrength(tolst);
    rezult();
}


void dialog_1_2::on_pushButton_clicked()
{
    close();
}

