#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "queue.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  Queue mainQueue;
  for (int i = 0; i < 10; ++i)
  {
    int value = rand() % 21 - 10;
    Node *newNode = new Node(value);
    mainQueue.enqueue(newNode);
  }

  qDebug() << "Main Queue: ";
  qDebug() << mainQueue.output();
  ui->main->setText(mainQueue.output());

  Queue negativeQueue;
  Queue positiveQueue;
  mainQueue.splitQueue(negativeQueue, positiveQueue);

  qDebug() << "Negative Queue: ";
  qDebug() << negativeQueue.output();
  ui->negative->setText(negativeQueue.output());

  qDebug() << "Positive Queue: ";
  qDebug() << positiveQueue.output();
  ui->positive->setText(positiveQueue.output());
}

MainWindow::~MainWindow()
{
}
