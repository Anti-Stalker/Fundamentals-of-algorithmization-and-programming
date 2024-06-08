#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_inputButton_clicked()
{
    if (ui->inputEdit->toPlainText() != "") {
        switch (ui->comboBox->currentIndex()) {
        case 0: {
            FileInputOutput::writeToFile(pathToSimpleParagraph, ui->inputEdit->toPlainText());
            break;
        }
        case 1: {
            QVector<float> nums;
            for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
                QDoubleSpinBox *spinBox = (QDoubleSpinBox *)ui->tableWidget->cellWidget(i, 0);
                nums.push_back(spinBox->value());
            }
            if (!nums.empty()) {
                FileInputOutput::writeArrayToFile(pathToArray, nums);
            }
            break;
        }
        case 2: {
            FileInputOutput::writeStructToTxtFile(pathToTxtStruct, plant);
            break;
        }
        case 3: {
            FileInputOutput::writeStructToBinFile(pathToBinStruct, plant);
            break;
        }
        case 4: {
            FileInputOutput::appendSentenceToFile(pathToListSentences, ui->inputEdit->toPlainText());
            break;
        }
        }
    }
}

void MainWindow::on_outputButton_clicked()
{
    switch (ui->comboBox->currentIndex()) {
    case 0: {
        ui->outputEdit->setText(FileInputOutput::readFromFile(pathToSimpleParagraph));
        break;
    }
    case 1: {
        ui->outputEdit->setText(FileInputOutput::readArrayFromFile(pathToArray));
        break;
    }
    case 2: {
        ui->outputEdit->clear();
        for (int i = 0; i < FileInputOutput::readStructFromTxtFile(pathToTxtStruct).size(); ++i) {
            ui->outputEdit->setText(
                ui->outputEdit->toPlainText()
                + FileInputOutput::readStructFromTxtFile(pathToTxtStruct)[i].plantToString() + '\n');
        }
        break;
    }
    case 3: {
        ui->outputEdit->clear();
        for (int i = 0; i < FileInputOutput::readStructFromBinFile(pathToBinStruct).size(); ++i) {
            ui->outputEdit->setText(
                ui->outputEdit->toPlainText()
                + FileInputOutput::readStructFromBinFile(pathToBinStruct)[i].plantToString() + '\n');
        }
        break;
    }
    case 4: {
        ui->outputEdit->setText(FileInputOutput::readFromFile(pathToListSentences));
        break;
    }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
    if (index == 0 || index == 4) {
        ui->inputEdit->setReadOnly(false);
    } else {
        ui->inputEdit->setReadOnly(true);
    }
    ui->inputEdit->clear();
    ui->outputEdit->clear();
}

void MainWindow::on_clearButton_clicked()
{
    ui->inputEdit->clear();
    if (ui->comboBox->currentIndex() == 1) {
        array.clear();
    }
}

void MainWindow::on_addButton_clicked()
{
    plant.age = ui->ageBox->value();
    plant.height = ui->heightBox->value();
    plant.isFlowering = (ui->yesBox->isChecked()) ? true : false;

    ui->inputEdit->setText(plant.plantToString());
}

void MainWindow::on_addButtonBin_clicked()
{
    plant.age = ui->ageBoxBin->value();
    plant.height = ui->heightBoxBin->value();
    plant.isFlowering = (ui->yesBoxBin->isChecked()) ? true : false;

    ui->inputEdit->setText(plant.plantToString());
}

void MainWindow::on_countInput_valueChanged(int arg1)
{
    int prevCount = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(arg1);
    for (int i = prevCount; i < arg1; i++) {
        ui->tableWidget->setCellWidget(i, 0, new QDoubleSpinBox());
    }
}


void MainWindow::on_addArray_clicked()
{
    ui->inputEdit->clear();
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        QDoubleSpinBox *spinBox = (QDoubleSpinBox *)ui->tableWidget->cellWidget(i, 0);
        ui->inputEdit->setText(ui->inputEdit->toPlainText()
                               + QString::number(spinBox->value()) + " | ");
    }
}

