#include "clickergame.h"
#include <QPainter>

ClickerGame::ClickerGame(QWidget *parent)
    : QWidget(parent), greenValue(0), redValue(0)
{

}

void ClickerGame::updateVerticalBars(int greenValue, int redValue)
{
    this->greenValue = greenValue;
    this->redValue = redValue;
    update(); // Вызывает перерисовку виджета
}

void ClickerGame::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);

    // Рисую черные полоски
    painter.drawRect(0, 0, 90, height());
    painter.drawRect(0, 0, 90, height());

    // Рисую зеленую полоску
    painter.setBrush(Qt::green);
    painter.drawRect(2, 2 + (100 - greenValue)*(height()-4)/100, 86, greenValue*(height()-4)/100);

    // Рисую красную полоску
    painter.setBrush(Qt::red);
    painter.drawRect(2, 2 + (100 - redValue)*(height()-4)/100, 86, redValue*(height()-4)/100);
}


