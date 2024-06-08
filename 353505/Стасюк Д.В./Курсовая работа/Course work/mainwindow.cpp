#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <createorderwindow.h>
#include <volume.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    orders.load_from_file("/Users/daryastasiuk/Documents/BSUIR/Courses\ work/d.txt");
    show_vector_in_table(orders.d);
    ui->countOdersLabel->setText(QString::number(orders.d.size()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtGui>
#include <QtQuick3D/qquick3d.h>

void MainWindow::on_openModelButton_clicked()
{
    QString file2Name = QFileDialog::getOpenFileName(this,
                                                     tr("Open STL file"), "~/", tr("STL Files (*.stl)"));
    this->engine.rootContext()->setContextProperty("modelUrl", QUrl::fromLocalFile(file2Name));
}

void MainWindow::show_vector_in_table(std::vector<Order> v) {
    ui->tableWidget->setRowCount(v.size());
    for (int i = 0; i < int(v.size()); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(v[i].id)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(v[i].customerName)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(v[i].modelPath)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(v[i].material)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(v[i].price)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(v[i].volume)));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(v[i].date.toString("dd-MM-yyyy")));
    }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QString mPath = QString::fromStdString(orders.d[row].modelPath);
    this->engine.rootContext()->setContextProperty("modelUrl", QUrl::fromLocalFile(mPath));
}


void MainWindow::on_createOrderButton_clicked()
{
    createOrderW = new CreateOrderWindow(this, &this->engine, &this->orders);
    createOrderW->show();
}


void MainWindow::on_sortByPriceButton_clicked()
{
    heapSort(orders.d, "price");
    show_vector_in_table(orders.d);
}


void MainWindow::on_sortByVolumeButton_clicked()
{
    heapSort(orders.d, "volume");
    show_vector_in_table(orders.d);
}


void MainWindow::on_sortByDateButton_clicked()
{
    heapSort(orders.d, "date");
    show_vector_in_table(orders.d);
}


void MainWindow::on_updateButton_clicked()
{
    orders.d.clear();
    orders.load_from_file("/Users/daryastasiuk/Documents/BSUIR/Courses\ work/d.txt");
    show_vector_in_table(orders.d);
    ui->countOdersLabel->setText(QString::number(orders.d.size()));
}

