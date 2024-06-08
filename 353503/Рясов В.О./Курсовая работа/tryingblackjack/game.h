#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "player.h"
#include <QObject>
#include <QTimer>
#include <vector>
#include <iterator>

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    Player& getCurrentPlayer();
    void addPlayer(int amount);
    void nextPlayer();
    void startGame();
    void dealCard(Player &player);
    void dealSplitCard (Player &player);
    QPixmap getCardImage();
    void playerPlaceBet(int bet);
    void playerRepeatBet();
    void playerDoubleBet();
    void playerHit();
    void playerStand();
    void playerDouble();
    void playerSplit();
    void playerBust(Player &player);
    void playerSplitHit();
    void playerSplitStand();
    void playerSplitBust(Player &player);
    void endGame();
    void kickNahuy();
    void quitGame();
    int getIndex();
    Action setAction(Action action);
public slots:
    void dealerPlay();
signals:
    void gameStarted();
    void indexChanged(int index);
    void splited(int index);
    void splitEnded();
    void getPlayerScore(int score, int index);
    void getPlayerSplitScore(int score, int index);
    void getPlayerChips(int chips, int index);
    void amountHasChanged(int index);
    void dealersTurn();
    void cardDealt(const QPixmap& pixmap, int index);
    void splitCardDealt(const QPixmap& pixmap, int index);
    void gameEnded();
private:
    bool ended = false;
    bool standing = false;
    Deck *deck;
    int count{0};
    std::vector<Player> players;
    std::vector<Player>::iterator currentPlayer;
    int _index = 0;
    QTimer _timer;
    void endGameForSplit(Player &player, int i);
};

#endif // GAME_H
