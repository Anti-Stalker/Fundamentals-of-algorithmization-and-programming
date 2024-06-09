#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Error Box
    ErrorBox.setWindowTitle("Error");
    ErrorBox.setText("You are doing something wrong");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Function to check if string is relevant
bool MainWindow::CheckString(QString& str)
{
    // Remove - if it exist
    if(str.at(0) == '-'){
        str.remove('-');
    }

    //Check all to be digits
    for(auto &i : str){
        if(!i.isDigit()){
            return false;
        }
    }
    return true;
}

QString MainWindow::ConvertToBin(const QString num)
{
    QString answer = "";
    QString str;

    answer += str.setNum(num.toInt() % 2);

    if(num.toInt() / 2 != 0){
        QString new_num;
        new_num.setNum(num.toInt() / 2);

        return answer + ConvertToBin(new_num);
    }

    return answer;
}

void MainWindow::RedirectString(QString& str)
{
    for(size_t i = 0; i < str.size() / 2; ++i){
        std::swap(str[i], str[str.size() - i - 1]);
    }
}

void MainWindow::on_pushButton_clicked()
{
    //Clear perinvious result
    ui->LineSet->clear();

    //Get string from ui
    QString str = ui->LineGet->text();
    if(!CheckString(str)){
        ErrorBox.exec();

        return;
    }

    //Converting str to bin
    QString answer = ConvertToBin(str);

    //Swap element as they ware got vise versa
    RedirectString(answer);

    //Set answer in the line on ui
    ui->LineSet->setText(answer);
}



