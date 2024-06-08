#include "mainwindow.h"
// #include <string.h>.
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    man = new Buisnessman();
    print();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print()
{
    QString str;
    str+=QString::number(man->cost());
    str+='|';
    str+=QString::number(man->floatSkin());
    str+='|';
    int *id= man->idPlayer();
    for(int i =0 ; i<3;i++)
    {

        str+=QString::number(id[i]);
    }
    str+='|';
    char *n = man->name();
    for(int i =0 ; i<10;i++)
    {
        str+=n[i];
    }
    str+='|';
    if(man->unique())
        str+="true";
    else
        str+="false";
    str+='|';
    str+=QString::number(man->wear());
    ui->label_show->setText(str);

    flagname=false;
    flagwear=false;
    flagcost=false;
    flagfloat=false;
    arrs="";
    forSecond=str;
}

void MainWindow::on_lineEdit_name_textChanged(const QString &arg1)
{
    std::string stdString = arg1.toStdString();
    char *charArray = new char[stdString.size() + 1];
    std::copy(stdString.begin(), stdString.end(), charArray);
    charArray[stdString.size()] = '\0';
    man->name(charArray);
    delete[] charArray;
}

void MainWindow::on_lineEdit_wear_textChanged(const QString &arg1)
{
    char ch = arg1.at(0).toLatin1();
    man->wear(ch);;
}

void MainWindow::on_checkBox_new_stateChanged(int arg1)
{
    man->unique(arg1);
}

void MainWindow::on_spinBox_cost_valueChanged(int arg1)
{
    man->cost(arg1);
}

void MainWindow::on_spinBox_id_valueChanged(int arg1)
{
   arrs+=QString::number(arg1);
}

void MainWindow::on_doubleSpinBox_float_valueChanged(double arg1)
{
    man->floatSkin(arg1);
}

void MainWindow::on_pushButton_clicked()
{
    print();
}

void MainWindow::on_pushButton_2_clicked()
{
    int temp = arrs.toInt();
    man->idPlayer(temp);
    flagfloat=true;
}


void MainWindow::on_pushButton_4_clicked()
{
    man->initializeSkinptr();
    print();
}


void MainWindow::on_pushButton_3_clicked()
{
    man->initializeSkinref();
    print();
}

