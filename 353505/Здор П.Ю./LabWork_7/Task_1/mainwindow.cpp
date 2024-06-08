#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
    int t=(int)rand();

    n.push_back(t);


}


void MainWindow::on_pushButton_2_clicked()
{
    n.pop_back();


}


void MainWindow::on_pushButton_3_clicked()
{
    int t=(int)rand();

    n1.push_back(t);

}


void MainWindow::on_pushButton_4_clicked()
{
    n1.pop_back();

}


void MainWindow::on_pushButton_5_clicked()
{
    int a=n.size();
    int max=0,in1=0,in2=0;
    int min =0;
    for(int i=0;i<a;++i)
    {
        if(min>n.at(i))
        {
            min=n.at(i);
            in1=i;
        }
        if(max<n.at(i))
        {
            max=n.at(i);
            in2=i;
        }
    }
    n.solve(n1,in1,in2);
    QString h="";
    for (int i=0;i<n.size();++i)
    {
        h+=QString::number(n.at(i));
        h+="|";


    }
    ui->label_6->setText(h);
}

