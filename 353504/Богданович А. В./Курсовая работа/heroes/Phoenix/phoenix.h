#ifndef PHOENIX_H
#define PHOENIX_H

#include "heroes/hero.h"

class Phoenix : public Hero {
public:
    Phoenix();

    void castSkill(int) override;
};

#endif // PHOENIX_H
