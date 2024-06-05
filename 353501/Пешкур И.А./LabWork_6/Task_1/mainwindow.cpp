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

    char gender;

    if( ui->comboBoxGender->currentIndex() == 0 )
        gender = 'M';
    else
        gender = 'W';

    char w;

    if( ui->comboBoxIsWork->currentIndex() )
        w = 'Y';
    else
        w = 'N';

    std::string sal=ui->textEditSalary->toPlainText().toStdString();

    if( sal.length() == 0 )
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

    }
    catch(...)
    {
        return false;
    }

    std::string name=ui->textEditName->toPlainText().toStdString();
    if(name.size()==0)
        return false;

    std::string vD= ui->textEditVacationDays->toPlainText().toStdString();

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
    worker_3.works=w;
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

    worker_1={25,'M',false,750000,"WorkerSupperFlexer",{30, 10}};

    worker_2.age=39;
    worker_2.gender='W';
    worker_2.works=true;
    worker_2.salary=300000;
    worker_2.name="WorkerPoShvecii";
    worker_2.vacationDays[0]=60;
    worker_2.vacationDays[1]=5;

    if(!check())
    {

        QMessageBox::warning(this,"Error","Gavno.\nPeredelyvai");

    }

    worker_4=new Worker();
    worker_4->age=22;
    worker_4->gender='M';
    worker_4->works=true;
    worker_4->salary=900;
    worker_4->name="Worker9Mice";
    worker_4->vacationDays[0]=0;
    worker_4->vacationDays[1]=1;

    worker_5.age=31;
    worker_5.gender='W';
    worker_5.works=false;
    worker_5.salary=0;
    worker_5.name="WorkerMellowGanger";
    worker_5.vacationDays[0]=24;
    worker_5.vacationDays[1]=0;
    setStructs();

}

