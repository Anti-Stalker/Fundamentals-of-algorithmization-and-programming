#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

    ui->popQ1->setDisabled(true);
    ui->popQ2->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushQ1_clicked()
{
    q.MyPush(ui->spinBox->value());
    print();

    ui->popQ1->setEnabled(true);
}


void MainWindow::on_popQ1_clicked()
{
    q.MyPop();
    print();

    if(q.empty())
        ui->popQ1->setDisabled(true);
}


void MainWindow::on_pushQ2_clicked()
{
    q1.MyPush(ui->spinBox_2->value());
    print();

    ui->popQ2->setEnabled(true);
}


void MainWindow::on_popQ2_clicked()
{
    q1.MyPop();
    print();

    if(q1.empty()) ui->popQ2->setDisabled(true);
}


void MainWindow::on_genQ1_clicked()
{
    q.clear();
    for(int i = 0; i < rand() % 20 + 1; i++) q.MyPush(rand() % 200000 - 100000);
    ui->popQ1->setEnabled(true);

    print();
}


void MainWindow::on_genQ2_clicked()
{
    q1.clear();
    for(int i = 0; i < rand() % 20 + 1; i++) q1.MyPush(rand() % 200000 - 100000);
    ui->popQ2->setEnabled(true);

    print();
}


void MainWindow::on_insertButton_clicked()
{
    q.insertAfterMaxElement(q1);
    ui->popQ1->setEnabled(true);

    print();
}


void MainWindow::print()
{
    q.print(ui->listWidget);

    if (q.empty())
        ui->emptyQ1->setText("true");
    else
        ui->emptyQ1->setText("false");

    ui->sizeQ1->setText(QString::number(q.size()));

    if (!q.empty())
        ui->frontQ1->setText(QString::number(q.front()));
    else
        ui->frontQ1->setText("exception");

    if (!q.empty())
        ui->backQ1->setText(QString::number(q.back()));
    else
        ui->backQ1->setText("exception");

    q1.print(ui->listWidget2);

    if (q1.empty())
        ui->emptyQ2->setText("true");
    else
        ui->emptyQ2->setText("false");

    ui->sizeQ2->setText(QString::number(q1.size()));

    if (!q1.empty())
        ui->frontQ2->setText(QString::number(q1.front()));
    else
        ui->frontQ2->setText("exception");

    if (!q1.empty())
        ui->backQ2->setText(QString::number(q1.back()));
    else
        ui->backQ2->setText("exception");
}
