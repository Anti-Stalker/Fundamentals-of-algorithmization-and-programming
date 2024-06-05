#include "player.h"

Player::Player(QString name, int gamePlayed, int winGames) {
    this->name = name;
    this->gamePlayed = gamePlayed;
    this->winGames = winGames;
}

void Player::setName(QString name) {
    this->name = name;
}

void Player::setGamePLayed(int gamePlayed) {
    this->gamePlayed = gamePlayed;
}

void Player::setWinGames(int winGames) {
    this->winGames = winGames;
}

QString Player::getName() {
    return this->name;
}

int Player::getGamePlayed() {
    return this->gamePlayed;
}
int Player::getWinGames() {
    return this->winGames;
}

QString Player::winRate() {
    if (gamePlayed) {
        double winRate = (double)(int)winGames / gamePlayed * 100;
        return QString::number(winRate) + "%";
    } else {
        return "0%";
    }
}

void Player::addWin() {
    this->winGames++;
}

void Player::addGame() {
    this->gamePlayed++;
}
