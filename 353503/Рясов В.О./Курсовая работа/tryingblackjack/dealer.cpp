#include "dealer.h"

Dealer::Dealer(Difficulty _difficulty){}

void Dealer::setDifficulty(Difficulty newDiff)
{
    _difficulty = newDiff;
}

void Dealer::chooseTactic(Difficulty &_difficulty)
{
    if(_difficulty == EASY){
        //easyBasicStrategy();
    }

    else if(_difficulty == MEDIUM){
        //basicStrategy();
    }

    else{
        //hi_loStrategy();
    }
}
