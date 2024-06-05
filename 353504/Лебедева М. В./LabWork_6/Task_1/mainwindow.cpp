#include "mainwindow.h"
#include "ui_mainwindow.h"

#define struct(x) ui->s##x->setText(QString::fromStdString(toString(worker_##x)))

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

bool MainWindow::check()
{
    worker_3.vacationDays[1]=-1;

    //Count of projects
    std::string cP=ui->textEdit_7->toPlainText().toStdString();

    qDebug()<<cP.size();

    if(cP.size()==0)
        return false;
    for(auto& i:cP)
    {
       if(!(i>='0'&&i<='9'))
            return false;
    }

    int c;
    try
    {
        c=stoi(cP);
     }catch(...){
        return false;
    }

    qDebug()<<"count of projects ok";

    //Age
    std::string ag=ui->textEdit->toPlainText().toStdString();

    if(ag.size()==0)
        return false;
    for(auto& i:ag)
    {
        if(!(i>='0'&&i<='9'))
            return false;
    }

    int age;
    try
    {
        age=stoi(ag);
    }catch(...){
        return false;
    }
    qDebug()<<"age ok";

    //Gender
    std::string ge=ui->textEdit_2->toPlainText().toStdString();;
    if(ge.size()>1||ge.size()==0)
        return false;

    char gender=ge[0];

    if(!(gender=='M'||gender=='W'))
        return false;

    qDebug()<<"gender ok";

    //Works
    std::string wor=ui->textEdit_3->toPlainText().toStdString();;
    if(wor.size()>1||wor.size()==0)
        return false;

    char w=wor[0];

    if(!(w=='1'||w=='0'))
        return false;

    bool works=w-'0';
    qDebug()<<"works ok";

    //Salary
    std::string sal=ui->textEdit_4->toPlainText().toStdString();

    if(sal.size()==0)
        return false;

    bool point=false;
    for(auto& i:sal)
    {
        if(i=='.')
        {
            if(point)return false;
            point=true;
        }else
            if(!(i>='0'&&i<='9'))
                return false;
    }

    double salary;
    try
    {
        salary=stod(sal);
    }catch(...){
        return false;
    }

    qDebug()<<"salary ok";

    //Name
    std::string name=ui->textEdit_5->toPlainText().toStdString();
    if(name.size()==0)
        return false;

    qDebug()<<"name ok:"<<name;

    //VacationDays
    std::string vD=ui->textEdit_6->toPlainText().toStdString();

    if(vD.size()==0)
        return false;
    for(auto& i:vD)
    {
        if(!(i>='0'&&i<='9'))
            return false;
    }

    int vacationDays;
    try
    {
        vacationDays=stoi(vD);
    }catch(...){
        return false;
    }
    qDebug()<<"vacationDays ok";

    worker_3.salary=salary;
    worker_3.name=new char [name.size()+1];
    for(int i=0;i<name.size();i++)
        worker_3.name[i]=name[i];
    worker_3.name[name.size()]='\0';
    worker_3.works=works;
    worker_3.age=age;
    worker_3.gender=gender;
    worker_3.vacationDays[0]=vacationDays;
    worker_3.vacationDays[1]=c;
    return true;
}

void MainWindow::setStructs()
{
    struct(1);
    struct(2);
    qDebug()<<worker_3.name;
    if(worker_3.vacationDays[1]!=-1)
        struct(3);
    else
        ui->s3->clear();

    //4
    std::string res;
    int i=0;
    while(worker_4->name[i]!='\0')
        res+=worker_4->name[i++];
    res+=" | ";
    res+=worker_4->gender;
    res+=" | ";
    res+=std::to_string(worker_4->salary);
    res+=" | ";
    res+=std::to_string(worker_4->age);
    res+=" | ";
    res+=std::to_string(worker_4->vacationDays[0]);
    res+=" | ";
    res+=std::to_string(worker_4->vacationDays[1]);
    res+=" | ";
    if(worker_4->works)
        res+="works";
    else
        res+="not works";
    ui->s4->setText(QString::fromStdString(res));

    //5
    struct(5);
}

std::string MainWindow::toString(Worker x)
{
    std::string res;
    int i=0;
    while(x.name[i]!='\0')
        res+=x.name[i++];
    res+=" | ";
    res+=x.gender;
    res+=" | ";
    res+=std::to_string(x.salary);
    res+=" | ";
    res+=std::to_string(x.age);
    res+=" | ";
    res+=std::to_string(x.vacationDays[0]);
    res+=" | ";
    res+=std::to_string(x.vacationDays[1]);
    res+=" | ";
    if(x.works)
        res+="works";
    else
        res+="not works";
    return res;
}

void MainWindow::on_pushButton_clicked()
{
    //Worker 1
    worker_1={25,'M',false,750000,"WorkerArtiom",{30, 10}};
    //Worker 2
    worker_2.age=39;
    worker_2.gender='W';
    worker_2.works=true;
    worker_2.salary=300000;
    worker_2.name="WorkerKsenia";
    worker_2.vacationDays[0]=60;
    worker_2.vacationDays[1]=5;
    //Worker 3
    if(!check())
    {
        QMessageBox::warning(this,"Error","You write incorrect data. Try again");
    }
    //Worker 4
    worker_4=new Worker();
    worker_4->age=22;
    worker_4->gender='M';
    worker_4->works=true;
    worker_4->salary=90400;
    worker_4->name="WorkerAnonimus";
    worker_4->vacationDays[0]=0;
    worker_4->vacationDays[1]=2;
    //Worker 5
    worker_5.age=31;
    worker_5.gender='W';
    worker_5.works=false;
    worker_5.salary=0;
    worker_5.name="WorkerAboba";
    worker_5.vacationDays[0]=24;
    worker_5.vacationDays[1]=0;
    setStructs();
}

