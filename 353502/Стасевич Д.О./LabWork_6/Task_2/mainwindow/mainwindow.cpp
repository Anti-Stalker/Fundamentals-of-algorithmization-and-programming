//
// Created by darina on 5/25/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include <QTextStream>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

struct Continent {
    int population;
    double area;
    char climate;
    bool hasMountains;
    static const int maxnameContinentLength = 200;
    char nameContinent[maxnameContinentLength];
    static const int maxCities = 10000;
    int cities;
};

mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    ui->lineEdit->hide();
    ui->outputplainplainTextEdit->hide();
    ui->pushButton->hide();
    ui->spinBox->hide();


    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(do_subtask_clicked(int)));
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(enter_clicked()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(save_array_clicked()));
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::do_subtask_clicked(int type) {
    ui->lineEdit->hide();
    ui->outputplainplainTextEdit->hide();
    current_subtask = type;
    ui->pushButton->hide();
    ui->spinBox->hide();
    switch (current_subtask) {
        case 0:
        {
            // input till enter
            ui->lineEdit->show();
            ui->outputplainplainTextEdit->show();
            break;
        }
        case 1:
        {
            ui->lineEdit->show();
            ui->outputplainplainTextEdit->show();
            ui->pushButton->show();
            ui->spinBox->show();
            break;
        }
    }
}

void mainwindow::enter_clicked() {
    QString text = ui->lineEdit->text();
    if(current_subtask == 0)
    {
        QString filename = "StasevichLab20.txt";
        QFile file(filename);
        QTextStream file_stream(&file);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream out(&file);

            for (const QChar &ch : text)
            {
                out << ch;
            }

            file.close();
        }
        else
        {
            std::cout << "can't open\n";
        }
        ui->lineEdit->clear();
        ui->outputplainplainTextEdit->clear();
        text.clear();
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&file);

            while (!in.atEnd())
            {
                QString character = in.read(1); // Читаем один символ
                text.append(character); // Добавляем символ к тексту
            }

            file.close();
            ui->outputplainplainTextEdit->setPlainText(text);
        }
        else
        {
            std::cout << "can't open\n";
        }
    }
}

void mainwindow::save_array_clicked() {
    int n = ui->spinBox->value();
    double* arr = new double[n];
    int cur = 0;
    QString t = ui->lineEdit->text();
    double cur_val = 0;
    bool point = 0;
    int del = 10;
    int sign = 0;
    for(auto x : t)
    {
        if(x == '-')
        {
            sign = 1;
            continue;
        }
        if(x == ' ')
        {
            arr[cur] = cur_val;
            if(sign)
                arr[cur] *= -1;
            sign = 0;
            cur ++;
            cur_val = 0;
            point = 0;
            del = 10;
            continue;
        }
        if(x == '.')
        {
            point = 1;
            del = 10;
            continue;
        }
        int t = x.digitValue();
        if(point)
        {
            cur_val += ((double)t / del);
            del *= 10;
            continue;
        }
        else
        {
            cur_val = cur_val * 10 + t;
            continue;
        }
    }
    if(cur != n)
    {
        arr[cur] = cur_val;
        if(sign)
        {
            arr[cur] *= -1;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    QString filename = "StasevichLab20_0.txt";
    QFile file(filename);
    QTextStream file_stream(&file);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        for(int i = 0; i < n; i ++)
        {
            out << arr[i] << "<";
        }
        file.close();
    }
    else
    {
        std::cout << "can't open\n";
    }
    ui->lineEdit->clear();
    ui->outputplainplainTextEdit->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);

        QString text;
        while (!in.atEnd())
        {
            while (!file_stream.atEnd()) {
                QChar character;
                file_stream >> character;
                if (character != '<' && character >= '0' && character <= '9')
                    text += character;
                else if(character == '<')
                {
                    text += " ";
                }
                else if(character == '.')
                {
                    text += ".";
                }
                else if(character == '-')
                {
                    text += '-';
                }
                else
                {

                }
            }
            file.close();
        }
        ui->outputplainplainTextEdit->setPlainText(text);
        file.close();
    }
    else
    {
        std::cout << "can't open\n";
    }
}
