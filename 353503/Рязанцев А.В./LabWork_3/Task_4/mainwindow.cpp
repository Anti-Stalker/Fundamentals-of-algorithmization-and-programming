#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup Error menu
    ErrorBox.setWindowTitle("Error");
    ErrorBox.setText("Error occured");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Check string to contain only digits
bool MainWindow::CheckString(const QString str)
{
    for(auto &elem : str){
        if(!elem.isDigit()){
            return false;
        }
    }

    return true;
}

void MainWindow::hanoi(int n, char from_rod, char to_rod, char help_rod, QString& output)
{
    //Create string with meaning of disk number
    QString num;
    num.setNum(n);

    if (n == 1){
        output += "Move disk " + num + " from rod " + from_rod + " to rod " + to_rod + "\n";
        return;
    }

    hanoi(n - 1, from_rod, help_rod, to_rod, output);
    output += "Move disk " + num + " from rod " + from_rod + " to rod " + to_rod + "\n";
    hanoi(n - 1, help_rod, to_rod, from_rod, output);
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clearHistory();
    output = "";

    //Check string to be number
    if(!CheckString(ui->EditGet->text())){
        //Dispay error window
        ErrorBox.exec();

        //delete wrong input
        ui->EditGet->setText("");

        return;
    }

    //Get number of rings;
    int n = ui->EditGet->text().toInt();

    //Call main function
    hanoi(n, 'A', 'C', 'B', output);

    //Display info on ui
    ui->textBrowser->setText(output);
}


