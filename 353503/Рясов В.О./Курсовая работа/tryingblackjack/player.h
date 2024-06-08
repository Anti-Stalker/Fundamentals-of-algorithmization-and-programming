#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"

enum Action {
    HIT,
    STAND,
    DOUBLE,
    SPLIT
};

class Player
{
public:
    Player();
    Action getAction(Action action);
    QString getName() { return name; }
    int getScore() { return score; }
    int getSplitScore() { return scoreforsplit; }
    void addScore(int value) { score += value; }
    int getBet() { return bet; }
    int getChips() { return _chips; }
    bool getSpliting() { return isSpliting; }
    void resetScore();
    void resetAces();
    void clearHand();
    void resetSplitScore();
    void resetSplitAces();
    void clearSplitHand();
    void winChips();
    void loseChips();
    void blackJack();
    void placeBet(int amount);
    void doubleBet() { bet *= 2; } // Удвоение ставки
    bool canSplit(); // Проверка на возможность разделения
    void addCard(Card card);
    void addCardToSplit(Card card);
    int getHandSize();
    int getSplitHandSize();
    void splitHand();
private:
    QString name;
    int score{0};
    int aces{0};
    int scoreforsplit{0};
    int acesforsplit{0};
    bool isSpliting{false};
    QVector<Card> hand;
    QVector<Card> forsplit;
    int bet;
    int _chips = 50000;
};

#endif // PLAYER_H
