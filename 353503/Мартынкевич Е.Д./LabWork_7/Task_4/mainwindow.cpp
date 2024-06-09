#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->clear();
    for(int i=0;i<16;++i)
    {
        h1->insert((int)rand(),(int)rand());
    }
    for(int i=0;i<64;++i)
    {
        h2->insert((int)rand(),(int)rand());
    }
    for(int i=0;i<128;++i)
    {
        h3->insert((int)rand(),(int)rand());
    }
    for(int i=0;i<2048;++i)
    {
        h4->insert((int)rand(),(int)rand());
    }
    vec1=h3->hash_table_display1();
    vec2=h3->hash_table_display2();
    QString tmp1="";
    QString tmp2="";
    for(int i=0;i<vec1.sizes();++i)
    {
        tmp1+=QString::number(vec1.find(i)->val);
        tmp2+=QString::number(vec2.find(i)->val);
        tmp2+="\n";
        tmp1+="\n";
    }
    ui->textEdit->setText(tmp1+tmp2);
    ui->textEdit_3->clear();
    vec1=h1->hash_table_display1();
    vec2=h1->hash_table_display2();
   tmp1="";
    tmp2="";
    for(int i=0;i<vec1.sizes();++i)
    {
        tmp1+=QString::number(vec1.find(i)->val);
        tmp2+=QString::number(vec2.find(i)->val);
        tmp2+="\n";
        tmp1+="\n";
    }
    ui->textEdit_3->setText(tmp1+tmp2);
    ui->textEdit_4->clear();
    vec1=h2->hash_table_display1();
    vec2=h2->hash_table_display2();
    tmp1="";
    tmp2="";
    for(int i=0;i<vec1.sizes();++i)
    {
        tmp1+=QString::number(vec1.find(i)->val);
        tmp2+=QString::number(vec2.find(i)->val);
        tmp2+="\n";
        tmp1+="\n";
    }
    ui->textEdit_4->setText(tmp1+tmp2);
    ui->textEdit_5->clear();
    vec1=h4->hash_table_display1();
    vec2=h4->hash_table_display2();
    tmp1="";
    tmp2="";
    for(int i=0;i<vec1.sizes();++i)
    {
        tmp1+=QString::number(vec1.find(i)->val);
        tmp2+=QString::number(vec2.find(i)->val);
        tmp2+="\n";
        tmp1+="\n";
    }
    ui->textEdit_5->setText(tmp1+tmp2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    h1->change();
    h2->change();
    h3->change();
    h4->change();
    ui->textEdit->clear();
    for(int i=0;i<16;++i)
    {
        h1->insert((int)rand(),(int)rand());
    }
    for(int i=0;i<64;++i)
    {
        h2->insert((int)rand(),(int)rand());
    }
    for(int i=0;i<128;++i)
    {
        h3->insert((int)rand(),(int)rand());
    }
    for(int i=0;i<2048;++i)
    {
        h4->insert((int)rand(),(int)rand());
    }
    vec1=h3->hash_table_display1();
    vec2=h3->hash_table_display2();
    QString tmp1="";
    QString tmp2="";
    for(int i=0;i<vec1.sizes();++i)
    {
        tmp1+=QString::number(vec1.find(i)->val);
        tmp2+=QString::number(vec2.find(i)->val);
        tmp2+="\n";
        tmp1+="\n";
    }
    ui->textEdit->setText(tmp1+tmp2);
    ui->textEdit_3->clear();
    vec1=h1->hash_table_display1();
    vec2=h1->hash_table_display2();
    tmp1="";
    tmp2="";
    for(int i=0;i<vec1.sizes();++i)
    {
        tmp1+=QString::number(vec1.find(i)->val);
        tmp2+=QString::number(vec2.find(i)->val);
        tmp2+="\n";
        tmp1+="\n";
    }
    ui->textEdit_3->setText(tmp1+tmp2);
    ui->textEdit_4->clear();
    vec1=h2->hash_table_display1();
    vec2=h2->hash_table_display2();
    tmp1="";
    tmp2="";
    for(int i=0;i<vec1.sizes();++i)
    {
        tmp1+=QString::number(vec1.find(i)->val);
        tmp2+=QString::number(vec2.find(i)->val);
        tmp2+="\n";
        tmp1+="\n";
    }
    ui->textEdit_4->setText(tmp1+tmp2);
    ui->textEdit_5->clear();
    vec1=h4->hash_table_display1();
    vec2=h4->hash_table_display2();
    tmp1="";
    tmp2="";
    for(int i=0;i<vec1.sizes();++i)
    {
        tmp1+=QString::number(vec1.find(i)->val);
        tmp2+=QString::number(vec2.find(i)->val);
        tmp2+="\n";
        tmp1+="\n";
    }
    ui->textEdit_5->setText(tmp1+tmp2);

}

