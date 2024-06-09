#include "mainwindow.h"
#include "QDebug"

const int8_t MAX_HEIGHT = 15;
const int8_t START = 1;
const int8_t FINISH = 2;
const int8_t TMP_NUMBER = 6;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , converterWidget(new QWidget(this))
    , hLayout(new QVBoxLayout())
    , heightTowerLine(new QSpinBox(this))
    , resultTextEdit(new QTextEdit(this))
    , calculateButton(new QPushButton("Рассчитать", this))
{
    setCentralWidget(converterWidget);
    converterWidget->setLayout(hLayout);

    resultTextEdit->setReadOnly(true);

    hLayout->addStretch();
    hLayout->addWidget(heightTowerLine);
    hLayout->addWidget(resultTextEdit);
    hLayout->addWidget(calculateButton);
    hLayout->addStretch();

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::StartHanoi);
}



void MainWindow::Hanoi(int8_t height, int8_t start, int8_t finish)
{
    if (height == 1) {
        resultTextEdit->append("Move disk from " + QString::number(start) + " to " + QString::number(finish));
    }
    else {
        int8_t tmp = TMP_NUMBER - start - finish;
        Hanoi(height - 1, start, tmp);
        resultTextEdit->append("Move disk from " + QString::number(start) + " to " + QString::number(finish));
        Hanoi(height - 1, tmp, finish);
    }
}

void MainWindow::StartHanoi()
{
    resultTextEdit->setText("");
    int8_t height = heightTowerLine->value();
    if (height >= 1 && height <= MAX_HEIGHT) {
        Hanoi(height, START, FINISH);
    }
    else {
        resultTextEdit->setText("Слишком долго будет считать");
    }
}
