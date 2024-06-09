#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic ("acer.png");

    ui->label->setPixmap(pic);

    ui->m->setMaximum(3);
    ui->n->setMaximum(9);

    connect(ui->ansB, &QPushButton::pressed, this, &MainWindow::printAcer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

long double MainWindow::Acer(int m, int n)
{
    if (m==0) return n+1;
    if (m>0 && n==0) return Acer(m-1,1);
    if (m>0 && n>0) return Acer(m-1, Acer(m,n-1));
    return 1;
}

void MainWindow::printAcer()
{
    int ans = Acer(ui->m->text().toInt(),  ui->n->text().toInt());
    ui->ansL->setText(QString::number(ans));
}
