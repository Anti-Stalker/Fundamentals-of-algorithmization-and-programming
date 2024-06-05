#include "dialogsetxy.h"
#include "ui_dialogsetxy.h"

DialogSetXY::DialogSetXY(QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogSetXY)
{
    ui->setupUi(this);
}

DialogSetXY::~DialogSetXY()
{
    delete ui;
}

void DialogSetXY::on_buttonBox_accepted()
{
    valuesNewXY XY;
    XY.x = ui->XX->value();
    XY.y = ui->YY->value();
    emit transmitValue(XY);
}
