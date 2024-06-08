#ifndef COIN_H
#define COIN_H

#include <QWidget>
#include "levelgenerator.h"
#include "character.h"

class Coin : public QWidget {
    Q_OBJECT
public:
    Coin(LevelGenerator *level, int x, int y, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void coinsChanged(int count);

private:
    LevelGenerator *m_level;
    int m_x;
    int m_y;
};

#endif // COIN_H
