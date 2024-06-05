#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player {
private:
    QString name;
    int gamePlayed;
    int winGames;

public:
    Player(QString, int, int);

    void setName(QString name);
    void setGamePLayed(int gamePlayed);
    void setWinGames(int winGames);

    void addWin();
    void addGame();

    QString getName();
    int getGamePlayed();
    int getWinGames();

    QString winRate();
};

#endif // PLAYER_H
