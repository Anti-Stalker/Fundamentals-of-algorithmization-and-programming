#include "drowranger.h"

DrowRanger::DrowRanger()
    : Hero("Drow Ranger", "../../Resources/images/Heroes/DrowRanger/DrowRanger.gif", 500, 300, new Ability[3]{
    {"Gust", QPixmap("../../Resources/images/Heroes/DrowRanger/drow_ranger_wave_of_silence.png"), 2, 50, 30, 1},
    {"Multishot", QPixmap("../../Resources/images/Heroes/DrowRanger/drow_ranger_multishot.png"), 1, 75, 100},
    {"Marksmanship", QPixmap("../../Resources/images/Heroes/DrowRanger/drow_ranger_marksmanship.png"), 0, 100, 120}
    }) {}

void DrowRanger::castSkill(int ind) {

}
