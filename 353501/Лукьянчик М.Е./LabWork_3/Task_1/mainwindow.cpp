#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    converter = new DecimalToBinary(this);
    connect(converter, &DecimalToBinary::binaryResult, this, &MainWindow::onBinaryResult);
    connect(ui->calculation, &QPushButton::clicked, this, &MainWindow::performConversion);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBinaryResult(const QString& binary)
{
    ui->answer->setText(binary);

}

void MainWindow::performConversion()
{
    QString decimalNumber = ui->lineEdit->text();
    QString binaryRepresentation = converter->convert(decimalNumber);
    emit converter->binaryResult(binaryRepresentation);
}


DecimalToBinary::DecimalToBinary(QObject *parent) : QObject(parent) {}

QString DecimalToBinary::convert(const QString& decimal)
{
    double num = decimal.toDouble();
    int sign = 0;
    if (num == 0) {
        return "0";
    }
    if(num<0)
    {
        sign = 1;
        num = num * (-1);
    }
    int intPart = static_cast<int>(num);
    double fracPart = num - intPart;
    QString binaryIntPart = convertIntPart(intPart, fracPart);
    QString binaryFracPart="";
    if(fracPart != 0)
    {
        binaryFracPart = convertFracPart(fracPart, 20);
    }
    QString result = "";
    if(sign == 1)
        result +="1";
    else result +="0";
    result += binaryIntPart;
    if (!binaryFracPart.isEmpty())
    {
        result += '.' + binaryFracPart;
    }
    return result;
}

QString DecimalToBinary::convertIntPart(int intPart, int fracPart)
{
    if (intPart == 0 && fracPart != 0)
    {
        return "0";
    }
    QString binary;
    if (intPart > 0)
    {
        binary = convertIntPart(intPart / 2, fracPart) + QString::number(intPart % 2);
    }
    return binary;
}

QString DecimalToBinary::convertFracPart(double fracPart, int maxFracDigits)
{
    if (maxFracDigits == 0)
    {
        return "";
    }
    fracPart *= 2;
    if (fracPart >= 1)
    {
        return '1' + convertFracPart(fracPart - 1, maxFracDigits - 1);
    } else
    {
        return '0' + convertFracPart(fracPart, maxFracDigits - 1);
    }
    if(fracPart==0)
        return "";
}
