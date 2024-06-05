#pragma once

#include "basePowerup.h"
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qpixmap.h>
#include <qtmetamacros.h>

class PowerupInvisible : public Powerup {
public:
    PowerupInvisible(int size, QGraphicsScene *scene, int x, int y);

    void use() override;

private slots:

    void unuse();
};