#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->eggsAmountForSaleLabel->setText(QString::number(eggsForSale));
    ui->bearsForSaleLabel->setText(QString::number(bearsForSale));
    setFixedSize(191, 365); 
    setDialogBackground();
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    QObject::connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::reject);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setButtonStyle(QPushButton* button){
    QString buttonStyle = "QPushButton {"
                      "    background-color: #0000FF;" 
                      "    color: #FFFFFF;"
                      "}";

    QString pressedStyle = "QPushButton:pressed {"
                        "    background-color: #009ACD;"
                        "}";

    button->setStyleSheet(buttonStyle + pressedStyle);

}

void Dialog::setDialogBackground()
{
    QPixmap background("../resources/backEggDialog.png");
    background = background.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    setButtonStyle(ui->loadSingleEggButton);
    setButtonStyle(ui->loadAllEggsButton);
    setButtonStyle(ui->sellEggsButton);
    setButtonStyle(ui->closeButton);
    setButtonStyle(ui->loadBear);
    setButtonStyle(ui->sellBear);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    setPalette(palette);
}

void Dialog::on_loadBear_clicked(){
    MainWindow* _ptrMainWindow = qobject_cast<MainWindow*>(parentWidget());
    if(_ptrMainWindow->collectedBears - (bearsForSale) > 0){
        bearsForSale++;
    }
    ui->bearsForSaleLabel->setText(QString::number(bearsForSale));
}

void Dialog::on_loadSingleEggButton_clicked(){
    MainWindow* _ptrMainWindow = qobject_cast<MainWindow*>(parentWidget());
    if(_ptrMainWindow->collectedEggs - (eggsForSale) > 0){
        eggsForSale++;
    }
    ui->eggsAmountForSaleLabel->setText(QString::number(eggsForSale));
}

void Dialog::on_loadAllEggsButton_clicked(){
    MainWindow* _ptrMainWindow = qobject_cast<MainWindow*>(parentWidget());
    eggsForSale = _ptrMainWindow->collectedEggs;
    ui->eggsAmountForSaleLabel->setText(QString::number(eggsForSale));
}

void Dialog::on_sellEggsButton_clicked(){
    if(eggsForSale > 0){
        ui->sellEggsButton->setEnabled(false);
        MainWindow* _ptrMainWindow = qobject_cast<MainWindow*>(parentWidget());
        _ptrMainWindow->collectedEggs-=eggsForSale;
        emit selledEggs(ui->sellEggsButton, eggsForSale);
        eggsForSale = 0;
        ui->eggsAmountForSaleLabel->setText(QString::number(eggsForSale));
        emit updateCollectedEggsLabelSignal();
    }
}

void Dialog::on_sellBear_clicked(){
    if(bearsForSale > 0){
        ui->sellBear->setEnabled(false);
        MainWindow* _ptrMainWindow = qobject_cast<MainWindow*>(parentWidget());
        _ptrMainWindow->collectedBears-=bearsForSale;
        emit selledBears(ui->sellBear, bearsForSale);
        bearsForSale = 0;
        ui->bearsForSaleLabel->setText(QString::number(bearsForSale));
    }
}