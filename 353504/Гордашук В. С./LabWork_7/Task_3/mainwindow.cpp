#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 5; ++i)
    {
        MyStack *stack = new MyStack();
        QString s;
        for (int i = 0; i < 10; ++i)
        {
            stack->push(QRandomGenerator::global()->bounded(100));
            s += QString::number(stack->back());
            if (i != 9) s += " | ";
        }
        hashTable->insert(stack);
        ui->listWidget->insertItem(i, s);
    }
    ui->label->setText("Наименьший ключ - " + QString::number(hashTable->getMinIndex()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MyStack *stack = new MyStack();
    QString s;
    for (int i = 0; i < 10; ++i)
    {
        stack->push(QRandomGenerator::global()->bounded(100));
        s += QString::number(stack->back());
        if (i != 9) s += " | ";
    }
    hashTable->insert(stack);
    ui->listWidget->insertItem(ui->listWidget->count(), s);
    ui->label->setText("Наименьший ключ - " + QString::number(hashTable->getMinIndex()));
}


void MainWindow::on_pushButton_2_clicked()
{
    int index = ui->listWidget->currentRow();
    int sum = 0;
    QString s = ui->listWidget->currentItem()->text();
    QStringList numbers = s.split(" | ");
    for (const QString &number : numbers)
    {
        sum += number.toInt();
    }
    hashTable->remove(sum % 100);
    ui->listWidget->takeItem(index);
    hashTable->getMinIndex();
    ui->label->setText("Наименьший ключ - " + QString::number(hashTable->getMinIndex()));
}

