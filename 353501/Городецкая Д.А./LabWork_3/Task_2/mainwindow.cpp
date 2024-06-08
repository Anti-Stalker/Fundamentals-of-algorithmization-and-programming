#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Введите m:", this);
    layout->addWidget(label);


    input1LineEdit = new QLineEdit(this);
    layout->addWidget(input1LineEdit);

    QLabel *label_2 = new QLabel("Введите n:", this);
    layout->addWidget(label_2);

    input2LineEdit = new QLineEdit(this);
    layout->addWidget(input2LineEdit);

    QPushButton *pushButton = new QPushButton("Преобразовать", this);
    layout->addWidget(pushButton);

    resultLabel = new QLabel("Ответ: ",this);
    layout->addWidget(resultLabel);

    connect(pushButton, &QPushButton::clicked, this, &MainWindow::answer);

    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::answer()
{
    int m = input1LineEdit->text().toInt();
    int n = input2LineEdit->text().toInt();


    if (m > 3)
    {
        QMessageBox::warning(this, "Ошибка", "Значение m должно быть не больше 3");
        return;
    }

    if (n > 9)
    {
        QMessageBox::warning(this, "Ошибка", "Значение n должно быть не больше 9");
        return;
    }
    int result = ackermann(m, n);

    resultLabel->setText("Ответ: " + QString::number(result));
}
int MainWindow::ackermann(int m, int n){
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0)
    {
        return ackermann(m - 1, 1);
    }
    else
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

