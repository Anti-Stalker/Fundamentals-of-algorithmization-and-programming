#include "mainwindow.h"

const int8_t RADIX = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , converterWidget(new QWidget(this))
    , hLayout(new QVBoxLayout())
    , numberLine(new QLineEdit(this))
    , outputResultLine(new QLineEdit(this))
    , calculateButton(new QPushButton("Рассчитать", this))
    , mintValidator(new QIntValidator(this))
{
    setCentralWidget(converterWidget);
    converterWidget->setLayout(hLayout);

    outputResultLine->setReadOnly(true);
    numberLine->setValidator(mintValidator);

    hLayout->addStretch();
    hLayout->addWidget(numberLine);
    hLayout->addWidget(outputResultLine);
    hLayout->addWidget(calculateButton);
    hLayout->addStretch();

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::RotateNumber);

}

void MainWindow::RotateNumber()
{
    int64_t number = numberLine->text().toInt();
    outputResultLine->setText(QString::number(GetRotateNumber(number)));
}

int64_t MainWindow::GetRotateNumber(int64_t number, int64_t temp)
{
    if (number == 0) {
        return temp;
    }
    temp *= RADIX;
    temp += number % RADIX;
    number /= RADIX;
    return GetRotateNumber(number, temp);
}








