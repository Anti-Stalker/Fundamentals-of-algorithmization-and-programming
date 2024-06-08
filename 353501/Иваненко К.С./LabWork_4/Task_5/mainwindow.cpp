#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  initVector();
  updateTables();
}

void MainWindow::initVector()
{
  for (int j = 0; j < 10; j++)
  {
    vector<int> tmp1;
    vector<pair<int, double>> tmp2;
    for (int i = 0; i < 10; ++i)
    {
      tmp1.push_back(generateRandomInt());
      // tmp1.push_back(rand() % 1000);
    }

    for (int i = 0; i < 10; ++i)
    {
      tmp2.push_back(pair(generateRandomInt(), generateRandomDouble()));
      // tmp2.push_back(pair(rand() % 100, (double)(rand() % 1000 + (double)(rand()) / 100)));
    }
    c.push_back(pair(tmp1, tmp2));
  }
}

void MainWindow::updateTables()
{
  ui->tableWidget_1->setRowCount(30);
  ui->tableWidget_1->setColumnCount(10);
  ui->tableWidget_2->setRowCount(30);
  ui->tableWidget_2->setColumnCount(10);
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < c[i].f.size(); ++j)
    {
      auto *item = new QTableWidgetItem(QString::number(c[i].f[j]));
      ui->tableWidget_1->setItem(i * 3, j, item);
    }
  }
  for (int i = 0; i < c.size(); ++i)
  {
    for (int j = 0; j < c[i].s.size(); ++j)
    {
      auto *item = new QTableWidgetItem(QString::number(c[i].s[j].f));
      ui->tableWidget_2->setItem(i * 3, j, item);
      item = new QTableWidgetItem(QString::number(c[i].s[j].s));
      ui->tableWidget_2->setItem(3 * i + 1, j, item);
    }
  }
}

void MainWindow::on_random_clicked()
{
  c.clear();
  initVector();
  updateTables();
  update();
}

int MainWindow::generateRandomInt()
{
  QRandomGenerator::securelySeeded();
  return QRandomGenerator::global()->bounded(-100, 100);
}


double MainWindow::generateRandomDouble()
{
  QRandomGenerator *generator = QRandomGenerator::global();
  return generator->generateDouble() * 200.0 - 100.0;
}

MainWindow::~MainWindow()
{
  delete ui;
}