#include "venomancer.h"

Venomancer::Venomancer()
    : Hero("Venomancer", "../../Resources/images/Heroes/Venomancer/Venomancer.gif", 500, 300, new Ability[3]{
    {"Venomous Gale", QPixmap("../../Resources/images/Heroes/Venomancer/venomancer_venomous_gale.png"), 1, 50, 80, 0, 0, 10, 2},
    {"Poison Sting", QPixmap("../../Resources/images/Heroes/Venomancer/venomancer_poison_sting.png"), 0, 15, 20, 0, 0, 5, 4},
    {"Noxious Plague", QPixmap("../../Resources/images/Heroes/Venomancer/venomancer_noxious_plague.png"), 4, 150, 175, 0, 0, 25, 2}
    }) {}

void Venomancer::castSkill(int ind) {

}
