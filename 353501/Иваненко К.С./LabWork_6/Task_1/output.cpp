#include "output.h"
#include "ui_output.h"

#include <QPushButton>

Output::Output(const QString &output, QWidget *parent)
    : QDialog(parent), ui(new Ui::Output)
{
    ui->setupUi(this);

    ui->out->setText(output);

}

Output::~Output()
{
    delete ui;
}
