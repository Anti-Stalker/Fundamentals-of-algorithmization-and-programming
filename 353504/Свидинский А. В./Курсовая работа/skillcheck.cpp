#include "skillcheck.h"
#include <QPainter>

SkillCheck::SkillCheck(QWidget *parent) : QWidget(parent), greenValue(100) {}

void SkillCheck::updateVerticalBar(int greenValue) {
    this->greenValue = greenValue;
    update();
}

void SkillCheck::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);

    painter.drawRect(0, 0, 90, height());

    // Рисую зеленую полоску
    painter.setBrush(Qt::green);
    painter.drawRect(2, 2 + (100 - greenValue)*(height()-4)/100, 86, greenValue*(height()-4)/100);
}
