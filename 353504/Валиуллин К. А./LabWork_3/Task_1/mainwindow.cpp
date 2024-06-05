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

void MainWindow::clear_all()
{
    ui->output->clear();
    binaryInt.clear();
    binaryFr.clear();
    binaryTotal.clear();
    binaryInt = "";
    binaryFr = "";
    binaryExp = "";
    binaryMantisa = "";
    binarySign = "0";
    binaryTotal = "";
}

void MainWindow::on_pushButton_clicked()
{
    clear_all();
    str = ui->input->text();
    value = str.toDouble(&correct);
    if (!correct && str[0] != '-') {
        QMessageBox::critical(nullptr, "Ошибка", "Неправильный ввод. Попробуйте снова.");
        return;
    }
    if (str[0] == '-') {
        binarySign = "1";
    }
    else {
        binarySign = "0";
    }
    if (str == "0" || str == "-0") {
        binaryExp = binaryExp.leftJustified(11, '0');
        binaryMantisa = binaryMantisa.leftJustified(52, '0');
        binaryTotal = binarySign + " " + binaryExp + " " + binaryMantisa;
        ui->output->setText(binaryTotal);
        return;
    }

    value = qAbs(value);
    integer = value / 1;
    fractional = value - integer;
    converting_integer(integer, binaryInt);

    if (fractional) {
        converting_fractional(fractional, binaryFr);
    }

    if (integer == 0) {
        while (binaryFr[counter] == '0') {
            counter++;
        }
        counter++;
        binaryFr.remove(0,counter);
        places = -counter;
    }
    else {
        places = binaryInt.length() - 1;
    }

    exponent = bias + places;

    converting_integer(exponent, binaryExp);
    binaryExp = binaryExp.rightJustified(11, '0');

    binaryInt.remove(0, 1);
    binaryMantisa = binaryInt + binaryFr;
    binaryMantisa = binaryMantisa.leftJustified(52, '0');
    binaryMantisa = binaryMantisa.left(52);

    binaryTotal = binarySign + " " + binaryExp + " " + binaryMantisa;

    qDebug() << binaryTotal.length() - 2;
    ui->output->setText(binaryTotal);
}

int MainWindow::converting_integer(int &integer, QString &binary) {
    if (integer / 2 == 0) {
        binary += QString::number(integer % 2);
        std::reverse((binary).begin(), binary.end());
        return 0;
    }
    else {
        binary += QString::number(integer % 2);
        integer /= 2;
        return converting_integer(integer, binary);
    }
}

int MainWindow::converting_fractional(double &fractional, QString &binary)
{
    if (qAbs(fractional * 2 - 1) <= epsilon) {
        binary += "1";
        binary += "0";
        return 0;
    }
    else {
        fractional *=2;
        if (fractional >= 1) {
            binary += "1";
            fractional--;
        }
        else {
            binary += "0";
        }
        return converting_fractional(fractional, binary);
    }
}
