#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    houseInitializingString = {3, 75.6, 'B', true};

    houseAssignValues.rooms = 2;
    houseAssignValues.area = 52.3;
    houseAssignValues.letterOFHouse = 'A';
    houseAssignValues.isTheHouseRentable = false;

    housePtr->rooms = 4;
    housePtr->area = 77.2;
    housePtr->letterOFHouse = 'C';
    housePtr->isTheHouseRentable = true;

    char temp[12] = "st. Pushkin";
    for (int i = 0; i < 12; ++i) {
        houseInitializingString.addres[i] = temp[i];
        houseAssignValues.addres[i] = temp[i];
        housePtr->addres[i] = temp[i];
        //.districtAdministrationAddress[i] = temp[i];
    }
    for (int i = 0; i < 3; ++i) {
        houseInitializingString.paymentsForTheLastMonths[i] = 200 + 25 * i;
        houseAssignValues.paymentsForTheLastMonths[i] = 100 + 25 * i;
        housePtr->paymentsForTheLastMonths[i] = 192 + 25 * i;
        stringOfPayments += QString::number(houseInitializingString.paymentsForTheLastMonths[i]) + " ";
    }

    showAllHoses();

    connect(ui->lineEdit, &QLineEdit::textEdited, this, &MainWindow::toUppercase);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toUppercase()
{
    QString temp = ui->lineEdit->text();
    ui->lineEdit->setText(temp.toUpper());
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->doubleSpinBox->value() != 0 && ui->spinBox->value() != 0 && !ui->lineEdit->text().isEmpty() && !ui->lineEdit_2->text().isEmpty() && ui->spinBox_2->value() != 0 && ui->spinBox_3->value() != 0 && ui->spinBox_4->value() != 0)
    {
        houseUser.rooms = ui->spinBox->value();
        houseUser.area = ui->doubleSpinBox->value();
        QString temp = ui->lineEdit->text();
        houseUser.letterOFHouse = temp[0].toLatin1();
        houseUser.isTheHouseRentable = ui->checkBox->isChecked();
        QString boolString = houseUser.isTheHouseRentable ? "true" : "false";

        temp = ui->lineEdit_2->text();
        for(int i = 0; i < temp.length(); i++)
        {
            houseUser.addres[i] = temp[i].toLatin1();
        }

        houseUser.paymentsForTheLastMonths[0] = ui->spinBox_2->value();
        houseUser.paymentsForTheLastMonths[1] = ui->spinBox_3->value();
        houseUser.paymentsForTheLastMonths[2] = ui->spinBox_4->value();

        QString stringHouse = QString::number(houseUser.rooms) + " | " + QString::number(houseUser.area) + " | " + houseUser.letterOFHouse + " | " + "Is rentable: " + boolString + " | " + temp + " | ";
        for(int i = 0; i < 3; i++)
        {
            stringHouse += QString::number(houseUser.paymentsForTheLastMonths[i]);
            if(i != 2)
            {
                stringHouse +=", ";
            }

        }
        ui->textEdit_4->setText(stringHouse);
    }

}

void MainWindow::showAllHoses()
{
    QString boolString = houseInitializingString.isTheHouseRentable ? "true" : "false";
    QString temp = "";
    for(int i = 0; i < 12; i++)
    {
        temp += houseInitializingString.addres[i];
    }
    QString stringHouse = QString::number(houseInitializingString.rooms) + " | " + QString::number(houseInitializingString.area) + " | " + houseInitializingString.letterOFHouse + " | " + "Is rentable: " + boolString + " | " + temp + " | ";
    for(int i = 0; i < 3; i++)
    {
        stringHouse += QString::number(houseInitializingString.paymentsForTheLastMonths[i]);
        if(i != 2)
        {
            stringHouse +=", ";
        }
    }
    ui->textEdit->setText(stringHouse);

    boolString = houseAssignValues.isTheHouseRentable ? "true" : "false";
    temp = "";
    for(int i = 0; i < 12; i++)
    {
        temp += houseAssignValues.addres[i];
    }
    stringHouse = QString::number(houseAssignValues.rooms) + " | " + QString::number(houseAssignValues.area) + " | " + houseAssignValues.letterOFHouse + " | " + "Is rentable: " + boolString + " | " + temp + " | ";
    for(int i = 0; i < 3; i++)
    {
        stringHouse += QString::number(houseAssignValues.paymentsForTheLastMonths[i]);
        if(i != 2)
        {
            stringHouse +=", ";
        }
    }
    ui->textEdit_2->setText(stringHouse);

    boolString = housePtr->isTheHouseRentable ? "true" : "false";
    temp = "";
    for(int i = 0; i < 12; i++)
    {
        temp += housePtr->addres[i];
    }
    stringHouse = QString::number(housePtr->rooms) + " | " + QString::number(housePtr->area) + " | " + housePtr->letterOFHouse + " | " + "Is rentable: " + boolString + " | " + temp + " | ";
    for(int i = 0; i < 3; i++)
    {
        stringHouse += QString::number(housePtr->paymentsForTheLastMonths[i]);
        if(i != 2)
        {
            stringHouse +=", ";
        }
    }
    ui->textEdit_3->setText(stringHouse);
}
