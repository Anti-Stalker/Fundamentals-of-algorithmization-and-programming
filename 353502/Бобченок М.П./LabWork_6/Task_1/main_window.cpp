//
// Created by u on 30.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"


void main_window::set()
{
    a.footSize = ui->footStep->text().toInt();
    a.height = ui->height->text().toInt();
    a.eyeColor = ui->eyeColor->text().toStdString()[0];
    a.isFast = ui->isFast->text().toInt();

    QString txt = ui->footStep->text() + "|" + ui->height->text() + "|" +
                  ui->eyeColor->text() + "|" + ui->isFast->text();
    ui->text->setText(txt);
}

void main_window::setFromConsole()
{
    ui->text->setText("footStep: ");
    curQ = 0;
}

void main_window::answer()
{
    if (curQ == 0)
    {
        QString txt = ui->inanswer->text();

        a.footSize = 0;
        for (int i = 0; i < std::min(2, txt.size()); i++)
        {
            if (txt[i] < '0' || txt[i] > '9')
                break;

            a.footSize = a.footSize * 10 + txt.midRef(i, 1).toInt();
        }

        ui->text->setText("height: ");
        curQ++;
    }
    else if (curQ == 1)
    {
        QString txt = ui->inanswer->text();

        a.height = 0;
        for (int i = 0; i < std::min(3, txt.size()); i++)
        {
            if (txt[i] < '0' || txt[i] > '9')
                break;

            a.height = a.height * 10 + txt.midRef(i, 1).toInt();
        }

        ui->text->setText("eyeColor: ");
        curQ++;
    }
    else if (curQ == 2)
    {
        QString txt = ui->inanswer->text();

        a.eyeColor = ' ';
        for (int i = 0; i < std::min(1, txt.size()); i++)
        {
            if (txt[i] < 'a' || txt[i] > 'z')
                break;

            a.eyeColor = txt.mid(i, 1).toStdString()[0];
        }

        ui->text->setText("isFast: ");
        curQ++;
    }
    else if (curQ == 3)
    {
        QString txt = ui->inanswer->text();

        a.isFast = false;
        for (int i = 8; i < std::min(1, txt.size()); i++)
        {
            if (txt[i] < '0' || txt[i] > '1')
                break;

            a.isFast = txt.midRef(i, 1).toInt();
        }

        txt = QString::number(a.footSize) + "|" + QString::number(a.height) + "|" +
              QString(a.eyeColor) + "|" + QString::number(a.isFast);
        ui->text->setText(txt);
        curQ++;
    }

}

void main_window::setByPtr()
{
    athlete *t = new athlete();

    t->footSize = ui->footStep->text().toInt();
    t->height = ui->height->text().toInt();
    t->eyeColor = ui->eyeColor->text().toStdString()[0];
    t->isFast = ui->isFast->text().toInt();

    QString txt = QString::number(t->footSize) + "|" + QString::number(t->height) + "|" +
                  QString(t->eyeColor) + "|" + QString::number(t->isFast);
    ui->text->setText(txt);
}

void main_window::setByLink()
{
    athlete &t = a;

    t.footSize = ui->footStep->text().toInt();
    t.height = ui->height->text().toInt();
    t.eyeColor = ui->eyeColor->text().toStdString()[0];
    t.isFast = ui->isFast->text().toInt();

    QString txt = QString::number(t.footSize) + "|" + QString::number(t.height) + "|" +
                  QString(t.eyeColor) + "|" + QString::number(t.isFast);
    ui->text->setText(txt);
}

main_window::main_window(QWidget *parent) :
        QWidget(parent), ui(new Ui::main_window)
{
    ui->setupUi(this);

    connect(ui->set, SIGNAL(clicked(bool)), this, SLOT(set()));
    connect(ui->setFromConsole, SIGNAL(clicked(bool)), this, SLOT(setFromConsole()));
    connect(ui->answer, SIGNAL(clicked(bool)), this, SLOT(answer()));
    connect(ui->setByPtr, SIGNAL(clicked(bool)), this, SLOT(setByPtr()));
    connect(ui->setByLink, SIGNAL(clicked(bool)), this, SLOT(setByLink()));
}

main_window::~main_window() {
    delete ui;
}
