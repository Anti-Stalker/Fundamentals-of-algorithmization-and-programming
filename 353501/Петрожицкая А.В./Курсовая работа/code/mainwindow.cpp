#include "mainwindow.h"
#include"ui_mainwindow.h"
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include<QRandomGenerator>
#include <QFile>
#include<QDebug>
#include <QPair>
#include<QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->plainTextEdit->setEnabled(false);
    ui->pushButton->setVisible(false);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл с кодом", QString(), "Файлы с кодом (*.cpp *.h)");

    if (!filePath.isEmpty())
    {
        displayCode(filePath);
    }
    ui->plainTextEdit->setEnabled(true);
}

void MainWindow::displayCode(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    QString code = file.readAll();
    ui->plainTextEdit->setPlainText(code);
}

void MainWindow::analysis(QString code){
    QStringList lines = code.split('\n');
    for(const QString& line : lines){
        if(line.contains("if") || line.contains("else")){
            draw.drawDecision();
            draw.drawLine();
        }
        else if(line.contains("cin")){
            draw.drawInput();
            draw.drawLine();
        }
        else if(line.contains("cout")){
            draw.drawOutput();
            draw.drawLine();
        }
        else if(line.contains("=")){
            draw.drawProcess();
            draw.drawLine();
        }
        else if(line.contains("for") || line.contains("while")){
            draw.drawLoop();
            draw.drawLine();
        }
        else if(line.contains("(") && !line.contains("if") && !line.contains("for") && !line.contains("while")){
            draw.drawStart();
            draw.drawLine();
        }
        else if(line.contains("return 0;")){
            draw.drawEnd();
        }
    }

    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap::fromImage(draw.returnImage()));
    item->setPos(0, 0);
    item->setScale(1.0);
}

int MainWindow::analysisCount(QString code){
    QStringList lines = code.split('\n');
    int counter = 0;
    for(const QString& line : lines){
        if(line.contains("if") || line.contains("else")){
            counter++;
        }
        else if(line.contains("cin")){
            counter++;
        }
        else if(line.contains("cout")){
            counter++;
        }
        else if(line.contains("=")){
            counter++;
        }
        else if(line.contains("for") || line.contains("while")){
            counter++;
        }
        else if(line.contains("(") && !line.contains("if") && !line.contains("for") && !line.contains("while")){
            counter++;
        }
        else if(line.contains("return 0;")){
            counter++;
        }
    }
    return counter;
}

void MainWindow::loadRandomCode(const QString directory) {
    QDir dir(directory);
    QStringList files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);

    int randomIndex = QRandomGenerator::global()->bounded(files.size());
    QString randomFile = files[randomIndex];
    QString filePath = dir.absoluteFilePath(randomFile);
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString code = file.readAll();
        ui->plainTextEdit->setPlainText(code);
        file.close();
    }
}

int MainWindow::generateRandomNumber(QString code)
{
    int count = analysisCount(code);
    int randomNumber = QRandomGenerator::global()->bounded(count);
    ui->label->setText(QString::number(randomNumber));
    return randomNumber;
}

void MainWindow::calculateDeterminant(QString code) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int randomNumber = generateRandomNumber(code);
            matrixLabels[i][j] = randomNumber;
        }
    }

    int det = calculateMatrixDeterminant();
    ui->label->setText("Determinant: " + QString::number(det));
}

int MainWindow::calculateMatrixDeterminant() {
    int a11 = matrixLabels[0][0];
    int a12 = matrixLabels[0][1];
    int a13 = matrixLabels[0][2];
    int a21 = matrixLabels[1][0];
    int a22 = matrixLabels[1][1];
    int a23 = matrixLabels[1][2];
    int a31 = matrixLabels[2][0];
    int a32 = matrixLabels[2][1];
    int a33 = matrixLabels[2][2];

    int det = a11 * (a22 * a33 - a23 * a32)
              - a12 * (a21 * a33 - a23 * a31)
              + a13 * (a21 * a32 - a22 * a31);
    return det;
}


void MainWindow::on_pushButton_clicked()
{
    openFile();
}


void MainWindow::on_radioButton_clicked()
{
    ui->plainTextEdit->setEnabled(false);
    ui->pushButton->setVisible(true);

}


void MainWindow::on_radioButton_2_clicked()
{
    ui->pushButton->setVisible(false);
    ui->plainTextEdit->setEnabled(true);
}

void MainWindow::saveImage(){
    draw.returnImage().save("/home/arina/курсач/flowchart.png", "PNG", -1);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->scene()->clear();
    analysis(ui->plainTextEdit->toPlainText());
}


void MainWindow::on_pushButton_4_clicked()
{
    loadRandomCode("/home/arina/курсач/test");
}


void MainWindow::on_pushButton_3_clicked()
{
    saveImage();
}


void MainWindow::on_pushButton_5_clicked()
{
    close();
}


void MainWindow::on_pushButton_6_clicked()
{
    generateRandomNumber(ui->plainTextEdit->toPlainText());
}


void MainWindow::on_pushButton_7_clicked()
{
    calculateDeterminant(ui->plainTextEdit->toPlainText());
}

