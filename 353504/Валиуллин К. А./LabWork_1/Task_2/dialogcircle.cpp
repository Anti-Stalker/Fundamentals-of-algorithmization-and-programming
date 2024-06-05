#include "dialogcircle.h"
#include "ui_dialogcircle.h"

DialogCircle::DialogCircle(QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogCircle)
{
    ui->setupUi(this);
}

DialogCircle::~DialogCircle()
{
    delete ui;
}

void DialogCircle::on_buttonBox_accepted()
{
    emit circleValue(ui->spinBox->value());
}

void DialogCircle::on_checkBox_stateChanged(int arg1)
{
    emit transmitRotation(ui->checkBox->isChecked());
}

