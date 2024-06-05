#ifndef DROWRANGER_H
#define DROWRANGER_H

#include "heroes/hero.h"

class DrowRanger : public Hero {
public:
    DrowRanger();

    void castSkill(int) override;
};

#endif // DROWRANGER_H
