#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include <QTimer>
#include "levelgenerator.h"

class Enemy : public QWidget {
    Q_OBJECT
public:
    Enemy(LevelGenerator *level, int startX, int startY);
    void startMoving();
    void stopMoving();


private slots:
    void move();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    LevelGenerator *m_level;
    int m_x;
    int m_y;
    int m_direction;
    QTimer *m_timer;

};

#endif // ENEMY_H
