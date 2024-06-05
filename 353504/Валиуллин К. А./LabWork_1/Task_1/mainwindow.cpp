#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "rocket.h"
#include "flames.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    rocket = new Rocket();
    flames = new Flames();
    scene->addItem(rocket);
    timerUp = new QTimer();
    timerDown = new QTimer();
    QTimer::singleShot(0, this, &MainWindow::on_returnButton_clicked);
    connect(timerUp, &QTimer::timeout, this, &MainWindow::onAnimationUpFinished);
    connect(timerDown, &QTimer::timeout, this, &MainWindow::onAnimationDownFinished);
    onAnimationDownFinished();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_returnButton_clicked()
{
    if(!isReturned) {
        rocket->moveLineDown();
        timerDown->start(2000);
        isReturned = true;
    }
}

void MainWindow::on_launchButton_clicked()
{
    if (isReturned) {
        scene->addItem(flames);
        rocket->moveLineUp();
        flames->moveLineUp();
        timerUp->start(1000);
        QTimer::singleShot(1000, this, &MainWindow::removeFlames);
        isReturned = false;
    }
}

void MainWindow::onAnimationUpFinished()
{
    timerUp->stop();
    ui->returnButton->setEnabled(true);
    ui->launchButton->setEnabled(false);
}

void MainWindow::onAnimationDownFinished()
{
    timerDown->stop();
    ui->returnButton->setEnabled(false);
    ui->launchButton->setEnabled(true);
}

void MainWindow::removeFlames()
{
    scene->removeItem(flames);
}

void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    rocket->setPos(0,rocket->startY);
}
