#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_On_insert_2_clicked()
{
    map.insert(ui->inBox_2->value(),ui->inValue->text().toStdString());
}

void MainWindow::on_On_delete_clicked()
{
    map.remove(ui->inBox_2->value());
}

void MainWindow::on_On_ExtractMax_clicked()
{
    QString str = "The key is ";
    str += map.contains(ui->inBox_2->value())? "contains " : "is not contains ";
    str += "the key " + QString::number(ui->inBox_2->value());
    ui->textEdit->setText(str);
}

void MainWindow::on_On_print_clicked()
{
    ui->textEdit->setText(QString::fromStdString(map.to_string()));
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    map.drawTree(scene);
}

void MainWindow::on_On_clear_2_clicked()
{
    map.clear();
    ui->textEdit->clear();
}

