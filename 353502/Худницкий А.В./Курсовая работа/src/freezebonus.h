#ifndef FREEZEBONUS_H
#define FREEZEBONUS_H

#include <QWidget>
#include "enemy.h"
#include "levelgenerator.h"

class FreezeBonus : public QWidget {
    Q_OBJECT
public:
    FreezeBonus(LevelGenerator *level, int x, int y, QWidget *parent = nullptr);

signals:
    void enemiesFrozen();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event);

private:
    LevelGenerator *m_level;
    int m_x;
    int m_y;
};

#endif // FREEZEBONUS_H
