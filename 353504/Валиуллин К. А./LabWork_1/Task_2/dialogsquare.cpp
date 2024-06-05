#include "dialogsquare.h"
#include "ui_dialogsquare.h"

DialogSquare::DialogSquare(QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogSquare)
{
    ui->setupUi(this);
}

DialogSquare::~DialogSquare()
{
    delete ui;
}

void DialogSquare::on_buttonBox_accepted()
{
    emit transmitValue(ui->spinBox_2->value());
}

