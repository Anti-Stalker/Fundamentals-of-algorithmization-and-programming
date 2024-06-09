#include "mainwindow.h"

const double MAX_VALUE = 1e9;
const double MIN_VALUE = 0;
const int DECIMAL_PRECISION = 20;

const int8_t MAX_N_FOR_M3 = 14;

constexpr auto DOUBLE_REG_EXPR_STRING = R"(^-?\d{1,20}(\.\d{1,20})?$)";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , converterWidget(new QWidget(this))
    , hLayout(new QVBoxLayout())
    , numberMLine(new QSpinBox(this))
    , numberNLine(new QSpinBox(this))
    , outputResultLine(new QLineEdit(this))
    , calculateButton(new QPushButton("Рассчитать", this))
{
    setCentralWidget(converterWidget);
    converterWidget->setLayout(hLayout);

    outputResultLine->setReadOnly(true);


    hLayout->addStretch();
    hLayout->addWidget(numberMLine);
    hLayout->addWidget(numberNLine);
    hLayout->addWidget(outputResultLine);
    hLayout->addWidget(calculateButton);
    hLayout->addStretch();

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::CalculateAckermanFunction);
}

void MainWindow::CalculateAckermanFunction()
{
    QHash<QPair<int64_t, int64_t>, int64_t> ackermanMemo;
    int64_t numberM = numberMLine->value();
    int64_t numberN = numberNLine->value();
    if (numberM == 0) {
        outputResultLine->setText(QString::number(numberN));
    }
    else if (numberM == 1) {
        outputResultLine->setText(QString::number(numberN+1));
    }
    else if (numberN <= MAX_N_FOR_M3 && numberM == 3 || numberM == 4 && numberN <= 1) {
        int64_t resultNumber = AckermanFunction(numberM, numberN, ackermanMemo);
        outputResultLine->setText(QString::number(resultNumber));
    }
    else {
        outputResultLine->setText("Слишком много");
    }
}

int64_t MainWindow::AckermanFunction(int64_t m, int64_t n, QHash<QPair<int64_t, int64_t>, int64_t> &ackermanMemo)
{
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return AckermanFunction(m - 1, 1, ackermanMemo);
    }

    if (ackermanMemo.find({m, n}) != ackermanMemo.end()) {
        return ackermanMemo[{m, n}];
    }

    ackermanMemo[{m, n}] = AckermanFunction(m - 1, AckermanFunction(m, n - 1, ackermanMemo), ackermanMemo);

    return ackermanMemo[{m, n}];
}



