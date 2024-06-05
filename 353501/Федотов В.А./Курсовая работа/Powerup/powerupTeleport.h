#pragma once

#include "basePowerup.h"
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qpixmap.h>

class PowerupTeleport : public Powerup {
public:
    PowerupTeleport(int size, QGraphicsScene *scene, int x, int y);

    void use() override;
};