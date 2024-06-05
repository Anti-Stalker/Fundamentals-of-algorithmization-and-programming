#include "dragonknight.h"

DragonKnight::DragonKnight()
    : Hero("Dragon Knight", "../../Resources/images/Heroes/DragonKnight/DragonKnight.gif", 500, 300, new Ability[3]{
    {"Breathe Fire", QPixmap("../../Resources/images/Heroes/DragonKnight/dragon_knight_breathe_fire.png"), 0, 50, 70},
    {"Dragon Tail", QPixmap("../../Resources/images/Heroes/DragonKnight/dragon_knight_dragon_tail.png"), 2, 50, 50, 0, 1},
    {"Elder Dragon Form", QPixmap("../../Resources/images/Heroes/DragonKnight/dragon_knight_elder_dragon_form.png"), 2, 150, 75, 0, 0, 25, 3}
    }) {}

void DragonKnight::castSkill(int ind) {

}
