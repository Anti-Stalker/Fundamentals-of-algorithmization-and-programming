#ifndef PRIZE_H
#define PRIZE_H

#include <QMap>
#include <QDebug>

class Prize
{
private:
    int points = 0;
    QMap<QString, int> prices;

public:
    Prize();

    bool addPrize(QString prize);
    void removePrize(QString prize);
    int getPoints() const;
    void setPoints(int newPoints);
    QMap<QString, bool> getCurrentPrizes() const;
};

#endif // PRIZE_H
