#include "mainwindow.h"
#include "./ui_mainwindow.h"

const int LOWLIMIT = 14;
const int UPLIMIT = 20000;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setting Error menu
    ErrorBox.setText("Some issue occured");
    ErrorBox.setWindowTitle("Error");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Checking validity of inputed numbers
bool MainWindow::CheckNumber(const QString n)
{
    for(auto &element : n){
        if(!element.isDigit()){
            return false;
        }
    }

    return true;
}

bool MainWindow::CheckForCorrectness(const int n, const int m)
{
    if(m == 1){
        return true;
    }
    if(m >= 4){
        return false;
    }
    if(n >= LOWLIMIT && m == 3){
        return false;
    }
    if(n >= UPLIMIT && m == 2){
        return false;
    }

    return true;
}

// main Function
int MainWindow::AkermanFunc(const int m, const int n)
{
    if(m == 0){
        return n + 1;
    }
    if(n == 0){
        return AkermanFunc(m - 1, 1);
    }
    else{
        return AkermanFunc(m - 1, AkermanFunc(m, n - 1));
    }
}

void MainWindow::on_pushButton_clicked()
{
    //Check inputed string
    if(!CheckNumber(ui->lineGet->text()) || !CheckNumber(ui->lineGet_2->text())){
        ErrorBox.exec();

        return;
    }

    // getting info as numbers
    int n = ui->lineGet->text().toUInt();
    int m = ui->lineGet_2->text().toUInt();

    //Ensure numbers are small
    if(!CheckForCorrectness(n, m)){
        ErrorBox.exec();

        return;
    }

    //Call main function
    QString answer;
    answer.setNum(AkermanFunc(m,n));

    //Displaying answer in ui line
    ui->lineSet->setText(answer);
}



