#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->spin->setMaximum(10);
    ui->spin->setMinimum(1);
    ui->graphicsView->setScene(scene);
    hTowers = new towers();
    scene->addItem(hTowers);
    ui->restartB->hide();
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->table->setColumnCount(3);

    connect(ui->spin, &QSpinBox::valueChanged, this, &MainWindow::spinSlot);
    connect(ui->startB, &QPushButton::pressed, this, &MainWindow::startSlot);
    connect(ui->restartB, &QPushButton::pressed, this, &MainWindow::restartSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete hTowers;
}

void MainWindow::start(int n, char from, char aux, char to)
{
    if (stop) return;
    if (n == 1)
    {
        moveDisc(n, from, to);

    }
    else
    {
        start(n - 1, from, to, aux);
        moveDisc(n, from, to);
        start(n - 1, aux, from, to);
    }

}

void MainWindow::moveDisc(int number,char from,char to)
{
    hTowers->finished = false;
    while(!hTowers->finished){
        hTowers->animate(10 - number,from,to);
        QCoreApplication::processEvents();
    }
    ui->table->setRowCount(row);
    QTableWidgetItem *itm = new QTableWidgetItem(QString(from));
    ui->table->setItem(row - 1, 0, itm);
    itm = new QTableWidgetItem("->");
    ui->table->setItem(row - 1, 1, itm);
    itm = new QTableWidgetItem(QString(to));
    ui->table->setItem(row - 1, 2, itm);
    ui->table->scrollToBottom();
    row++;
    if (from == 'A') hTowers->lastEmptyPositionA += 20;
    else if (from == 'B') hTowers->lastEmptyPositionB += 20;
    else if (from == 'C') hTowers->lastEmptyPositionC +=20;

    if (number ==1)  ui->restartB->show();
    update();
}

void MainWindow::startSlot()
{
    hTowers->isChanging = false;
    stop=false;
    hTowers->lastEmptyPositionA -= hTowers->posN[hTowers->n - 1];
    hTowers->lastEmptyPositionB -= hTowers->posN[hTowers->n - 1];
    hTowers->lastEmptyPositionC -= hTowers->posN[hTowers->n - 1];
    ui->startB->hide();
    ui->spin->hide();
    ui->label->hide();
    ui->restartB->hide();
    start(hTowers->n, 'A', 'B', 'C');
}


void MainWindow::spinSlot(int value)
{
    hTowers->changeNumberOfRings(value);
    update();
}


void MainWindow::restartSlot()
{
    stop=true;
    delete hTowers;
    hTowers = new towers();



    scene->addItem(hTowers);
    ui->label->show();
    ui->restartB->hide();
     ui->startB->show();
    ui->spin->show();
    ui->spin->setValue(1);
}
