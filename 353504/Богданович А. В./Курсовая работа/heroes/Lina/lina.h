#ifndef LINA_H
#define LINA_H

#include "heroes/hero.h"

class Lina : public Hero {
public:
    Lina();

    void castSkill(int) override;
};

#endif // LINA_H
