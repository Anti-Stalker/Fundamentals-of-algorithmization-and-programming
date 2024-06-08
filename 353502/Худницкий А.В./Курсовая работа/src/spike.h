#ifndef SPIKE_H
#define SPIKE_H

#include <QWidget>
#include "levelgenerator.h"
#include "character.h"

class Spike : public QWidget {
    Q_OBJECT
public:
    Spike(LevelGenerator *level, int x, int y, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event, Character* character);

private:
    LevelGenerator *m_level;
    int m_x;
    int m_y;
};

#endif // SPIKE_H
