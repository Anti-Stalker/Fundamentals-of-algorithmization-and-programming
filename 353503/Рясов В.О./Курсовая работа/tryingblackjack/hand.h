#ifndef HAND_H
#define HAND_H
#include "deck.h"

class Hand
{
public:
    Hand();
    void getCardToHand();
    void compareHands(Hand dealerHand, Hand playerHand);
    static std::vector<Hand> handsOfPlayers;
    static std::vector<int> valueOfCards;
    static bool isMoveEnded;
    static int _total_value;
};

#endif // HAND_H
