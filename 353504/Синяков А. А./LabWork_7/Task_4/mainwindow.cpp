#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <QTime>
#include<QElapsedTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->tableIndexSpinBox->setMaximum(3);

    // Создание хеш-таблиц с разными размерами
    hashTables.push_back(new MyHashTable(16));
    hashTables.push_back(new MyHashTable(64));
    hashTables.push_back(new MyHashTable(128));
    hashTables.push_back(new MyHashTable(2048));

    // Заполнение хеш-таблиц случайными строками
    for (auto &ht : hashTables) {
        ht->generateAndFill(ht->getSize() / 2); // Заполнение элементами
    }

    // Вывод содержимого первой хеш-таблицы в QTextEdit
    ui->outputTextEdit->append("Hash Table Contents:");
    ui->outputTextEdit->append(hashTables[0]->print());
}

MainWindow::~MainWindow()
{
    delete ui;
    for (auto &ht : hashTables) {
        delete ht;
    }
}

void MainWindow::on_FindMaxStackButton_clicked()
{
    int tableIndex = ui->tableIndexSpinBox->value();
    if (tableIndex >= 0 && tableIndex < hashTables.size()) {
        QElapsedTimer timer;
        timer.start();
        int maxStackIndex = hashTables[tableIndex]->findMaxStack();
        double elapsedTime = timer.nsecsElapsed() / 1000000000.0; // Время в секундах
        QString message = "Max stack index: " + QString::number(maxStackIndex) + " (found in " + QString::number(elapsedTime, 'f', 6) + " seconds)";
        ui->outputTextEdit->append(message);
    }


}


void MainWindow::on_SearchButton_clicked()
{
    QString key = ui->inputLineEdit->text();
    QVector<double> searchTimes;

    for (int i = 0; i < hashTables.size(); ++i) {
        QElapsedTimer timer;
        timer.start();
        if (hashTables[i]->find(key)) {
            double elapsedTime = timer.nsecsElapsed() / 1000000000.0; // Время в секундах
            QString message = "Found key " + key + " in table " + QString::number(i) + " in " + QString::number(elapsedTime, 'f', 6) + " seconds";
            ui->outputTextEdit->append(message);
            searchTimes.append(elapsedTime);
        }
        else {
            searchTimes.append(0.0); // Если ключ не найден, добавляем 0.0 секунд
        }
    }

    if (searchTimes.contains(0.0)) {
        ui->outputTextEdit->append("Key not found: " + key);
    }

    // После завершения поиска обновляем диаграмму
    updateSearchTimesAndGraph(searchTimes);
}

void MainWindow::updateSearchTimesAndGraph(const QVector<double> &searchTimes)
{
    scene->clear();
    int margin = 50;
    int width = 400;
    int height = 300;

    // Draw axes
    QGraphicsLineItem* xAxis = new QGraphicsLineItem(margin, height + margin, width + margin, height + margin);
    QGraphicsLineItem* yAxis = new QGraphicsLineItem(margin, margin, margin, height + margin);
    scene->addItem(xAxis);
    scene->addItem(yAxis);

    // Определение максимального времени поиска
    double maxSearchTime = *std::max_element(searchTimes.constBegin(), searchTimes.constEnd());

    int columnWidth = (width - margin * 2) / searchTimes.size();
    for (int i = 0; i < searchTimes.size(); ++i) {
        double searchTime = searchTimes[i];
        int columnHeight = height * (searchTime / maxSearchTime);
        QGraphicsRectItem* column = new QGraphicsRectItem(margin + i * columnWidth, height + margin - columnHeight, columnWidth, columnHeight);
        column->setBrush(Qt::blue);
        scene->addItem(column);
    }
}
void MainWindow::on_tableIndexSpinBox_valueChanged(int index)
{
    if (index >= 0 && index < hashTables.size()) {
        ui->outputTextEdit->clear();
        ui->outputTextEdit->append("Hash Table Contents:");
        ui->outputTextEdit->append(hashTables[index]->print());
    }
}
