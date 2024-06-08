//
// Created by u on 27.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"


void main_window::at()
{
    ui->mini->setText(QString::number(v.at(ui->atspinbox->value())));
}

void main_window::begin()
{
    ui->mini->setText(QString::number(*v.begin()));
}

void main_window::capacity()
{
    ui->mini->setText(QString::number(v.capacity()));
}

void main_window::clear()
{
    v.clear();
}

void main_window::empty()
{
    ui->mini->setText(QString::number(v.empty()));
}

void main_window::end()
{
    ui->mini->setText(QString::number(*v.end()));
}

void main_window::erase()
{
    v.erase(ui->erasespinbox->value());
}

void main_window::pop_back()
{
    v.pop_back();
}

void main_window::push_back()
{
    v.push_back(ui->push_backspinbox->value());
}

void main_window::resize()
{
    v.resize(ui->resizespinbox->value());
}

void main_window::size()
{
    ui->mini->setText(QString::number(v.size()));
}

void main_window::updateWindow()
{
    QString s = "";
    for (auto u : v)
    {
        s += QString::number(u) + " ";
    }

    ui->showtext->setText(s);

    QWidget::update();
}

main_window::main_window(QWidget *parent) :
        QWidget(parent), ui(new Ui::main_window)
{
    ui->setupUi(this);

    connect(ui->atbutton, SIGNAL(pressed()), this, SLOT(at()));
    connect(ui->beginbutton, SIGNAL(pressed()), this, SLOT(begin()));
    connect(ui->capacitybutton, SIGNAL(pressed()), this, SLOT(capacity()));
    connect(ui->clearbutton, SIGNAL(pressed()), this, SLOT(clear()));
    connect(ui->emptybutton, SIGNAL(pressed()), this, SLOT(empty()));
    connect(ui->endbutton, SIGNAL(pressed()), this, SLOT(end()));
    connect(ui->erasebutton, SIGNAL(pressed()), this, SLOT(erase()));
    connect(ui->pop_backbutton, SIGNAL(pressed()), this, SLOT(pop_back()));
    connect(ui->push_backbutton, SIGNAL(pressed()), this, SLOT(push_back()));
    connect(ui->resizebutton, SIGNAL(pressed()), this, SLOT(resize()));
    connect(ui->sizebutton, SIGNAL(pressed()), this, SLOT(size()));

    auto *timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWindow()));
    timer->start();
}

main_window::~main_window() {
    delete ui;
}
