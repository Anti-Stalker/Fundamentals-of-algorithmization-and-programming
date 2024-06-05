#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    {
        QFile file("BelavusauLab20.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }
        file.resize(0);
        file.write(ui->textEdit->toPlainText().toStdString().c_str());

        file.close();
    }

    {
        QFile file("BelavusauLab20.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return;
        }
        ui->textEdit_2->setText(file.readAll());

        file.close();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    {
        QFile file("BelavusauLab20_0.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }
        file.resize(0);

        std::string userInput = ui->textEdit_4->toPlainText().toStdString();

        QTextStream out(&file);

        for (int i = 0; i < userInput.size(); i++) {
            if (userInput[i] != '\n')
                out << userInput[i];
            else
                out << '|';
        }

        file.close();
    }

    {
        QFile file("BelavusauLab20_0.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return;
        }
        file.resize(0);

        std::string fileInfo = file.readAll().toStdString();

        size_t pos = 0;
        QString answer = "";

        QString number = "";
        while (fileInfo[pos] != '|') {
            number += fileInfo[pos++];
        }

        size_t n = number.toInt();

        answer += number + '\n';

        QVector<float> all;

        for (int i = 0; i < n; i++) {
            number = "";
            pos++;
            while (pos < fileInfo.size() && fileInfo[pos] != '|') {
                number += fileInfo[pos++];
            }

            answer += number + '\n';
        }

        ui->textEdit_3->setText(answer);

        file.close();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QFile file("BelavusauLab20_1.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    std::string all = file.readAll().toStdString();
    std::string answer = "";

    while (all.size() != 0) {
        Car car;
        car.from_string(all.substr(0, all.find('\n')));
        all.erase(0, all.find('\n') + 1);
        answer += car.to_string() + '\n';
    }

    ui->textEdit_6->setText(answer.c_str());

    file.close();
}

void MainWindow::on_pushButton_7_clicked(bool checked)
{
    QFile file("BelavusauLab20_1.txt");
    if (!file.open(QIODevice::Append | QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    std::string all = ui->textEdit_5->toPlainText().toStdString();

    Car car;
    car.from_string(all, '\n');

    file.write((car.to_string() + '\n').c_str());

    file.close();
}

void MainWindow::on_pushButton_8_clicked()
{
    QFile file("BelavusauLab20_2.bin");
    if (!file.open(QIODevice::Append | QIODevice::WriteOnly)) {
        return;
    }

    std::string all = ui->textEdit_7->toPlainText().toStdString();

    Car car;
    car.from_string(all, '\n');

    file.write((car.to_string() + '\n').c_str());

    file.close();
}


void MainWindow::on_pushButton_4_clicked()
{
    QFile file("BelavusauLab20_2.bin");
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    std::string all = file.readAll().toStdString();
    std::string answer = "";

    while (all.size() != 0) {
        Car car;
        car.from_string(all.substr(0, all.find('\n')));
        all.erase(0, all.find('\n') + 1);
        answer += car.to_string() + '\n';
    }

    ui->textEdit_8->setText(answer.c_str());

    file.close();
}


void MainWindow::on_pushButton_6_clicked()
{
    QFile file("BelavusauLab20_3.txt");
    if (!file.open(QIODevice::Append | QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    std::string all = ui->textEdit_10->toPlainText().toStdString();

    while (all.find('\n') != std::string::npos)
    {
        all[all.find('\n')] = ' ';
    }

    file.write(('\n' + all + '\n').c_str());

    file.close();
}


void MainWindow::on_pushButton_5_clicked()
{
    QFile file("BelavusauLab20_3.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    std::string all = file.readAll().toStdString();

    ui->textEdit_9->setText(all.c_str());

    file.close();
}

