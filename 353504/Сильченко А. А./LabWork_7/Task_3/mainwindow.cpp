#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette p(ui->centralwidget->palette());
    p.setColor(QPalette::Window, QColor(219, 243, 246));
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(p);
    ui->plainTextEdit->setPalette(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_On_insert_clicked()
{
    int val = ui->inBox->value();
    HT.insert(val);
    ui->plainTextEdit->setPlainText(QString::fromStdString(HT.toString()));
}


void MainWindow::on_On_remove_clicked()
{
    int val = ui->inBox->value();
    HT.remove(val);
    ui->plainTextEdit->setPlainText(QString::fromStdString(HT.toString()));
}

void MainWindow::on_On_search_clicked()
{
    int val = ui->inBox->value();
    bool Is = HT.search(val);
    QString expr = "The key was" + QString(Is ? " " : " not ") + "found";
    ui->plainTextEdit->setPlainText(expr);
}

void MainWindow::on_On_print_clicked()
{
    QString expr = QString::fromStdString(HT.toString());
    ui->plainTextEdit->setPlainText(expr);
}


void MainWindow::on_On_clear_clicked()
{
    ui->plainTextEdit->clear();
}


void MainWindow::on_On_search_min_clicked()
{
    QString str = "Min key is : ";
    int val = HT.findMinKey();
    str += QString::number(val);
    ui->plainTextEdit->setPlainText(str);
}


void MainWindow::on_On_Fill_clicked()
{
    for (int i = 0; i < static_cast<int>(HT.getSize()); ++i)
    {
        int val = QRandomGenerator::global()->bounded(100);;
        HT.insert(val);
    }

}

