#ifndef VENOMANCER_H
#define VENOMANCER_H

#include "heroes/hero.h"

class Venomancer : public Hero {
public:
    Venomancer();

    void castSkill(int) override;
};

#endif // VENOMANCER_H
