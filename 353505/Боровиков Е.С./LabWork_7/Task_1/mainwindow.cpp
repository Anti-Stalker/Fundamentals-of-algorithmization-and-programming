#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Связь сигналов и слотов
    connect(ui->ADD, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->Sort, &QPushButton::clicked, this, &MainWindow::on_sortButton_clicked);
    updateListWidget();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    bool ok;
    int value = QInputDialog::getInt(this, tr("Add Value"),
                                     tr("Value:"), 0, -2147483647, 2147483647, 1, &ok);
    if (ok) {
        queue.enqueue(value);
        updateListWidget();
    }
}

void MainWindow::on_sortButton_clicked() {
    queue.bubbleSort();
    updateListWidget();
}

void MainWindow::updateListWidget() {
    ui->listWidget->clear();
    QStringList items = queue.toString().split(' ');
    ui->listWidget->addItems(items);
}
