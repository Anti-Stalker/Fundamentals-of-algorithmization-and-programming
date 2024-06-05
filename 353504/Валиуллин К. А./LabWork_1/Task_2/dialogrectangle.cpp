#include "dialogrectangle.h"
#include "ui_dialogrectangle.h"

DialogRectangle::DialogRectangle(QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogRectangle)
{
    ui->setupUi(this);
}

DialogRectangle::~DialogRectangle()
{
    delete ui;
}

void DialogRectangle::on_buttonBox_accepted()
{
    sidesValues sides;
    sides.side1 = ui->spinBox->value();
    sides.side2 = ui->spinBox_2->value();
    emit transmitValues(sides);
}

