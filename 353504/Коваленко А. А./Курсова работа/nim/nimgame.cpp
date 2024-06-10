#include "nimgame.h"
#include <cstdlib>
#include <ctime>

NimGame::NimGame(QObject *parent, int numPiles)
    : QObject(parent), numPiles(numPiles)
{
    piles = new int[numPiles];
}

void NimGame::setInitialPiles(int *initialPiles)
{
    for (int i = 0; i < numPiles; ++i) {
        piles[i] = initialPiles[i];
    }
}

bool NimGame::checkEmpty()
{
    for (int i = 0; i < numPiles; ++i) {
        if (piles[i] > 0) {
            return false;
        }
    }
    return true;
}

bool NimGame::humanMove(int pile, int numItems)
{
    if (piles[pile]>0)
    {
    piles[pile] -= numItems;
    player1Turn = !player1Turn;
    emit gameEnded(checkEmpty() ? getWinner() : "");
    return true;
    }
    return false;
}

void NimGame::aiMove(int maxTake)
{
    int nimSum = 0;
    for (int i = 0; i < numPiles; ++i) {
        nimSum ^= piles[i];
    }

    if (nimSum == 0) {
        // Если Ним-сумма ноль, делаем случайный ход
        srand(time(0));
        int pile, numItems;
        do {
            pile = rand() % numPiles;
            numItems = rand() % std::min(piles[pile], maxTake) + 1;
        } while (piles[pile] == 0);
        piles[pile] -= numItems;
    } else {
        // Оптимальный ход
        for (int i = 0; i < numPiles; ++i) {
            if ((piles[i] ^ nimSum) < piles[i]) {
                int numItems = piles[i] - (piles[i] ^ nimSum);
                if (numItems > maxTake) {
                    numItems = maxTake;
                }
                piles[i] -= numItems;
                break;
            }
        }
    }
    player1Turn = !player1Turn;
    emit gameEnded(checkEmpty() ? getWinner() : "");
}

QString NimGame::getWinner()
{
    return player1Turn ? "Компьютер выиграл!" : "Поздравляем! Вы выиграли!";
}

int NimGame::getPile(int index)
{
    return piles[index];
}

int NimGame::getNumPiles() const
{
    return numPiles;
}

