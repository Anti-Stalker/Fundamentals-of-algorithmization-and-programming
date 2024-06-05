#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

void MainWindow::on_init_by_pointer_clicked(){
    ptrAirport->runwayCount = 3;
    ptrAirport->area = 2500.5;
    ptrAirport->airportCode = 'A';
    ptrAirport->hasControlTower = true;
    QString str = "My Pointer Airport";
    std::strcpy(ptrAirport->airportName, "My Pointer Airport");

    int years[] = {2010, 2012, 2015, 2017, 2019, 2021, 2023, 2025, 2027, 2029};
    std::memcpy(ptrAirport->weekendYears, years, sizeof(years));

    printFields(ptrAirport, str.size(), 10);
}

void MainWindow::on_init_by_ref_clicked(){
    ref.runwayCount = 34567890;
    ref.area = 250450.5;
    ref.airportCode = 'H';
    ref.hasControlTower = true;
    QString str = "My Ref Airport";
    std::strcpy(ref.airportName, "My Ref Airport");
    for (int i = 0; i < 10; ++i) {
        ref.weekendYears[i] = 2010 + (i * 2);
    }
    printFields(ref, str.size(), 10);
}

void MainWindow::on_init_with_str_clicked(){
    QString str = "International Airport";
    airportInitWithString = {4, 3500.25, 'B', true, {"International Airport"}, {2000, 2005, 2010, 2015, 2020}};
    printFields(airportInitWithString, str.size(), 5);
}

void MainWindow::printFields(const Airport* airportInitEachField, int sizeStr, int sizeWeekendYears){
    ui->textBrowser->clear();
    QString name;
    for(int i = 0; i < sizeStr;i++){
        name.push_back(airportInitEachField->airportName[i]);
    }

    QString strToPrint = QString::number(airportInitEachField->runwayCount) + " | " + 
                            QString::number(airportInitEachField->area) + " | " +
                            airportInitEachField->airportCode + " | "  + 
                            (airportInitEachField->hasControlTower ? "true" : "false") + "|" +
                            name + "|";
    for(auto i = 0; i < sizeWeekendYears; i++){
        strToPrint += QString::number(airportInitEachField->weekendYears[i]) + "|";
    }

    ui->textBrowser->setText(strToPrint);
}    

void MainWindow::on_print_clicked(){
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Print Report"));
    if (dialog.exec() != QDialog::Accepted)
        return;

    QTextDocument td;
    td.setHtml(ui->textBrowser->toHtml());
    td.print(&printer);
}

void MainWindow::printFields(const Airport &airportInitEachField, int sizeStr, int sizeWeekendYears){
    ui->textBrowser->clear();
    QString name;
    for(int i = 0; i < sizeStr;i++){
        name.push_back(airportInitEachField.airportName[i]);
    }

    QString strToPrint = QString::number(airportInitEachField.runwayCount) + " | " + 
                            QString::number(airportInitEachField.area) + " | " +
                            airportInitEachField.airportCode + " | "  + 
                            (airportInitEachField.hasControlTower ? "true" : "false") + "|" +
                            name + "|";
    for(auto i = 0; i < sizeWeekendYears; i++){
        strToPrint += QString::number(airportInitEachField.weekendYears[i]) + "|";
    }

    ui->textBrowser->setText(strToPrint);
}                              

void MainWindow::on_init_each_filed_clicked(){
    airportInitEachField.runwayCount = 4;
    airportInitEachField.area = 44500.25;
    airportInitEachField.airportCode = 'C';
    airportInitEachField.hasControlTower = true;
    std::string tempName = "International Airport";
    for(auto i = 0; i < tempName.size(); i++){
        airportInitEachField.airportName[i] = tempName[i];
    }
    std::vector<int> tempYears = {200, 200, 201, 201, 202};
    for(auto i = 0; i < tempYears.size(); i++){
        airportInitEachField.weekendYears[i] = tempYears[i];
    }
    printFields(airportInitEachField, tempName.size(), tempYears.size());
}

void MainWindow::initWithUserInput(const int& runwayCount, const double& area, char inputChar, const bool& hasControlTower,
                                    std::string airportName, const QVector<int>& numbers)
{
    userInputAirport.runwayCount = runwayCount;
    userInputAirport.area = area;
    userInputAirport.airportCode = inputChar;
    userInputAirport.hasControlTower = hasControlTower;

    for(auto i = 0; i < airportName.size(); i++){
        userInputAirport.airportName[i] = airportName[i];
    }


    int sizeWeekYear = 0;
    for(auto i = 0; i < numbers.size(); i++){
        userInputAirport.weekendYears[i] = numbers[i];
        sizeWeekYear++;
    }
    printFields(userInputAirport, airportName.size(), sizeWeekYear);
}

void MainWindow::on_init_with_user_input_clicked(){
    Dialog* dialog = new Dialog();
    connect(dialog, &Dialog::textEntered, this, &MainWindow::initWithUserInput);
    dialog->exec();
}