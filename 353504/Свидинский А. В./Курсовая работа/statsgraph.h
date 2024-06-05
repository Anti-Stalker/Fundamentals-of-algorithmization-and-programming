#ifndef STATSGRAPH_H
#define STATSGRAPH_H

#include <QWidget>
#include <QVector>

class StatsGraph : public QWidget
{
    Q_OBJECT
public:
    StatsGraph(QWidget *parent = nullptr);
    void clearStatsHistory();
    void updateStatsGraph(int wealth, int power, int intelligence, int decency);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QVector<int> wealthHistory;
    QVector<int> powerHistory;
    QVector<int> intelligenceHistory;
    QVector<int> decencyHistory;
};

#endif // STATSGRAPH_H
