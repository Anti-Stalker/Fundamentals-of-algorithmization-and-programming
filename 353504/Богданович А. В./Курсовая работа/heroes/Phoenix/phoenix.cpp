#include "phoenix.h"

Phoenix::Phoenix()
    : Hero("Phoenix", "../../Resources/images/Heroes/Phoenix/Phoenix.gif", 500, 300, new Ability[3]{
    {"Icarus Dive", QPixmap("../../Resources/images/Heroes/Phoenix/phoenix_icarus_dive.png"), 0, 20, 40},
    {"Fire Spirits", QPixmap("../../Resources/images/Heroes/Phoenix/phoenix_fire_spirits.png"), 3, 80, 50, 0, 0, 10, 3},
    {"Supernova", QPixmap("../../Resources/images/Heroes/Phoenix/phoenix_supernova.png"), 4, 200, 150, 0, 1, 15, 2}
    }) {}

void Phoenix::castSkill(int ind) {

}
