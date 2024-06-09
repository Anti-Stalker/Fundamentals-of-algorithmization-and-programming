#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file1 = new QFile("../file1.txt");
    file2 = new QFile("../file2.txt");
    file3 = new QFile("../file3.txt");
    file4 = new QFile("../file4.bin");
    file5 = new QFile("../file5.txt");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex() == 0)
    {
        ui->textBrowser->clear();
        if (file1->open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(file1);
            QString in = ui->textEdit->toPlainText();
            for(QChar c : in)
            {
                stream<<c;
            }
            file1->close();
        }

        if (file1->open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(file1);
            QString text = stream.readAll();
            for(QChar c : text)
            {
                ui->textBrowser->insertPlainText(c);
            }
            file1->close();
        }
    }
    else if(ui->comboBox->currentIndex() == 1)
    {
        ui->textBrowser->clear();
        if (file2->open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(file2);
            QString text = ui->textEdit->toPlainText();
            QTextStream str(&text);
            char v;
            for(int i = 0; i < ui->spinBox->value(); i++)
            {
                str >> v;
                stream << v;
                if (i < ui->spinBox->value() - 1)
                    stream << "~";
            }
            file2->close();
        }

        if (file2->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(file2);
            QString text = stream.readAll();
            text.replace("~", " ");
            ui->textBrowser->setText(text);
            file2->close();
        }
    }
    else if(ui->comboBox->currentIndex() == 2)
    {
        ui->textBrowser->clear();
        if (file3->open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(file3);
            QString in = ui->textEdit->toPlainText();
            stream << in;
            stream <<'\n';
            file3->close();
        }

        if (file3->open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(file3);
            QString text = stream.readAll();
            for(QChar c : text)
            {
                ui->textBrowser->insertPlainText(c);
            }
            file3->close();
        }
    }
    else if(ui->comboBox->currentIndex() == 3)
    {
        ui->textBrowser->clear();


        QFile file4("../file5.bin");
        if (file4.open(QIODevice::Append))
        {
            file4.write(reinterpret_cast<const char*>(&zver), sizeof(Animal));
            file4.close();
        }
        else
        {

            return;
        }

        if (file4.open(QIODevice::ReadOnly))
        {
            Animal second;
            while (file4.read(reinterpret_cast<char*>(&second), sizeof(Animal)))
            {
                QString secondStr = QString("%1 | %2 | %3 | %4 | %5 | [ ").arg(
                    QString::number(second.age),
                    QString::number(second.weight),
                    QString(second.type),
                    QString::number(second.wasFeedToday),
                    QString(second.aClass));

                for (int i = 0; i < second.daysInWeek; i++)
                {
                    secondStr += QString::number(second.foodPerDay[i]) + " ";
                }

                secondStr += "]";
                ui->textBrowser->append(secondStr);
            }

            file4.close();
        }
        else
        {

            return;
        }
    }
    else if(ui->comboBox->currentIndex() == 4)
    {
        ui->textBrowser->clear();

        file5->open(QFile::Append);
        {
            QTextStream stream(file5);
            stream << ui->textEdit->toPlainText() << "\n";
        }
        file5->close();

        file5->open(QFile::ReadOnly);

        QList<QString> lines;

        QTextStream stream(file5);
        while (!stream.atEnd()) {
            lines.push_back(stream.readLine());
        }
        file5->close();


        for (int i = 0; i < lines.count(); i++) {
            ui->textBrowser->append(lines[i]);
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    input* sInput = new input();
    connect(sInput, SIGNAL(enter(QString, Animal)), this, SLOT(getNewA(QString, Animal)));
    sInput->show();

}

void MainWindow::getNewA(QString b, Animal a)
{
    newA = b;


    zver.age = a.age;
    zver.weight = a.weight;
    std::copy(a.type, a.type + Animal::nameLength, zver.type);
    std::copy(a.foodPerDay, a.foodPerDay + Animal::daysInWeek, zver.foodPerDay);
    zver.wasFeedToday = a.wasFeedToday;
    zver.aClass = a.aClass;

    ui->textEdit->setText(newA);
}

