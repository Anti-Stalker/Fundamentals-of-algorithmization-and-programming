#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::vector<double> MainWindow::calculateMedians(const std::vector<double>& inputVector)
{
    std::vector<double> medians;

    int size = inputVector.size();
    for (int i = 0; i < size; i += 3)
    {
        double median;

        if (i + 2 < size)
        {
            std::vector<double> triplet = { inputVector[i], inputVector[i + 1], inputVector[i + 2] };
            std::sort(triplet.begin(), triplet.end());
            median = triplet[1];
        }
        else
        {
            median = (inputVector[i] + inputVector[i + 1]) / 2.0;
        }

        medians.push_back(median);
    }

    return medians;
}

void MainWindow::on_calculateButton_clicked()
{
    QString inputText = ui->inputTextEdit->toPlainText();
    QStringList inputList = inputText.split(" ", Qt::SkipEmptyParts);
    std::vector<double> inputVector;

    for (const QString& str : inputList)
    {
        bool conversionOk;
        double value = str.toDouble(&conversionOk);
        if (conversionOk)
        {
            inputVector.push_back(value);
        }
        else
        {
            QMessageBox::warning(this, "Error", "Invalid input: " + str);
            return;
        }
    }

    std::vector<double> medians = calculateMedians(inputVector);

    QString outputText;
    for (double median : medians)
    {
        outputText += QString::number(median) + " ";
    }

    ui->outputTextEdit->setPlainText(outputText);
}
