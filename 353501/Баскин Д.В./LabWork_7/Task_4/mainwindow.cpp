#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_pushButton_reset_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateInfo()
{
{
    ui->listWidget16->clear();
    auto vec = table16x->toVector();
    QString str;
    for (int i = 0; i < vec.size(); ++i)
    {
        str += QString::number(i) + ": ";
        str += QString::number(vec[i].first) + "," + QString::number(vec[i].second) + "\n\n";
    }
    ui->listWidget16->addItem(str);
}
{
    ui->listWidget64->clear();
    auto vec = table64x->toVector();
    QString str;
    for (int i = 0; i < vec.size(); ++i)
    {
        str += QString::number(i) + ": ";
        str += QString::number(vec[i].first) + "," + QString::number(vec[i].second) + "\n\n";
    }
    ui->listWidget64->addItem(str);
}
{
    ui->listWidget128->clear();
    auto vec = table128x->toVector();
    QString str;
    for (int i = 0; i < vec.size(); ++i)
    {
        str += QString::number(i) + ": ";
        str += QString::number(vec[i].first) + "," + QString::number(vec[i].second) + "\n\n";
    }
    ui->listWidget128->addItem(str);
}
{
    ui->listWidget2048->clear();
    auto vec = table2048x->toVector();
    QString str;
    for (int i = 0; i < vec.size(); ++i)
    {
        str += QString::number(i) + ": ";
        str += QString::number(vec[i].first) + "," + QString::number(vec[i].second) + "\n\n";
    }
    ui->listWidget2048->addItem(str);
}
}

void MainWindow::on_pushButton_reset_clicked()
{
    table16x = new HashTable(16);
    for (int i = 0; i < 16; ++i)
    {
        table16x->addItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    table64x = new HashTable(64);
    for (int i = 0; i < 64; ++i)
    {
        table64x->addItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    table128x = new HashTable(128);
    for (int i = 0; i < 128; ++i)
    {
        table128x->addItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    table2048x = new HashTable(1024);
    for (int i = 0; i < 1024; ++i)
    {
        table2048x->addItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    UpdateInfo();
}


void MainWindow::on_pushButton_find_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int result16 = table16x->findItem(ui->spinBox->value());

    qint64 elapsed16 = timer.elapsed();
    ui->label_16->setText("res: " + QString::number(result16) + " time: " + QString::number(elapsed16) + " ms");

    timer.start();

    int result64 = table64x->findItem(ui->spinBox->value());

    qint64 elapsed64 = timer.elapsed();
    ui->label_64->setText("res: " + QString::number(result64) + " time: " + QString::number(elapsed64) + " ms");

    timer.start();

    int result128 = table128x->findItem(ui->spinBox->value());

    qint64 elapsed128 = timer.elapsed();
    ui->label_128->setText("res: " + QString::number(result128) + " time: " + QString::number(elapsed128) + " ms");

    timer.start();

    int result2048 = table2048x->findItem(ui->spinBox->value());

    qint64 elapsed2048 = timer.elapsed();

    ui->label_2048->setText("res: " + QString::number(result2048) + " time: " + QString::number(elapsed2048) + " ms");

    QGraphicsView *view = ui->graphicsView;
    QGraphicsScene *scene = new QGraphicsScene(this);
    view->setScene(scene);
    QGraphicsRectItem *bar16 = new QGraphicsRectItem(0, -(elapsed16), 140, elapsed16);
    bar16->setBrush(Qt::yellow);
    QGraphicsRectItem *bar64 = new QGraphicsRectItem(150, -(elapsed64), 140, elapsed64);
    bar64->setBrush(Qt::yellow);
    QGraphicsRectItem *bar128 = new QGraphicsRectItem(310, -(elapsed128), 140, elapsed128);
    bar128->setBrush(Qt::yellow);
    QGraphicsRectItem *bar2048 = new QGraphicsRectItem(470, -(elapsed2048), 140, elapsed2048);
    bar2048->setBrush(Qt::yellow);
    scene->addItem(bar16);
    scene->addItem(bar64);
    scene->addItem(bar128);
    scene->addItem(bar2048);
}
