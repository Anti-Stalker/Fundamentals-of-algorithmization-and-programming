#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPicture>
#include <QGraphicsView>
#include <QPushButton>
#include "rocket.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //QGraphicsView *view = new QGraphicsView(this);
    QGraphicsScene* scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, width_scene, heigth_scene);

    rock = new Rocket;
    scene->addItem(rock);
    rock->setPos(width_scene / 2, heigth_scene);

    QPushButton* button = new QPushButton("Пуск", this);

    QTimer *time = new QTimer();
    connect(time, &QTimer::timeout, this, &MainWindow::moveObj);
    time->start(6);

    connect(button, &QPushButton::clicked, this, &MainWindow::off_onObj);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveObj()
{
    rock->move();
}

void MainWindow::off_onObj()
{
    rock->off_on();
}
