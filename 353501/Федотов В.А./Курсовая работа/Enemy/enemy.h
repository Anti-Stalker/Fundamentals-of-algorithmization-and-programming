#pragma once

#include <QGraphicsScene>
#include <QTimer>
#include <qpixmap.h>

enum EnemyModes { Idle, Triggered, Tired };

class Enemy : public QObject {
    Q_OBJECT
public:
    Enemy(double size, QGraphicsScene *scene, int x, int y);
    ~Enemy();

    void setEnemyPos(int x, int y);
    void setTriggered();
    EnemyModes getMode() { return mode; }
    int get_x();
    int get_y();

    static QPixmap *image;

private slots:
    void move();
    void moveToPlayer();
    void setTired();
    void setIdle();

signals:
    void moveEnemy(Enemy *enemy);
    void moveEnemyToPlayer(Enemy *enemy);

private:
    QTimer *idleTimer;
    QTimer *chaseTimer;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *body;

    int pos_x;
    int pos_y;

    EnemyModes mode;

    double size;
};