#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    tmp1=rand();
    char k=char(rand()%40+20);
    tree.insert(tmp1,k);
    QString h =ui->label_2->text();
    h+=(QString::number(tmp1)+ "  "+ k+ "\n");
    ui->label_2->setText(h);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(tree.find_key(tmp1)) ui->label->setText("есть");
    else {
        ui->label->setText("нет");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(tree.find_key(1)) ui->label->setText("есть");
    else {
        ui->label->setText("нет");
    }
}




void MainWindow::on_pushButton_5_clicked()
{
    char k1=char(rand()%40+20);
    s->add(k1);
    QString h =ui->label_2->text();
    h+=(k1);
    ui->label_5->setText(h);
}


void MainWindow::on_pushButton_6_clicked()
{
    if(s->contains(100)) ui->label_3->setText("есть");
    else {
        ui->label_3->setText("нет");
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    char k1=char(rand()%40+26);
    tmp2=rand();
    m.add(tmp2,k1);
    QString h =ui->label_2->text();
    h+=(QString::number(tmp2)+ "  "+ k1+ "\n");
    ui->label_6->setText(h);
}


void MainWindow::on_pushButton_9_clicked()
{
    char a=(m[tmp2]);
    QString k;
    k+=a;
    ui->label_4->setText(k);
}

