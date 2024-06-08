#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_push_back_clicked()
{
    if (numOfQueue==1){
        queue.random(true);
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(QString::number(queue.back()));
    } else if (numOfQueue==2){
        queue2.random(true);
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(QString::number(queue2.back()));
    }
}

void MainWindow::on_push_front_clicked()
{
    if (numOfQueue==1){
    queue.random(false);
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(QString::number(queue.front()));
    } else if (numOfQueue==2){
        queue2.random(false);
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(QString::number(queue2.front()));
    }
}

void MainWindow::on_pop_back_clicked()
{
    if (numOfQueue==1){
    if(!queue.empty())
    {
        try
        {
            long long value = queue.pop_back();
            ui->plainTextEdit->clear();
            ui->plainTextEdit->setPlainText(QString::number(value));
        }
        catch (...)
        {
            QMessageBox::warning(nullptr, "Invalid Input", "The Queue is empty!");
        }
    }
    } else if (numOfQueue == 2){
        if(!queue2.empty())
        {
            try
            {
                long long value = queue2.pop_back();
                ui->plainTextEdit->clear();
                ui->plainTextEdit->setPlainText(QString::number(value));
            }
            catch (...)
            {
                QMessageBox::warning(nullptr, "Invalid Input", "The Queue is empty!");
            }
        }
    }
}

void MainWindow::on_pop_front_clicked()
{
    if (numOfQueue == 1){
    if(!queue.empty())
    {
        try
        {
            long long value = queue.pop_front();
            ui->plainTextEdit->clear();
            ui->plainTextEdit->setPlainText(QString::number(value));
        }
        catch (...)
        {
            QMessageBox::warning(nullptr, "Invalid Input", "The Queue is empty!");
        }
    }
    } else if (numOfQueue == 2){
        if(!queue2.empty())
        {
            try
            {
                long long value = queue2.pop_front();
                ui->plainTextEdit->clear();
                ui->plainTextEdit->setPlainText(QString::number(value));
            }
            catch (...)
            {
                QMessageBox::warning(nullptr, "Invalid Input", "The Queue is empty!");
            }
        }
    }
}

void MainWindow::on_front_clicked()
{
    if (numOfQueue == 1){
    if(!queue.empty())
    {
        try
        {
            long long value = queue.front();
            ui->plainTextEdit->clear();
            ui->plainTextEdit->setPlainText(QString::number(value));
        }
        catch (...)
        {
            QMessageBox::warning(nullptr, "Invalid Input", "The Queue is empty!");
        }
    }
    } else if (numOfQueue == 2){
        if(!queue2.empty())
        {
            try
            {
                long long value = queue2.front();
                ui->plainTextEdit->clear();
                ui->plainTextEdit->setPlainText(QString::number(value));
            }
            catch (...)
            {
                QMessageBox::warning(nullptr, "Invalid Input", "The Queue is empty!");
            }
        }
    }
}

void MainWindow::on_back_clicked()
{
    if (numOfQueue == 1){
    if(!queue.empty())
    {
        try
        {
            long long value = queue.back();
            ui->plainTextEdit->clear();
            ui->plainTextEdit->setPlainText(QString::number(value));
        }
        catch (...)
        {
            QMessageBox::warning(nullptr, "Invalid Input", "The Queue is empty!");
        }
    }
    } else if (numOfQueue == 2){
        if(!queue2.empty())
        {
            try
            {
                long long value = queue2.back();
                ui->plainTextEdit->clear();
                ui->plainTextEdit->setPlainText(QString::number(value));
            }
            catch (...)
            {
                QMessageBox::warning(nullptr, "Invalid Input", "The Queue is empty!");
            }
        }
    }
}

void MainWindow::on_empty_clicked()
{
    if (numOfQueue == 1){
        bool isEmpty = queue.empty();
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(QString(isEmpty ? "1 Is Empty!" : "1 Is not Empty!"));
    } else if (numOfQueue == 2){
        bool isEmpty = queue2.empty();
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(QString(isEmpty ? "2 Is Empty!" : "2 Is not Empty!"));
    }
}

void MainWindow::on_print_clicked()
{
        ui->plainTextEdit->clear();
        ui->plainTextEdit->setPlainText(queue.print() + "\n" + queue2.print());
}

void MainWindow::on_clear_clicked()
{
    if (numOfQueue == 1){
    ui->plainTextEdit->clear();
    queue.clear();
    } else if (numOfQueue == 2){
        ui->plainTextEdit->clear();
        queue2.clear();
    }
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    numOfQueue=arg1.toInt();
}

void MainWindow::on_task_clicked()
{
    try
    {
    long long minVal = queue.front();
    long long maxVal = queue.front();
    Queue<long long> tempQueue;

    while (!queue.empty()) {
        long long val = queue.pop_front();
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;
        tempQueue.push_back(val);
    }

    bool minFound = false, maxFound = false;
    while (!tempQueue.empty()) {
        long long val = tempQueue.pop_front();
        if (val == minVal && !minFound) {
            minFound = true;
            queue.push_back(val);
            while (!queue2.empty()) {
                queue.push_back(queue2.pop_front());
            }
        } else if (val == maxVal && !maxFound) {
            maxFound = true;
            queue.push_back(val);
            while (!queue2.empty()) {
                queue.push_back(queue2.pop_front());
            }
        } else {
            queue.push_back(val);
        }
    }
    MainWindow::on_print_clicked();
    }
    catch (...)
    {
        QMessageBox::warning(nullptr, "Invalid Input", "The Queue is empty!");
    }
}


