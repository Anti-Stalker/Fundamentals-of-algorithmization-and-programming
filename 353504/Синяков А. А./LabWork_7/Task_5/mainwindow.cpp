#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushBackButton_clicked() {
    bool ok;
    int value = ui->valueInput->text().toInt(&ok);
    if (ok) {
        deque.push_back(value);
        updateDequeDisplay();
    }
}

void MainWindow::on_pushFrontButton_clicked() {
    bool ok;
    int value = ui->valueInput->text().toInt(&ok);
    if (ok) {
        deque.push_front(value);
        updateDequeDisplay();
    }
}

void MainWindow::on_popBackButton_clicked() {
    try {
        deque.pop_back();
        updateDequeDisplay();
    } catch (const std::out_of_range& e) {
        // Handle error
    }
}

void MainWindow::on_popFrontButton_clicked() {
    try {
        deque.pop_front();
        updateDequeDisplay();
    } catch (const std::out_of_range& e) {
        // Handle error
    }
}

void MainWindow::on_clearButton_clicked() {
    deque.clear();
    updateDequeDisplay();
}

void MainWindow::updateDequeDisplay() {
    ui->dequeDisplay->clear();
    for (size_t i = 0; i < deque.size(); ++i) {
        ui->dequeDisplay->append(QString::number(deque[i]));
    }
    ui->sizeLabel->setText(QString::number(deque.size()));
    ui->emptyLabel->setText(deque.empty() ? "True" : "False");
}
