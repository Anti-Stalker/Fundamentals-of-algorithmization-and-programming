#include "hand.h"
#include "deck.h"
#include "card.h"

Hand::Hand()
{

}

void Hand::getCardToHand()
{
    QString infoCard = Deck::deck->takeCardFromDeck();
    Card *card = new Card(infoCard);
    int a = card->getValue().toInt();
    Hand::_total_value += a;
    if(_total_value > 21){
        qDebug("lox");
        Hand::handsOfPlayers.clear();
        Hand::valueOfCards.clear();
        Hand::_total_value = 0;
        Hand::isMoveEnded = true;
    }
    valueOfCards.push_back(card->getValue().toInt());
}

void Hand::compareHands(Hand dealerHand, Hand playerHand)
{
    if(dealerHand._total_value > playerHand._total_value){

    }

    else if(dealerHand._total_value < playerHand._total_value){

    }

    else {

    }
}

bool Hand::isMoveEnded = false;
std::vector<int> Hand::valueOfCards;
std::vector<Hand> Hand::handsOfPlayers;
int Hand::_total_value = 0;
