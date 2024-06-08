#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tableWidget=ui->tableWidget;


    ui->tableWidget->update();
    ui->pushButton_5->setHidden(true);
     ui->pushButton_3->setHidden(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check(QString s,int sch=0,bool fl=0){
    if(s.length()==10){
        while(sch<11){
            if((s[sch-1]<'0' || s[sch-1]>'9') && sch-1!=2 && sch-1!=5){
                fl=1;
            }
            if((sch-1==2 ||  sch-1== 5) && s[sch-1]!='.'){
                fl=1;
            }
            sch++;
        }
        if(!fl){
            year=s[6].digitValue()*1000+s[7].digitValue()*100+s[8].digitValue()*10+s[9].digitValue();
            if(s[0].digitValue()*10+s[1].digitValue()>0 && s[0].digitValue()*10+s[1].digitValue()<32 && s[3].digitValue()*10+s[4].digitValue()<13 && s[3].digitValue()*10+s[4].digitValue()>0){
                if(year>0 && year<10000){

                    if(s[3].digitValue()*10+s[4].digitValue()==4 || s[3].digitValue()*10+s[4].digitValue()==6 || s[3].digitValue()*10+s[4].digitValue()==9 || s[3].digitValue()*10+s[4].digitValue()==11){
                        if(s[0].digitValue()*10+s[1].digitValue()<=30){
                        return true;
                        }
                        else return false;
                    }
                    else if(s[3].digitValue()*10+s[4].digitValue()==2 && year%400==0 || (year%4==0 && year%100!=0)  ){
                        if(s[0].digitValue()*10+s[1].digitValue()<=29) return true;
                        else return false;
                    }
                    else if(s[3].digitValue()*10+s[4].digitValue()==2){
                        if(s[0].digitValue()*10+s[1].digitValue()<=28) return true;
                        else return false;
                    }
                    else return true;


                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false ;
}

void MainWindow::cr(QString a){
    date=new QList <Date>;
    QFile t=(a);
    files=a;
    QTableWidgetItem *l;
    t.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&t);
    QString line;
    rest=0;
    out=0;
    fl2=0;

    ui->tableWidget->setRowCount(0);
    while(!in.atEnd()){
        ui->tableWidget->setRowCount(rest);
        ui->tableWidget->insertRow(rest);
        line=in.readLine();
        if(check(line,sch,fl)){
        date->append(Date(0,0,0));
        date[0][rest].create(line);
        l= new QTableWidgetItem(line);
        item.append(*l);
        ui->tableWidget->setItem(rest,0,l);
         l->setFlags(l->flags() ^ Qt::ItemIsEditable);
        out++;
         l= new QTableWidgetItem(date[0][rest].output());
         ui->tableWidget->setItem(rest,5,l);
         l->setFlags(l->flags() ^ Qt::ItemIsEditable);
        l= new QTableWidgetItem(date[0][rest].output_string(date[0][rest]));
        item.append(*l);
        ui->tableWidget->setItem(rest,1,l);
         l->setFlags(l->flags() ^ Qt::ItemIsEditable);
        l= new QTableWidgetItem((date[0][rest].output_string_1(date[0][rest])));
        item.append(*l);
        ui->tableWidget->setItem(rest,4,l);
        l->setFlags(l->flags() ^ Qt::ItemIsEditable);
        l= new QTableWidgetItem(date[0][rest].outp_n(date[0][rest]));
        ui->tableWidget->setItem(rest,3,l);
        l->setFlags(l->flags() ^ Qt::ItemIsEditable);
        l= new QTableWidgetItem(date[0][rest].outp(date[0][rest]));
        ui->tableWidget->setItem(rest,2,l);
         l->setFlags(l->flags() ^ Qt::ItemIsEditable);

        rest++;
        }
        else {
            QMessageBox::critical(nullptr,"Error","Error appeared");
            break;
        }
    }
    fl1=1;
    t.close();
}
void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{

}

void MainWindow::openfile(){
    QString filep=QFileDialog::getOpenFileName(nullptr,"Open file","","Text files (*.txt)");
    cr(filep);
    files=filep;
    ui->tableWidget->update();
}

void MainWindow::on_pushButton_clicked()
{
    openfile();
}





void MainWindow::on_lineEdit_4_textEdited(const QString &arg1)
{
    if(fl1){
        if(arg1.length()==0){
            ui->pushButton_5->setHidden(true);
            return;
        }

        if(arg1.length()==10){
            QTableWidgetItem *l;
            QString line=arg1;

            if(check(line,sch,fl)){
                fl2=1;
                ui->pushButton_5->setHidden(false);
                a=line;
            }
            else {
                QMessageBox::critical(nullptr,"Error","Error appeared");
                ui->lineEdit_4->clear();
                fl2=0;
            }

        }
    }
    else {
    if(arg1.length()==0){
        ui->pushButton_5->setHidden(true);
        return;
    }

        if(arg1.length()==10){
            QTableWidgetItem *l;
            QString line=arg1;

        if(check(line,sch,fl)){
            fl2=1;
            ui->pushButton_5->setHidden(false);
            a=line;
        }
        else {
            QMessageBox::critical(nullptr,"Error","Error appeared");
            ui->lineEdit_4->clear();
            fl2=0;
        }
        }
    }

}



void MainWindow::on_pushButton_5_clicked()
{
    if(fl2)
    {
    ui->tableWidget->setRowCount(rest);
    ui->tableWidget->insertRow(rest);
    QTableWidgetItem *l;
    QString line=a;
    date->append(Date(0,0,0));
    date[0][rest].create(line);
    l= new QTableWidgetItem(line);
    item.append(*l);
    ui->tableWidget->setItem(rest,0,l);
    l->setFlags(l->flags() ^ Qt::ItemIsEditable);
    out++;
     l= new QTableWidgetItem((date[0][rest].output_string_1(date[0][rest])));
    item.append(*l);
    ui->tableWidget->setItem(rest,4,l);
    l->setFlags(l->flags() ^ Qt::ItemIsEditable);
    l= new QTableWidgetItem(date[0][rest].output());
    ui->tableWidget->setItem(rest,5,l);
    l->setFlags(l->flags() ^ Qt::ItemIsEditable);
    l= new QTableWidgetItem(date[0][rest].output_string(date[0][rest]));
    item.append(*l);
    ui->tableWidget->setItem(rest,1,l);
    l->setFlags(l->flags() ^ Qt::ItemIsEditable);

    l= new QTableWidgetItem(date[0][rest].outp_n(date[0][rest]));
    ui->tableWidget->setItem(rest,3,l);
    l->setFlags(l->flags() ^ Qt::ItemIsEditable);
    l= new QTableWidgetItem(date[0][rest].outp(date[0][rest]));
    ui->tableWidget->setItem(rest,2,l);
    l->setFlags(l->flags() ^ Qt::ItemIsEditable);
    QFile t=(files);
    t.open(QIODevice::ReadWrite);
    QTextStream in(&t);
    for(int i=0;i<rest;++i){
        in.readLine();
    }
    t.seek(in.pos());
    in << a << Qt::endl;
    t.close();
    rest++;
    }
}


void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    if(arg1.length()==10){
        QTableWidgetItem *l;
        QString line=arg1;

        if(check(line,sch,fl)){
            a=line;
            d=new Date(0,0,0);
            d->create(line);
            ui->label_6->setText(QString::number((d->DateTillYourBirthday(*d))));
        }
        else {
            QMessageBox::critical(nullptr,"Error","Error appeared");
            ui->lineEdit_3->clear();
        }
    }
}
bool MainWindow::ch(int a){
    if(a<0 || a>rest) return false;
            else return true;
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    fl3=0;
    if(arg1.length()==0){
        ui->pushButton_3->setHidden(true);
        return;
    }

    tempd=0;
    QString a=arg1;
    if(a[0]>='0' && a[0]<='9'){
    tempd+=a[0].digitValue();
    }
    else {
        QMessageBox::critical(nullptr,"Error","Error appeared");
        ui->lineEdit_2->clear();
        return;
    }
    for(int i= a.length()-2;i>-1;--i){

        tempd*=10;
        if(a[i]>='0' && a[i]<='9'){
            tempd+=a[i].digitValue();
        }
        else {
            QMessageBox::critical(nullptr,"Error","Error appeared");
            ui->lineEdit_2->clear();
            return;
        }
    }
    if(!ch(tempd)){
        QMessageBox::critical(nullptr,"Error","Error appeared");
        ui->lineEdit_2->clear();
    }
    else {
        fl3=1;
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    fl4=0;
    if(fl1 && fl3){
        if(arg1.length()==10){
            QTableWidgetItem *l;
            a=arg1;

            if(check(a,sch,fl)){
                fl4=1;
                ui->pushButton_3->setHidden(false);
                QFile t=(files);
                t.open(QIODevice::ReadWrite | QIODevice::Text);
                QTextStream stream(&t);
                for(int i=0;i<tempd-1;++i){
                    stream.readLine();
                }
                qint64 pos=stream.pos();
                t.seek(pos);
                stream << a << Qt::endl;
                t.close();
            }
            else {
                QMessageBox::critical(nullptr,"Error","Error appeared");
                ui->lineEdit_3->clear();
            }
        }
    }
    else if(fl3){
        if(arg1.length()==10){
            QTableWidgetItem *l;
            a=arg1;

            if(check(a,sch,fl)){
                fl4=1;
                 ui->pushButton_3->setHidden(false);
            }
            else {
                QMessageBox::critical(nullptr,"Error","Error appeared");
                ui->lineEdit_3->clear();
            }
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(fl4){
        QTableWidgetItem *l;
        QString line=a;
        date[0][tempd-1].create(line);
        l= new QTableWidgetItem(line);
        item.append(*l);
        ui->tableWidget->setItem(tempd-1,0,l);
        l->setFlags(l->flags() ^ Qt::ItemIsEditable);
        out++;
        l= new QTableWidgetItem((date[0][rest].output_string_1(date[0][rest])));
        item.append(*l);
        ui->tableWidget->setItem(rest,4,l);
        l->setFlags(l->flags() ^ Qt::ItemIsEditable);
        l= new QTableWidgetItem(date[0][tempd-1].output());
        ui->tableWidget->setItem(tempd-1,5,l);
        l->setFlags(l->flags() ^ Qt::ItemIsEditable);
        l= new QTableWidgetItem(date[0][tempd-1].output_string(date[0][tempd-1]));
        item.append(*l);
        ui->tableWidget->setItem(tempd-1,1,l);
        l->setFlags(l->flags() ^ Qt::ItemIsEditable);

        l= new QTableWidgetItem(date[0][tempd-1].outp_n(date[0][tempd-1]));
        ui->tableWidget->setItem(tempd-1,3,l);
        l->setFlags(l->flags() ^ Qt::ItemIsEditable);
        l= new QTableWidgetItem(date[0][tempd-1].outp(date[0][tempd-1]));
        ui->tableWidget->setItem(tempd-1,2,l);
        l->setFlags(l->flags() ^ Qt::ItemIsEditable);

    }
}

