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

void MainWindow::on_input_fv_clicked()
{
    QString inputText = ui->textEdit_1v->toPlainText();
    QStringList inputList = inputText.split(" ", Qt::SkipEmptyParts);
    for (const QString& str : inputList)
    {
        bool conversionOk;
        double value = str.toDouble(&conversionOk);
        if (conversionOk)
        {
            first.push_back(value);
        }
        else
        {
            QMessageBox::warning(this, "Error", "Invalid input: " + str);
            return;
        }
    }

}


void MainWindow::on_input_sv_clicked()
{
    QString inputText = ui->plainTextEdit_2v->toPlainText();
    QStringList inputList = inputText.split(" ", Qt::SkipEmptyParts);
    for (const QString& str : inputList)
    {
        bool conversionOk;
        double value = str.toDouble(&conversionOk);
        if (conversionOk)
        {
            first.push_back(value);
        }
        else
        {
            QMessageBox::warning(this, "Error", "Invalid input: " + str);
            return;
        }
    }
}


void MainWindow::on_assignBut_clicked()
{
    Vector<int> *sample;
    first->assign(first,sample);
}

