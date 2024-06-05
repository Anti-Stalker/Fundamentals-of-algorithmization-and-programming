#include "AnimatedRect.h"

AnimatedRect::AnimatedRect(QWidget *parent) : QWidget(parent)
{
    setFixedSize(30, 100);
}

AnimatedRect::~AnimatedRect() {}

void AnimatedRect::paintEvent(QPaintEvent *event)
{
    if (isPaint) {
        QPainter painter(this);
        painter.setBrush(Qt::blue);
        painter.drawRect(rect());
    }
}

void AnimatedRect::stopPaint() {
    isPaint = false;
}
