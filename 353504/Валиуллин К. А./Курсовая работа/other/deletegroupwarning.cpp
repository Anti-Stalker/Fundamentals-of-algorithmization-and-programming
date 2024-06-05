#include "other/deletegroupwarning.h"
#include "ui_deletegroupwarning.h"

DeleteGroupWarning::DeleteGroupWarning(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeleteGroupWarning)
{
    ui->setupUi(this);
}

DeleteGroupWarning::~DeleteGroupWarning()
{
    delete ui;
}

void DeleteGroupWarning::on_buttonBox_accepted()
{
    emit transmitDeletingConfirmation();
}

void DeleteGroupWarning::on_buttonBox_rejected()
{
    close();
}

