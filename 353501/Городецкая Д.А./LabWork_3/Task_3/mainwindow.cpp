#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *layout = new QVBoxLayout(this);

    inputEdit = new QLineEdit(this);
    layout->addWidget(inputEdit);

    QPushButton *calculateButton = new QPushButton("Преобразовать");
    layout->addWidget(calculateButton);

    answer = new QLabel("Ответ:", this);
    layout->addWidget(answer);

    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::reverseNumber);
    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(layout);
}
void MainWindow::reverseNumber()
{
    bool ok;
    int n = inputEdit->text().toInt(&ok);

    if (!ok)
    {
        QMessageBox::warning(this, "Ошибка", "Некорректное значение числа");
        return;
    }

    int reversed = reverse(n);

    answer->setText("Ответ: " + QString::number(reversed));
}
int MainWindow::reverse(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        int lastDigit = n % 10;
        int remainingDigits = n / 10;
        int reversedRemaining = reverse(remainingDigits);
        int reversed = lastDigit;

        while (reversed >= 10)
        {
            reversed /= 10;
        }

        int orderOfMagnitude = 10;
        while (reversedRemaining >= orderOfMagnitude)
        {
            orderOfMagnitude *= 10;
        }

        return reversed * orderOfMagnitude + reversedRemaining;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
