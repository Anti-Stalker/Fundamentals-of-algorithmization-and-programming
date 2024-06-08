#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_InsertButton_clicked()
{
    int key = ui->inputLineEdit->text().toInt();
    int index = ui->indexLineEdit->text().toInt();
    hashTable.insert(key, index);
    ui->outputTextEdit->append("Inserted key: " + QString::number(key) + " at index: " + QString::number(index));
    ui->outputTextEdit->append(hashTable.print());
}

void MainWindow::on_FindMaxStackButton_clicked()
{
    int maxStackIndex = hashTable.findMaxStack();
    ui->outputTextEdit->append("Max stack index: " + QString::number(maxStackIndex));
}

void MainWindow::on_GenerateButton_clicked()
{
    int size = ui->sizeLineEdit->text().toInt();
    hashTable.generateAndFill(size);
    ui->outputTextEdit->append("Generated hash table:");
    ui->outputTextEdit->append(hashTable.print());
}

void MainWindow::on_FindButton_clicked()
{
    int key = ui->findLineEdit->text().toInt();
    int index, stackIndex;
    if (hashTable.find(key, index, stackIndex)) {
        ui->outputTextEdit->append("Found key: " + QString::number(key) + " at stack index: " + QString::number(index) + " and position: " + QString::number(stackIndex));
    } else {
        ui->outputTextEdit->append("Key not found: " + QString::number(key));
    }
}

void MainWindow::on_RemoveButton_clicked()
{
    int key = ui->removeLineEdit->text().toInt();
    if (hashTable.remove(key)) {
        ui->outputTextEdit->append("Removed key: " + QString::number(key));
    } else {
        ui->outputTextEdit->append("Key not found: " + QString::number(key));
    }
    ui->outputTextEdit->append(hashTable.print());
}


