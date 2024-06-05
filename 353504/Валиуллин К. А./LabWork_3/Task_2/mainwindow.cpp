#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap image("/home/konstantin/QTProjects/OAIP_LABS/LAB3/TASK2/condition.png");
    ui->label_2->setPixmap(image);
    ui->label_2->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    strM = ui->lineEditM->text();
    strN = ui->lineEditN->text();
    m = strM.toLongLong(&correctM);
    n = strN.toLongLong(&correctN);
    if (!correctM && !correctN) {
        QMessageBox::critical(nullptr, "Ошибка", "Вы ввели неправильно оба числа!");
    }
    else if (!correctM) {
        QMessageBox::critical(nullptr, "Ошибка", "Неправильный ввод числа m!");
        return;
    }
    else if (!correctN) {
        QMessageBox::critical(nullptr, "Ошибка", "Неправильный ввод числа n!");
        return;
    }
    else if ((m == 5 && n > 0) || (m == 4 && n > 1) || m > 5 || (m == 3 && n > 13)
               || n > 10000) {
        QMessageBox::critical(nullptr, "Ошибка", "Результат выполнения слишком велик или слишком "
"долог и не может быть отображен...");
        return;
    }
    answer = akkerman(m, n);
    strAnswer = QString::number(answer);
    ui->output->setText(strAnswer);
}

int MainWindow::akkerman(int m, int n)
{
    if (m == 0) {
        return n + 1;
    }
    else if (m > 0 && n == 0) {
        return akkerman(m - 1, 1);
    }
    else if (m > 0 && n > 0) {
        return akkerman(m - 1, akkerman(m, n - 1));
    }
}
