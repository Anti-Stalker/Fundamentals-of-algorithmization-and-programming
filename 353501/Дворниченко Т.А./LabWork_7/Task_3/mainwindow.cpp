#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug> // Для отладочных сообщений

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , hashTable(new ExtendedHashTable(10)) // Инициализация хеш-таблицы
{
    ui->setupUi(this);

    connect(ui->pushButtonMinKey, &QPushButton::clicked, this, &MainWindow::on_pushButtonMinKey_clicked);
    connect(ui->pushButtonRandomFill, &QPushButton::clicked, this, &MainWindow::on_pushButtonRandomFill_clicked);
    connect(ui->pushButtonClear, &QPushButton::clicked, this, &MainWindow::on_pushButtonClear_clicked);

    qDebug() << "MainWindow initialized"; // Отладочное сообщение

    updateDisplay();
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow destroyed"; // Отладочное сообщение
    delete ui;
    delete hashTable; // Освобождение памяти
}

void MainWindow::on_pushButtonMinKey_clicked()
{
    if (!hashTable) return;
    int minKey = hashTable->findMinKey();
    ui->plainTextEdit->appendPlainText("Min Key: " + QString::number(minKey));
    qDebug() << "Min key found: " << minKey; // Отладочное сообщение
}

void MainWindow::on_pushButtonRandomFill_clicked()
{
    if (!hashTable) return;
    hashTable->clear();
    for (int i = 0; i < 20; ++i) {
        int key = QRandomGenerator::global()->bounded(100);
        hashTable->insert(key);
    }
    updateDisplay();
    qDebug() << "Hash table randomly filled"; // Отладочное сообщение
}

void MainWindow::on_pushButtonClear_clicked()
{
    if (!hashTable) return;
    hashTable->clear();
    updateDisplay();
    qDebug() << "Hash table cleared"; // Отладочное сообщение
}

void MainWindow::updateDisplay()
{
    if (!hashTable) return;
    ui->plainTextEdit->setPlainText(hashTable->toString());
    qDebug() << "Display updated"; // Отладочное сообщение
}

