#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Str();
    Ptr();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::Str()
{

    Airplane initWithStr = {35, 48, 'C', true, {'S','a','v','a','n','n','a'},{34,25,27}};
    QString str = QString::number(initWithStr.pasengers) + "|" + QString::number(initWithStr.bags) + "|" + initWithStr.typeFlight + "|" + (initWithStr.flight ? "true" : "false") + "|";
    for(int i = 0; initWithStr.namePlane[i] != '\0'; ++i){
        str += initWithStr.namePlane[i];
    }

    str += "|";

    for(int i = 0; i < 3; ++i){
        str += QString::number(initWithStr.yearSteward[i]) + "|";
    }
    ui->AddingText->setText(str);
}

void MainWindow::Ptr()
{
    Airplane Ptr;
    Airplane *initWithPtr = &Ptr;
    initWithPtr->pasengers = 45;
    initWithPtr->bags = 50;
    initWithPtr->typeFlight = 'B';
    initWithPtr->flight = true;
    char nameInit[] = "Sunrise";
    for(int i = 0; i <15; ++i){
        initWithPtr->namePlane[i] = nameInit[i];
    }
    initWithPtr->yearSteward[0] = 28;
    initWithPtr->yearSteward[1] = 23;
    initWithPtr->yearSteward[2] = 35;

    QString str = QString::number(initWithPtr->pasengers) + "|" + QString::number(initWithPtr->bags) + "|" + initWithPtr->typeFlight + "|" + (initWithPtr->flight ? "true" : "false") + "|" + QString(initWithPtr->namePlane) + "|";
    for (int i = 0; i < 3; ++i)
    {
        str += QString::number(initWithPtr->yearSteward[i]) + (i == 2 ? "" : ", ");
    }

    QString current_text = ui->AddingText->text();
    ui->AddingText->setText(current_text + "\n" + str);

}

void MainWindow::on_pushButton_clicked()
{
    Airplane initWithUi;
    QString pasangers = ui->Pasengers->text();
    QString bags = ui->Bags->text();
    QString typeFlight;
    if (ui->checkBox_2->isChecked()){
        typeFlight = ui->checkBox_2->text();
    }
    else if (ui->checkBox_3->isChecked()){
        typeFlight = ui->checkBox_3->text();
    }
    QString flight;
    if (ui->checkBox_4->isChecked()){
        flight = ui->checkBox_4->text();
    }
    else if(ui->checkBox_5->isChecked()){
        flight = ui->checkBox_5->text();
    }

    QString steward1 = ui->steward1->text();
    QString steward2 = ui->steward2->text();
    QString steward3 = ui->steward3->text();

    QString current_text = ui->AddingText->text();


    ui->AddingText->setText(current_text + "\n" + pasangers + "|" + bags + "|" + typeFlight + "|" + flight + "|" + steward1 + "|" + steward2 + "|" + steward3);
}


void MainWindow::on_checkBox_2_clicked()
{
    if (ui->checkBox_2->isChecked()){
        ui->checkBox_3->setChecked(false);
    }
}


void MainWindow::on_checkBox_3_clicked()
{
    if (ui->checkBox_3->isChecked()){
        ui->checkBox_2->setChecked(false);
    }
}


void MainWindow::on_checkBox_4_clicked()
{
    if(ui->checkBox_4->isChecked()){
       ui->checkBox_5->setChecked(false);
    }
}


void MainWindow::on_checkBox_5_clicked()
{
    if(ui->checkBox_5->isCheckable()){
       ui->checkBox_4->setChecked(false);
    }
}

