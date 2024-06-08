#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::clearStrs(QString &str3, QString &str1, QString &str2)
{
    str1.clear();
    str2.clear();
    str3.clear();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    long long values[] = {4400, 11200, 9300, 228, 2005};

    explicitInit(values, str2, str3);
    str1 = Motorcycle1.is_electric == true ? "electric" : "not electric";
    ui->lineEdit->setText(QString::number(Motorcycle1.engineCapacity)
                          + '|' + QString::number(Motorcycle1.fuelConsumption) +
                          '|' + Motorcycle1.category + '|' + str1 +
                          '|' + str2 + '|' + str3);
    clearStrs(str3, str1, str2);

    separatlyInit(values, str2, str3);
    str1 = Motorcycle2.is_electric == true ? "electric" : "not electric";
    ui->lineEdit_2->setText(QString::number(Motorcycle2.engineCapacity)
                          + '|' + QString::number(Motorcycle2.fuelConsumption) +
                          '|' + Motorcycle2.category + '|' + str1 +
                          '|' + str2 + '|' + str3);
    clearStrs(str3, str1, str2);

    initializeMotorcycleViaPointer(motorcyclePtr, str2, str3, values);
    str1 = motorcyclePtr->is_electric ? "electric" : "not electric";
    ui->lineEdit_4->setText(QString::number(motorcyclePtr->engineCapacity)
                            + '|' + QString::number(motorcyclePtr->fuelConsumption) +
                            '|' + motorcyclePtr->category + '|' + str1 +
                            '|' + str2 + '|' + str3);
    clearStrs(str3, str1, str2);

    initializeMotorcycleViaReference(motorcycleRef, str2, str3, values);
    str1 = motorcycleRef.is_electric ? "electric" : "not electric";
    ui->lineEdit_7->setText(QString::number(motorcycleRef.engineCapacity)
                            + '|' + QString::number(motorcycleRef.fuelConsumption) +
                            '|' + motorcycleRef.category + '|' + str1 +
                            '|' + str2 + '|' + str3);
    clearStrs(str3, str1, str2);
}

void MainWindow::formStr3(Motorcycle &motorcycle, QString &str3, long long *values)
{
    for (int i = 0; i < 5; i++)
    {
        motorcycle.mileageByYear[i] = values[i];
        str3 += QString::number(values[i]);
        str3 += " ";
    }
}

void MainWindow::formStr2(Motorcycle &motorcycle, QString &str2)
{
    for (int i = 0; motorcycle.brand[i] != '\0'; ++i)
    {
        str2 += motorcycle.brand[i];
    }
}

void MainWindow::explicitInit(long long *values, QString &str2, QString &str3)
{
    Motorcycle1 = {1000, 5.5, 'D', false, "BMW"};
    formStr2(Motorcycle1, str2);
    formStr3(Motorcycle1, str3, values);
}

void MainWindow::separatlyInit(long long *values, QString &str2, QString &str3)
{
    Motorcycle2.engineCapacity = 1200;
    Motorcycle2.fuelConsumption = 6.0;
    Motorcycle2.category = 'E';
    Motorcycle2.is_electric = true;
    strcpy(Motorcycle2.brand, "Yamaha");
    formStr2(Motorcycle2, str2);
    formStr3(Motorcycle2, str3, values);
}

void MainWindow::initializeMotorcycleViaPointer(Motorcycle *motorcycle, QString &str2, QString &str3, long long *values)
{
    motorcycle->engineCapacity = 1500;
    motorcycle->fuelConsumption = 7.5;
    motorcycle->category = 'C';
    motorcycle->is_electric = false;
    strcpy(motorcycle->brand, "Harley-Davidson");
    formStr2(*motorcycle, str2);
    formStr3(*motorcycle, str3, values);
}

void MainWindow::initializeMotorcycleViaReference(Motorcycle &motorcycle, QString &str2, QString &str3, long long *values)
{
    motorcycle.engineCapacity = 1800;
    motorcycle.fuelConsumption = 8.0;
    motorcycle.category = 'D';
    motorcycle.is_electric = true;
    strcpy(motorcycle.brand, "Ducati");
    formStr2(motorcycle, str2);
    formStr3(motorcycle, str3, values);
}

void MainWindow::initializeByClient(QString &str2, QString &str3)
{
    int engineCapacity = ui->spinBox->value();
    if (engineCapacity <= 0) {
        QMessageBox::warning(this, "Ошибка ввода", "Некорректное значение для объема двигателя.");
        return;
    }
    Motorcycle3.engineCapacity = engineCapacity;

    double fuelConsumption = ui->doubleSpinBox->value();
    if (fuelConsumption <= 0) {
        QMessageBox::warning(this, "Ошибка ввода", "Некорректное значение для расхода топлива.");
        return;
    }
    Motorcycle3.fuelConsumption = fuelConsumption;

    QString categoryText = ui->lineEdit_5->text();
    if (categoryText.isEmpty() || categoryText.length() != 1) {
        QMessageBox::warning(this, "Ошибка ввода", "Введен некорректный символ для категории.");
        return;
    }
    Motorcycle3.category = categoryText[0].toLatin1();

    QString isElectric = ui->comboBox->currentText();
    if (isElectric != "Да" && isElectric != "Нет") {
        QMessageBox::warning(this, "Ошибка ввода", "Выберите 'Да' или 'Нет' для электрического мотоцикла.");
        return;
    }
    Motorcycle3.is_electric = (isElectric == "Да");

    QString brand = ui->lineEdit_6->text();
    if (brand.isEmpty()) {
        QMessageBox::warning(this, "Ошибка ввода", "Введите марку мотоцикла.");
        return;
    }
    strcpy(Motorcycle3.brand, brand.toLatin1().data());

    for (int i = 0; i < 5; ++i) {
        int mileage = 0;
        switch (i) {
        case 0: mileage = ui->spinBox_2->value(); break;
        case 1: mileage = ui->spinBox_3->value(); break;
        case 2: mileage = ui->spinBox_4->value(); break;
        case 3: mileage = ui->spinBox_5->value(); break;
        case 4: mileage = ui->spinBox_6->value(); break;
        }
        if (mileage < 0) {
            QMessageBox::warning(this, "Ошибка ввода", "Пробег за год не может быть отрицательным.");
            return;
        }
        Motorcycle3.mileageByYear[i] = mileage;
    }

    formStr2(Motorcycle3, str2);

    for (int i = 0; i < 5; i++) {
        str3 += QString::number(Motorcycle3.mileageByYear[i]);
        str3 += " ";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    initializeByClient(str2, str3);
    str1 = Motorcycle3.is_electric == true ? "electric" : "not electric";
    ui->lineEdit_3->setText(QString::number(Motorcycle3.engineCapacity)
                            + '|' + QString::number(Motorcycle3.fuelConsumption) +
                            '|' + Motorcycle3.category + '|' + str1 +
                            '|' + str2 + '|' + str3);
    clearStrs(str3, str1, str2);
}


void MainWindow::on_pushButton_clicked()
{
    close();
}

