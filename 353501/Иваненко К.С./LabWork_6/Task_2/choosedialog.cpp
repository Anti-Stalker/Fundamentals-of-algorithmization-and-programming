#include "choosedialog.h"
#include "ui_choosedialog.h"

#include <QPushButton>

ChooseDialog::ChooseDialog(const QString &options, const int  number, QWidget *parent)
    : QDialog(parent), ui(new Ui::ChooseDialog)
{
    ui->setupUi(this);

    ui->optionsTextEdit->setText(options);

    ui->chooseSpinBox->setMinimum(1);
    ui->chooseSpinBox->setMaximum(number);
}

ChooseDialog::~ChooseDialog()
{
    delete ui;
}

int ChooseDialog::getOption()
{
    return ui->chooseSpinBox->value();
}
