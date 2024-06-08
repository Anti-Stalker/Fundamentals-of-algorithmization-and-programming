#include "mainwindow.h"
#include "town.h"
#include "ui_mainwindow.h"
#include "output.h"

MainWindow::MainWindow()
    : ui(new Ui::MainWindow), town(new Town)
{
  ui->setupUi(this);

  fillUiFromStruct();
  ui->regionLineEdit->setMaxLength(1);

  connect(ui->nameLineEdit, &QLineEdit::textChanged, [&](QString newVal)
          { town->setName(newVal); });
  connect(ui->populationSpinBox, &QSpinBox::valueChanged, [&](int newVal)
          { town->setPopulation(newVal); });
  connect(ui->areaSpinBox, &QDoubleSpinBox::valueChanged, [&](double newVal)
          { town->setArea(newVal); });
  connect(ui->regionLineEdit, &QLineEdit::textChanged, [&](QString newVal)
          { (newVal != "") ? town->setRegion(newVal[0]) : town->setRegion(' '); });
  connect(ui->isCapitalCheckBox, &QCheckBox::stateChanged, [&](int checked)
          { town->setIsCapital(checked == Qt::Checked); });
  connect(ui->spinBox_1, &QSpinBox::valueChanged, [&](int newVal)
          { town->setMayoralElection(newVal, 0); });
  connect(ui->spinBox_2, &QSpinBox::valueChanged, [&](int newVal)
          { town->setMayoralElection(newVal, 1); });
  connect(ui->spinBox_3, &QSpinBox::valueChanged, [&](int newVal)
          { town->setMayoralElection(newVal, 2); });
}

MainWindow::~MainWindow()
{
}

void MainWindow::fillUiFromStruct()
{
  ui->nameLineEdit->setText(town->name());
  ui->populationSpinBox->setValue(town->population());
  ui->areaSpinBox->setValue(town->area());
  ui->regionLineEdit->setText(QString(town->region()));
  ui->isCapitalCheckBox->setChecked(town->isCapital());
  ui->spinBox_1->setValue(town->mayoralElection(0));
  ui->spinBox_2->setValue(town->mayoralElection(1));
  ui->spinBox_3->setValue(town->mayoralElection(2));
}

void MainWindow::on_printButton_clicked()
{
  Output renameDialog(town->report(), this);
  if (renameDialog.exec() == QDialog::Accepted)
  {
  }
}