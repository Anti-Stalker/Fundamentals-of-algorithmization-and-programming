#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked, this, &StartWindow::onStartButtonClicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &StartWindow::onCloseButtonClicked);

    QPalette palette1 = ui->textBrowser->palette();
    palette1.setColor(QPalette::Base, Qt::gray);
    ui->textBrowser->setPalette(palette1);

    ui->startButton->setStyleSheet(QString("QPushButton#%1 { background-color: gray; }").arg(ui->startButton->objectName()));
    ui->closeButton->setStyleSheet(QString("QPushButton#%1 { background-color: gray; }").arg(ui->closeButton->objectName()));

}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::onStartButtonClicked()
{
    emit startGame();
}

void StartWindow::onCloseButtonClicked()
{
    emit closeApplication();
}
