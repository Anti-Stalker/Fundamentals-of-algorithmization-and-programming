#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textEdit->setReadOnly(true);
    ui->textEdit_2->setReadOnly(true);
    ui->spinBox->setRange(2, 99);


    table = MyHashTable<int>(2);
    table.createRandomHashTable();
    showInformation();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showInformation()
{

    QVector <QVector<int>> vec = table.toVector();
    QString str = "";
    for (int i = 0; i < vec.size(); ++i){
        str += QString::number(i) + ": ";
        for (int j = 0; j < vec[i].size(); ++j){
            str += QString::number(vec[i][j]) + " ";
        }
        if (i != vec.size() -1)str += "\n------------\n";
    }
    ui->textEdit->setText(str);
}

void MainWindow::on_pushButton_clicked()
{
    table.clear();
    table = MyHashTable<int>(ui->spinBox->value());
    table.createRandomHashTable();
    showInformation();


}


void MainWindow::on_pushButton_2_clicked()
{
    table.del(ui->spinBox_2->value());
    showInformation();
}


void MainWindow::on_pushButton_3_clicked()
{
    table.insert(ui->spinBox_2->value(), ui->spinBox_3->value());
    showInformation();
}


void MainWindow::on_pushButton_4_clicked()
{
    QVector <int> vec = table[table.findMinKey()];
    QString str = "";
    for (int i = 0; i < vec.size(); ++i){
        str += QString::number(vec[i]) + " ";
    }
    ui->textEdit_2->setText(str);
}

