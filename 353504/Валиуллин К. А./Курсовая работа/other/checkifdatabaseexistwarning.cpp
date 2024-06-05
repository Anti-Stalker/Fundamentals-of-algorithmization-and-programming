#include "checkifdatabaseexistwarning.h"
#include "ui_checkifdatabaseexistwarning.h"

CheckIfDatabaseExistWarning::CheckIfDatabaseExistWarning(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CheckIfDatabaseExistWarning)
{
    ui->setupUi(this);
}

CheckIfDatabaseExistWarning::~CheckIfDatabaseExistWarning()
{
    delete ui;
}

void CheckIfDatabaseExistWarning::on_buttonBox_accepted()
{
    emit transmitCheckIfDbExistConfirmation();
}

void CheckIfDatabaseExistWarning::on_buttonBox_rejected()
{
    close();
}
