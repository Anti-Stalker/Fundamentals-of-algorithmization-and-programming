#include "dialogrhombus.h"
#include "ui_dialogrhombus.h"

DialogRhombus::DialogRhombus(QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogRhombus)
{
    ui->setupUi(this);
}

DialogRhombus::~DialogRhombus()
{
    delete ui;
}

void DialogRhombus::on_buttonBox_accepted()
{
    sideAndAngleCoordinates coordinates;
    coordinates.side1 = ui->Side1Box->value();
    coordinates.side2 = ui->Side2Box->value();
    emit rhombusValues(coordinates);
}

void DialogRhombus::on_buttonBox_rejected()
{
    rejectPushed = true;
}

