#ifndef COINBONUS_H
#define COINBONUS_H

#include <QWidget>
#include "enemy.h"
#include "levelgenerator.h"
#include "character.h"

class CoinBonus : public QWidget {
    Q_OBJECT
public:
    CoinBonus(LevelGenerator *level, int x, int y, QWidget *parent = nullptr);

signals:
    void multiply(int factor);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event, Character* character);

private:
    LevelGenerator *m_level;
    int m_x;
    int m_y;
};

#endif // COINBONUS_H
