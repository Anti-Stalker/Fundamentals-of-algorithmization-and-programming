#include "mainwindow.h"

const double MAX_VALUE = 1e9;
const double MIN_VALUE = 0;
const int DECIMAL_PRECISION = 20;

constexpr auto DOUBLE_REG_EXPR_STRING = R"(^-?\d{1,20}(\.\d{1,20})?$)";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , converterWidget(new QWidget(this))
    , hLayout(new QVBoxLayout())
    , decimalInputLineEdit(new QLineEdit(this))
    , decimalPrecisionLineEdit(new QSpinBox(this))
    , binaryOutputLineEdit (new QLineEdit(this))
    , doubleValidator(new QRegularExpressionValidator(QRegularExpression(DOUBLE_REG_EXPR_STRING), this))
    , calculateButton(new QPushButton("Рассчитать", this))
{
    setCentralWidget(converterWidget);
    converterWidget->setLayout(hLayout);

    decimalInputLineEdit->setValidator(doubleValidator);
    binaryOutputLineEdit->setReadOnly(true);

    hLayout->addStretch();
    hLayout->addWidget(decimalInputLineEdit);
    hLayout->addWidget(decimalPrecisionLineEdit);
    hLayout->addWidget(binaryOutputLineEdit);
    hLayout->addWidget(calculateButton);
    hLayout->addStretch();

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::CalculateDecimalToBinary);
}

void MainWindow::CalculateDecimalToBinary()
{
    long double decimal = decimalInputLineEdit->text().toDouble();
    int decimalPrecision = decimalPrecisionLineEdit->value();
    binaryOutputLineEdit->setText(DecimalToBinary(decimal, decimalPrecision));
}

QString MainWindow::DecimalToBinary(const long double decimal, const int16_t decimalPrecision)
{
    bool isNegativeNumber = decimal < 0;
    int64_t decimalPart = abs(static_cast<int64_t>(decimal));
    double partialPart = fabs(fabs(decimal) - decimalPart);
    if (decimalPrecision == 0) {
        return (isNegativeNumber?"-":"") + DecimalPartToBinary(decimalPart);
    }
    else {
        return (isNegativeNumber?"-":"") + DecimalPartToBinary(decimalPart) + "." + PartialPartToBinary(partialPart, decimalPrecision);
    }

}

QString MainWindow::DecimalPartToBinary(int64_t decimalPart, QString resultString)
{
    const int8_t binaryNumber = 2;

    resultString = QString::number(decimalPart % binaryNumber) + resultString;
    decimalPart = decimalPart / binaryNumber;

    if (decimalPart == 0) {
        return resultString;
    }

    return DecimalPartToBinary(decimalPart, resultString);
}

QString MainWindow::PartialPartToBinary(double partialPart, const int16_t decimalPrecision, QString resultString)
{
    const int8_t binaryNumber = 2;

    int8_t decimalPart = static_cast<int>(partialPart * binaryNumber);
    resultString += QString::number(decimalPart);
    partialPart = partialPart * binaryNumber - decimalPart;

    if (decimalPrecision <= resultString.size()) {
        return resultString;
    }

    return PartialPartToBinary(partialPart, decimalPrecision, resultString);
}




