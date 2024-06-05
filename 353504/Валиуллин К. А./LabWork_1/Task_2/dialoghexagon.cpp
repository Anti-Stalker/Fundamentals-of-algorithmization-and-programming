#include "dialoghexagon.h"
#include "ui_dialoghexagon.h"

DialogHexagon::DialogHexagon(QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogHexagon)
{
    ui->setupUi(this);
}

DialogHexagon::~DialogHexagon()
{
    delete ui;
}

void DialogHexagon::on_buttonBox_accepted()
{
    emit transmitValue(ui->spinBox->value());
}

