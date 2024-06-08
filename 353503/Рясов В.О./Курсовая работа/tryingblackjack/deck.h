#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <QImage>
#include<QRandomGenerator>
#include<QString>
#include<QVector>

class Deck
{
public:
    Deck(int _num_decks);

    void shuffle();

    Card takeCardFromDeck();
    QImage takeCardImageFromDeck();

    void setNumDecks(int num);

    QVector<Card> _cards;
    QVector<QImage> _images;
private:
    int _num_decks;
};

#endif // DECK_H
