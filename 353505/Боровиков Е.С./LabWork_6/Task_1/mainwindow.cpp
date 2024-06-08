#include "mainwindow.h"
#include "ui_mainwindow.h"

char SPEC[] = {'E', 'B', 'T'};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    computer_1 = {8, 2.5, 'D', true};

    int arr[] = {16, 97, 50, 74, 81, 66, 94};
    std::string Name = "Model_for1";
    for(int i = 0; i<7; ++i)
    {
        Computer::performanceScores[i] = arr[i];
    }

    for(int i = 0; i<Name.size(); ++i)
    {
        Computer::modelName[i] = Name[i];
    }

    computer_2.ramSizeGB = 16;
    computer_2.cpuSpeedGHz = 3.0;
    computer_2.brandInitial = 'A';
    computer_2.isLaptop = false;

    computer_4->ramSizeGB = 10;
    computer_4->cpuSpeedGHz = 52.2;
    computer_4->brandInitial = 'B';
    computer_4->isLaptop = true;

    computer_5.ramSizeGB = 20;
    computer_5.cpuSpeedGHz = 100;
    computer_5.brandInitial = 'E';
    computer_5.isLaptop = true;

    showInfo();

    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        computer_1.isLaptop  = ui->radioButton->isChecked();
        computer_1.cpuSpeedGHz = ui->doubleSpinBox->value();
        computer_1.ramSizeGB = ui->spinBox->value();
        computer_1.brandInitial = SPEC[ui->comboBox->currentIndex()];
        for(int i = 0; i<ui->lineEdit->text().size() && i<30; ++i)
        {
            Computer::modelName[i] = ui->lineEdit->text()[i];
        }

        Computer::performanceScores[0] = ui->spinBox_2->value();
        Computer::performanceScores[1] = ui->spinBox_3->value();
        Computer::performanceScores[2] = ui->spinBox_4->value();
        Computer::performanceScores[3] = ui->spinBox_5->value();
        Computer::performanceScores[4] = ui->spinBox_6->value();
        Computer::performanceScores[5] = ui->spinBox_7->value();
        Computer::performanceScores[6] = ui->spinBox_8->value();
        showInfo();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showInfo()
{
    QString h = "";
    for (int i = 0; i < 7; ++i) {
        h += QString::number(Computer::performanceScores[i]) + " | ";
    }
    ui->label_9->setText(QString::number(computer_1.ramSizeGB) + " | " + QString::number(computer_1.cpuSpeedGHz) + " | " +
                         computer_1.brandInitial + " | " + (computer_1.isLaptop ? "Ноутбук" : "Компьютер") + " | " +
                         QString(reinterpret_cast<const QChar*>(Computer::modelName)) + " | " + h);
    ui->label->setText(QString::number(computer_4->ramSizeGB) + " | " + QString::number(computer_4->cpuSpeedGHz) + " | " +
                       computer_4->brandInitial + " | " + (computer_4->isLaptop ? "Ноутбук" : "Компьютер") + " | " +
                       QString(reinterpret_cast<const QChar*>(Computer::modelName)) + " | " + h);
    ui->label_2->setText(QString::number(computer_5.ramSizeGB) + " | " + QString::number(computer_5.cpuSpeedGHz) + " | " +
                         computer_5.brandInitial + " | " + (computer_5.isLaptop ? "Ноутбук" : "Компьютер") + " | " +
                         QString(reinterpret_cast<const QChar*>(Computer::modelName)) + " | " + h);
}
