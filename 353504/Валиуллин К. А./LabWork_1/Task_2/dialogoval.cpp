#include "dialogoval.h"
#include "ui_dialogoval.h"

DialogOval::DialogOval(QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogOval)
{
    ui->setupUi(this);
}

DialogOval::~DialogOval()
{
    delete ui;
}

void DialogOval::on_buttonBox_accepted()
{
    valuesOfOval values;
    values.r1 = ui->spinBox->value();
    values.r2 = ui->spinBox_2->value();
    emit transmitValues(values);
}

