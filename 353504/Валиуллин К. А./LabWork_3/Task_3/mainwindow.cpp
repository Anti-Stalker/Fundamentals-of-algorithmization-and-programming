#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap image("/home/konstantin/QTProjects/OAIP_LABS/LAB3/TASK3/condition.png");
    ui->condition->setPixmap(image);
    ui->condition->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::extracted() {
    strNumber.clear();
    answer = 0;
}
void MainWindow::on_pushButton_clicked() {
    extracted();
    strNumber = ui->lineEditNumber->text();
    number = strNumber.toLongLong(&correct);
    if (strNumber.contains('0') || !correct) {
        QMessageBox::critical(nullptr, "Ошибка", "Неправильный ввод!");
        return;
    }
    reverse_number(number, answer);
    ui->output->setText(QString::number(answer));
}

long long MainWindow::reverse_number(long long number, long long &answer) {
    if (number == 0) {
        return answer;
    }
    int lastDigit = number % 10;
    number /= 10;
    answer = answer * 10 + lastDigit;
    return reverse_number(number, answer);
}
