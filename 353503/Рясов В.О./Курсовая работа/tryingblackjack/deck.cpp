#include "deck.h"

Deck::Deck(int _num_decks) {
    for (int i = 0; i < _num_decks; ++i) {
        for (const QString &suit : {"C", "D", "H", "S"}) {
            for (const QString &rank : {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}) {
                _cards.append(Card(suit, rank));
                _images.append(QImage("/home/vlad/tryingblackjack/cards/" + suit+rank + ".png"));
            }
        }
    }
}

void Deck::setNumDecks(int num)
{
    _num_decks = num;
}

void Deck::shuffle() {
    const int n = _cards.size();
    for (int i = n - 1; i > 0; --i) {
        int j = QRandomGenerator::global()->bounded(i + 1);
        qSwap(_cards[i], _cards[j]);
        qSwap(_images[i], _images[j]);
    }
}

Card Deck::takeCardFromDeck() {
    return _cards.takeLast();
}

QImage Deck::takeCardImageFromDeck()
{
    return _images.takeLast();
}

