#include "mainwindow.h"
#include "./ui_mainwindow.h"

const unsigned int TEN = 10;
const unsigned int NINE = 9;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup error message
    ErrorBox.setWindowTitle("Error");
    ErrorBox.setText("Some error occured");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Check string to be number without zeros
bool MainWindow::CheckString(const QString string)
{
    if(string.size() >= NINE){
        return false;
    }

    for(auto &element : string){
        if(!element.isDigit() || element == '0'){
            return false;
        }
    }

    return true;
}

// Main Func
unsigned int MainWindow::Recurs(unsigned int num, unsigned int remainder)
{
    if(num < TEN){
        return remainder * TEN + num;
    }
    return Recurs(num / TEN, remainder * TEN + num % TEN);
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineSet->clear();

    if(!CheckString(ui->lineGet->text())){
        //call Error
        ErrorBox.exec();

        return;
    }

    //Get number from line
    unsigned int number = ui->lineGet->text().toUInt();

    //Call function
    unsigned int answer = Recurs(number, 0);

    //Creating string containg number
    QString answ;
    answ.setNum(answer);

    //Dispalying result
    ui->lineSet->setText(answ);
}



