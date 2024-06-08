#include "deck.h"
#include "hand.h"
#include "player.h"

Player::Player(){}

Action Player::getAction(Action action)
{
    return action;
}

void Player::resetScore()
{
    score = 0;
    qDebug("score = 0");
}

void Player::resetAces()
{
    aces = 0;
}

void Player::clearHand()
{
    hand.clear();
}

void Player::resetSplitScore()
{
    scoreforsplit = 0;
}

void Player::resetSplitAces()
{
    acesforsplit = 0;
}

void Player::clearSplitHand()
{
    forsplit.clear();
}

void Player::winChips()
{
    _chips += bet;
}

void Player::loseChips()
{
    _chips -= bet;
}

void Player::blackJack()
{
    _chips += bet * 1.5;
}

void Player::placeBet(int amount)
{
    bet = amount;
}

bool Player::canSplit()
{
    if(hand.size() == 2 and hand[0].getValue() == hand[1].getValue()){
        isSpliting = true;
        return true;
    }
    return false;
}

void Player::addCard(Card card)
{
    hand.push_back(card);
    if(card.getValue() == 'J' or card.getValue() == 'Q' or card.getValue() == 'K'){
        score += 10;
    }
    else if(card.getValue() == 'A'){
        score += 11;
        aces++;
    }
    else score += card.getValue().toInt();
    while(score > 21 and aces > 0){
        score -=10;
        --aces;
    }
}

void Player::addCardToSplit(Card card)
{
    forsplit.push_back(card);
    if(card.getValue() == 'J' or card.getValue() == 'Q' or card.getValue() == 'K'){
        scoreforsplit += 10;
    }
    else if(card.getValue() == 'A'){
        scoreforsplit += 11;
        acesforsplit++;
    }
    else scoreforsplit += card.getValue().toInt();
    while(scoreforsplit > 21 and acesforsplit > 0){
        scoreforsplit -=10;
        --acesforsplit;
    }
}

int Player::getHandSize()
{
    return hand.size();
}

int Player::getSplitHandSize()
{
    return forsplit.size();
}

void Player::splitHand()
{
    scoreforsplit = score/2;
    score /= 2;
    forsplit.push_back(hand.takeLast());
}
