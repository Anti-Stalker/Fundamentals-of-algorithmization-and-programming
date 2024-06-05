#include "statsgraph.h"
#include <QPainter>

StatsGraph::StatsGraph(QWidget *parent)
    : QWidget(parent)
{

}

void StatsGraph::updateStatsGraph(int wealth, int power, int intelligence, int decency)
{
    wealthHistory.append(wealth);
    powerHistory.append(power);
    intelligenceHistory.append(intelligence);
    decencyHistory.append(decency);
    update(); // Вызываю перерисовку виджета
}

void StatsGraph::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPen pen;

    // Устанавливаю толщину линий
    pen.setWidth(3);

    // Рисую графики статистики
    pen.setColor(Qt::yellow);
    painter.setPen(pen);
    for (int i = 1; i < wealthHistory.size(); ++i) {
        painter.drawLine((i-1)*width()/60, height() - wealthHistory[i-1]*height()/100, i*width()/60, height() - wealthHistory[i]*height()/100);
    }
    pen.setColor(Qt::red);
    painter.setPen(pen);
    for (int i = 1; i < powerHistory.size(); ++i) {
        painter.drawLine((i-1)*width()/60, height() - powerHistory[i-1]*height()/100, i*width()/60, height() - powerHistory[i]*height()/100);
    }
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    for (int i = 1; i < intelligenceHistory.size(); ++i) {
        painter.drawLine((i-1)*width()/60, height() - intelligenceHistory[i-1]*height()/100, i*width()/60, height() - intelligenceHistory[i]*height()/100);
    }
    pen.setColor(Qt::green);
    painter.setPen(pen);
    for (int i = 1; i < decencyHistory.size(); ++i) {
        painter.drawLine((i-1)*width()/60, height() - decencyHistory[i-1]*height()/100, i*width()/60, height() - decencyHistory[i]*height()/100);
    }
}

void StatsGraph::clearStatsHistory()
{
    wealthHistory.clear();
    powerHistory.clear();
    intelligenceHistory.clear();
    decencyHistory.clear();
}

