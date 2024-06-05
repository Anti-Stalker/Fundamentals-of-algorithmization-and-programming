#include "basePowerup.h"

#include "powerupInvisible.h"
#include "powerupTeleport.h"
#include <qpixmap.h>

QPixmap *Powerup::imageTeleport;
QPixmap *Powerup::imageInvisibility;

Powerup *Powerup::newInstance(int size, QGraphicsScene *scene, int x, int y, Type type) {
        switch (type) {
        case Teleport:
            return new PowerupTeleport(size, scene, x, y);
        case Invisible:
            return new PowerupInvisible(size, scene, x, y);
        default:
            return nullptr;
    }
}

Powerup *Powerup::pickUp() {
    if (taken)
        return nullptr;

    pos_x = -1;
    pos_y = -1;
    
    taken = true;
    body->setVisible(false);

    return this;
};