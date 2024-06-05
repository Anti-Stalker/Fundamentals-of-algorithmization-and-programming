// statsbars.cpp
#include "statsbars.h"
#include <QPainter>

StatsBars::StatsBars(QWidget *parent)
    : QWidget(parent), wealth(0), power(0), intelligence(0), decency(0)
{

}

void StatsBars::updateStatsBars(int wealth, int power, int intelligence, int decency)
{
    this->wealth = wealth;
    this->power = power;
    this->intelligence = intelligence;
    this->decency = decency;
    update(); // Вызываю перерисовку виджета
}

void StatsBars::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // Устанавливаю цвет кисти и цвет пера одинаковыми
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);

    // Рисую незаполненные черные полоски
    painter.drawRect(0, 0, width(), 15);
    painter.drawRect(0, 25, width()*3, 15);
    painter.drawRect(0, 50, width()*3, 15);
    painter.drawRect(0, 75, width()*3, 15);

    // Рисую полоски статистики поверх белых полосок
    painter.setBrush(Qt::yellow);
    painter.drawRect(2, 2, wealth*(width()-4)/100, 11);
    painter.setBrush(Qt::red);
    painter.drawRect(2, 27, power*(width()-4)/100, 11);
    painter.setBrush(Qt::blue);
    painter.drawRect(2, 52, intelligence*(width()-4)/100, 11);
    painter.setBrush(Qt::green);
    painter.drawRect(2, 77, decency*(width()-4)/100, 11);
}
