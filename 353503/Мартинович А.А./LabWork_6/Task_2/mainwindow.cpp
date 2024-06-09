#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFile"
#include "QStringList"
#include "employee.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->write_button, &QPushButton::clicked, this, &MainWindow::clickWriteButton);
    connect(ui->read_button, &QPushButton::clicked, this, &MainWindow::clickReadButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickWriteButton()
{
    if (ui->task1_radiobutton->isChecked()) {
        QString filename = "MartinovichLab20.txt";
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << ui->write_text->toPlainText();
            ui->write_text->clear();
        }
        file.close();
    }
    else if (ui->task2_radiobutton->isChecked()) {
        QString filename = "MartinovichLab20_0.txt";
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            QStringList list = ui->write_text->toPlainText().split('+');
            bool flag = true;
            for (const auto& s: list) {
                bool ok = false;
                short num = s.toShort(&ok);
                if (!ok) {
                    return;
                }
            }
            QString result = list.join(" ");
            stream << result;
            ui->write_text->clear();
        }
        file.close();

    }
    else if (ui->task3_radiobutton->isChecked()) {
        QString filename = "MartinovichLab20_1.txt";
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            file.reset();
            QTextStream stream(&file);
            QStringList list = ui->write_text->toPlainText().split('\n');
            bool ok = false;
            if (list.size() % 4) {
                return;
            }
            for (int i = 0; i < list.size(); i+= 4) {
                Employee employee;
                int  id = list[i].toInt(&ok);
                if (!ok) {
                    return;
                }
                else {
                    employee.id = id;
                }

                double salary = list[1+i].toDouble(&ok);
                if (!ok) {
                    return;
                }
                else {
                    employee.salary = salary;
                }

                strcpy(employee.position, list[2+i].toStdString().c_str());

                bool isFullTime;
                if (list[3+i] == "True" || list[3+i] == "true" || list[3] == "1") {
                    employee.isFullTime = true;
                }
                stream << employee.id << " | " << employee.salary << " | " << employee.position << " | " << (employee.isFullTime?"YES":"NO") << "\n";
            }

            ui->write_text->clear();
        }
        file.close();
    }
    else if (ui->task4_radiobutton->isChecked()) {
        QString filename = "MartinovichLab20_2.txt";
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            file.reset();
            QTextStream stream(&file);
            QStringList list = ui->write_text->toPlainText().split('\n');
            bool ok = false;
            if (list.size() % 4) {
                return;
            }
            for (int i = 0; i < list.size(); i+= 4) {
                Employee employee;
                int  id = list[i].toInt(&ok);
                if (!ok) {
                    return;
                }
                else {
                    employee.id = id;
                }

                double salary = list[1+i].toDouble(&ok);
                if (!ok) {
                    return;
                }
                else {
                    employee.salary = salary;
                }

                strcpy(employee.position, list[2+i].toStdString().c_str());

                bool isFullTime;
                if (list[3+i] == "True" || list[3+i] == "true" || list[3] == "1") {
                    employee.isFullTime = true;
                }
                file.write((char*)&employee, sizeof(Employee));

        }

            ui->write_text->clear();
        }
        file.close();
    }
    else {
        QString filename = "MartinovichLab20_3.txt";
        QFile file(filename);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << ui->write_text->toPlainText() << "\n";
            ui->write_text->clear();
        }
        file.close();
    }
}

void MainWindow::clickReadButton()
{
    if (ui->task1_radiobutton->isChecked()) {
        ui->read_text->clear();
        QString filename = "MartinovichLab20.txt";
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                ui->read_text->append(line);
            }
        }
        file.close();
    }
    else if (ui->task2_radiobutton->isChecked()) {
        ui->read_text->clear();
        QString filename = "MartinovichLab20_0.txt";
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                ui->read_text->setText(line);
            }
        }
        file.close();
    }
    else if (ui->task3_radiobutton->isChecked()) {
        ui->read_text->clear();
        QString filename = "MartinovichLab20_1.txt";
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                ui->read_text->append(line);
            }
        }
        file.close();
    }
    else if (ui->task4_radiobutton->isChecked()) {
        ui->read_text->clear();
        QString filename = "MartinovichLab20_2.txt";
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                Employee employee;
                file.read((char*)&employee,sizeof(Employee));
                ui->read_text->append(QString::number(employee.id) + " | " + QString::number(employee.salary)
                                      + " | " + QString(employee.position) + " | " + (employee.isFullTime?"YES":"NO") + "\n");

            }
        }
        file.close();
    }
    else {
        ui->read_text->clear();
        QString filename = "MartinovichLab20_3.txt";
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                ui->read_text->append(line);
            }
        }
        file.close();
    }
}

