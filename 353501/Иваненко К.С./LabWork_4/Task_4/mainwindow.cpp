#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  myTable.getvector(tmp);
  ui->setupUi(this);
  myTable.getui(ui);
  myTable.updatetable();
  
}
void MainWindow::on_push_backbutton_clicked()
{
  myTable.pushback(ui->push_backspinbox->value());
}
void MainWindow::on_resizebutton_clicked()
{
  myTable.res(ui->resizespinbox->value());
}
void MainWindow::on_atbutton_clicked()
{
  myTable.showat(ui->atspinbox->value());
}
void MainWindow::on_endbutton_clicked()
{
  myTable.endshow();
}
void MainWindow::on_beginbutton_clicked()
{
  myTable.beginshow();
}
void MainWindow::on_capacitybutton_clicked()
{
  myTable.showcap();
}
void MainWindow::on_clearbutton_clicked()
{
  myTable.clearpressed();
}
void MainWindow::on_emptubutton_clicked()
{
  myTable.isempty();
}
void MainWindow::on_erasebutton_clicked()
{
  myTable.erasepressed(ui->erasespinbox->value());
}
void MainWindow::on_pop_backbutton_clicked()
{
  myTable.pbpressed();
}
void MainWindow::on_sizebutton_clicked()
{
  myTable.sizepressed();
}
void MainWindow::on_insertbutton_clicked()
{
  myTable.insertpressed(ui->insertindex->value(), ui->insertvalue->value());
}

MainWindow::~MainWindow()
{
  delete ui;
}