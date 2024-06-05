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

void MainWindow::on_openfile_btn_clicked()
{

    QString path = QFileDialog::getOpenFileName();

    QFile file(path);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    };

    QTextStream in (&file);
    int i= 0;
    ui->input->clear();
    while(!in.atEnd())
    {

        QString line = in.readLine();

        QStringList words = line.split(" ", Qt::SkipEmptyParts);

        Workers *newWork = new Workers(words[0], words[1], words[2], words[3], words[4], words[5]);
        worker.push_back(*newWork);

        ui->input->insertRow(ui->input->rowCount());

        QString s = words[0];
        QTableWidgetItem *itm0 = new QTableWidgetItem(s);
        ui->input->setItem(i,0,itm0);

        s = words[1];
        QTableWidgetItem *itm1 = new QTableWidgetItem(s);
        ui->input->setItem(i,1,itm1);

        s = words[2];
        QTableWidgetItem *itm2 = new QTableWidgetItem(s);
        ui->input->setItem(i,2,itm2);

        s = words[3];
        QTableWidgetItem *itm3 = new QTableWidgetItem(s);
        ui->input->setItem(i,3,itm3);

        s = words[4];
        QTableWidgetItem *itm4 = new QTableWidgetItem(s);
        ui->input->setItem(i,4,itm4);

        s = words[5];
        QTableWidgetItem *itm5 = new QTableWidgetItem(s);
        ui->input->setItem(i,5,itm5);

        s = words[5];
        QTableWidgetItem *itm6 = new QTableWidgetItem(s);
        ui->input->setItem(i,6,itm6);
        i++;
    }
}


void MainWindow::on_sorter_clicked()
{
    for (int i = 0; i < worker.size()-1; i++)
    {
        for (int j = 0; j < worker.size()-i-1; j++)
        {
            QDate pretime = QDate::fromString(worker[j].cDate);
            QDate time = QDate::fromString(worker[j+1].cDate);
            if ( pretime > time) {
                std::swap(worker[j], worker[j+1]);
            }
        }
    }


    ui->input->clear();
    ui->input->update();

    for (int i = 0; i < worker.size(); i++)
    {
        //ui->input->insertRow(ui->input->rowCount());


        QTableWidgetItem *itm0 = new QTableWidgetItem(worker[i].getfName());
        ui->input->setItem(i,0,itm0);


        QTableWidgetItem *itm1 = new QTableWidgetItem(worker[i].getpName());
        ui->input->setItem(i,1,itm1);


        QTableWidgetItem *itm2 = new QTableWidgetItem(worker[i].gettName());
        ui->input->setItem(i,2,itm2);


        QTableWidgetItem *itm3 = new QTableWidgetItem(worker[i].getcDate());
        ui->input->setItem(i,3,itm3);


        QTableWidgetItem *itm4 = new QTableWidgetItem(worker[i].getsDate());
        ui->input->setItem(i,4,itm4);


        QTableWidgetItem *itm5 = new QTableWidgetItem(worker[i].getfDate());
        ui->input->setItem(i,5,itm5);
    }
}


void MainWindow::on_fiosearch_btn_clicked()
{
    ui->input->clear();
    QString name = ui->fiosearch->text();
    for (int i = 0; i < worker.size(); ++i)
    {
        if ( worker[i].fName == name )
        {
            ui->input->insertRow(ui->input->rowCount());
            QTableWidgetItem *itm0 = new QTableWidgetItem(worker[i].getfName());
            ui->input->setItem(i,0,itm0);


            QTableWidgetItem *itm1 = new QTableWidgetItem(worker[i].getpName());
            ui->input->setItem(i,1,itm1);


            QTableWidgetItem *itm2 = new QTableWidgetItem(worker[i].gettName());
            ui->input->setItem(i,2,itm2);


            QTableWidgetItem *itm3 = new QTableWidgetItem(worker[i].getcDate());
            ui->input->setItem(i,3,itm3);


            QTableWidgetItem *itm4 = new QTableWidgetItem(worker[i].getsDate());
            ui->input->setItem(i,4,itm4);


            QTableWidgetItem *itm5 = new QTableWidgetItem(worker[i].getfDate());
            ui->input->setItem(i,5,itm5);
        }
    }
}

