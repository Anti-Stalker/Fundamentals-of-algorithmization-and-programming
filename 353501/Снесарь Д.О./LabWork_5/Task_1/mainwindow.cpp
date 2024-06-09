#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->keyboardW->setFocus();

    ui->lineEdit->loadLevel();
    timer = new QElapsedTimer;
    connect(ui->lineEdit, &customLineEdit::keyPressed, ui->keyboardW, &keyboard::keyPressEventK);
    timer->start();
    QTimer* updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::update);
    connect(ui->lineEdit, &customLineEdit::ending, this, &MainWindow::stop);
    updateTimer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(ui->comboBox->currentIndex() == 6)
    {

    }
    if (!isStarted) return;
    if (event->key() == Qt::Key_Tab) {
          this->setFocus();
        return;
    }
    ui->lineEdit->keyPressEvent(event);
    this->setFocus();

}

void MainWindow::update()
{
    if (!isStarted) return;
    int words = ui->lineEdit->getCorrS() / 5;
    ui->lcdNumber_3->display(1. * words * 60000 / timer->elapsed());
    ui->lcdNumber->display((int)timer->elapsed() / 100);
    ui->lcdNumber_2->display(100. * ui->lineEdit->getCorrS() / ( ui->lineEdit->getPos() == 0 ? 1 : ui->lineEdit->getPos()));
}

void MainWindow::stop()
{
     isStarted = false;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->keyboardW->setLocale(index);
    this->setFocus();
}



void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->loadLevel(1);
     this->setFocus();
}


void MainWindow::on_pushButton_clicked()
{
    isStarted = true;
    timer->restart();
}


void MainWindow::on_pushButton_2_clicked()
{
    stop();
}

