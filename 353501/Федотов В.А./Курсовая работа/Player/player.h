#pragma once

#include "../Powerup/basePowerup.h"

#include <QGraphicsItem>
#include <qcontainerfwd.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qtmetamacros.h>

class Powerup;

class Player : public QObject {
    Q_OBJECT
public:
    Player(double size, QGraphicsScene *scene);
    ~Player();

    void setPlayerPos(int x, int y);
    int get_x();
    int get_y();

    void addPowerup(Powerup *powerup);
    void usePowerup(int index);

    bool isInvisible() { return invisible; }

    static QPixmap *defaultFace;
    static QPixmap *invisibleFace;
    static Player* getInstance( ) { return instance; }

public slots:
    void setInvisible(bool);
    
private:
    bool invisible = false;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *body;

    QVector<Powerup*> powerups;

    static Player *instance;

    int pos_x;
    int pos_y;

    double size;

signals:
    void powerupAdded(Powerup *powerup);
    void powerupUsed(int index);

    void playerMoved(QPointF offset);
};