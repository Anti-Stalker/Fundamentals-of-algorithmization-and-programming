#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>  // для std::rand и std::srand
#include <ctime>    // для std::time

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enqueueButton_clicked()
{
    QString valueStr = ui->valueLineEdit->text();
    if (!valueStr.isEmpty()) {
        int value = valueStr.toInt();
        m_queue.enqueue(value);
        ui->queueListWidget->addItem(QString::number(value));
        ui->valueLineEdit->clear();
        ui->messageLabel->setText(QString("Enqueued: %1").arg(value));
    } else {
        ui->messageLabel->setText("Please enter a value to enqueue.");
    }
}

void MainWindow::on_dequeueButton_clicked()
{
    try {
        int value = m_queue.dequeue();
        ui->queueListWidget->takeItem(0);
        ui->messageLabel->setText(QString("Dequeued: %1").arg(value));
    } catch (const std::runtime_error& e) {
        ui->messageLabel->setText(e.what());
    }
}

void MainWindow::on_findAndMoveMinButton_clicked()
{
    try {
        int minValue = m_queue.findAndMoveMin();
        ui->queueListWidget->clear();
        for (int value : m_queue) {
            ui->queueListWidget->addItem(QString::number(value));
        }
        ui->messageLabel->setText(QString("Minimum value (%1) moved to the front of the queue.").arg(minValue));
    } catch (const std::runtime_error& e) {
        ui->messageLabel->setText(e.what());
    }
}

void MainWindow::on_fillRandomButton_clicked()
{
    const int numRandomValues = 10; // Количество случайных чисел для добавления
    const int minValue = 1;         // Минимальное значение случайного числа
    const int maxValue = 100;       // Максимальное значение случайного числа

    ui->queueListWidget->clear(); // Очистить список в виджете

    for (int i = 0; i < numRandomValues; ++i) {
        int randomValue = minValue + std::rand() % (maxValue - minValue + 1);
        m_queue.enqueue(randomValue);
        ui->queueListWidget->addItem(QString::number(randomValue));
    }

    ui->messageLabel->setText(QString("Queue filled with %1 random values.").arg(numRandomValues));
}
