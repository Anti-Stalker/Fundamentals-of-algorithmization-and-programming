#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    int W_WIDTH = 800;
    int W_HEIGHT = 600;
    scene = new QGraphicsScene(0,0,W_WIDTH,W_HEIGHT);
    ui->graphicsView->setScene(scene);
    locom = new Locomotive(scene);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);
    timer->start(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout()
{
    if (locom->get_left_x()>W_WIDTH) {
        locom->reset_position_x(-300);
    }
    locom->shift_x(10);
}

void MainWindow::on_stop_clicked()
{
    if (timer->isActive()) {
        timer->stop();
    } else {
        timer->start();
    }

}

void MainWindow::on_pushButton_clicked()
{
    if (timer->interval() < 10) {
        QMessageBox::about(this, "Speed Notification", "Speed limit is reached.");
    } else {
        timer->setInterval(timer->interval()-3);
    }

}

void MainWindow::on_speedDownButton_clicked()
{
    if (timer->interval() > 200) {
        QMessageBox::about(this, "Speed Notification", "Speed is very low.");
    } else {
        timer->setInterval(timer->interval()+5);
    }
}

