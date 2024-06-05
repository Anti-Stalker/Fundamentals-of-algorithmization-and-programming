#ifndef DRAGONKNIGHT_H
#define DRAGONKNIGHT_H

#include "heroes/hero.h"

class DragonKnight : public Hero {
public:
    DragonKnight();

    void castSkill(int) override;
};

#endif // DRAGONKNIGHT_H
