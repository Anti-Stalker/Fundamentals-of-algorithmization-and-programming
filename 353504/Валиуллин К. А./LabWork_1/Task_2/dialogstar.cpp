#include "dialogstar.h"
#include "ui_dialogstar.h"

DialogStar::DialogStar(QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogStar)
{
    ui->setupUi(this);
}

DialogStar::~DialogStar()
{
    delete ui;
}

void DialogStar::on_buttonBox_accepted()
{
    valuesOfStar values;
    values.tip = ui->buttonGroup->checkedId();
    values.side = ui->spinBox->value();
    emit transmitValues(values);
}

