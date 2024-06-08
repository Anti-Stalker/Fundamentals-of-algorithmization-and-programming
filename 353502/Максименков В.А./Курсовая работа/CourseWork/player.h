#ifndef PLAYER_H
#define PLAYER_H
#include <QVector>
#include <QString>
#include <QDebug>

#include "time.h"


const QString ALPHABET = " АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
const QString PLAYER = "player";
const QString COMPUTER_1 = "computer1";
const QString COMPUTER_2 = "computer2";
const int MAX_PROCENT = 100;
const int EASY_LEVEL = 30;
const int MEDIUM_LEVEL = 50;
const int HARD_LEVEL = 70;

class Player
{
private:
    int numberOfPoints = 0;
    int level = 0;
    QVector<QString> currentRightLetters;
    QVector<QString> currentFakeLetters;

    bool isExists(const QString& whatFind, const QString& whereFind);

public:
    explicit Player(const QString& answer, int level);

    void removeRightLetter(const QString &letter);
    void removeFakeLetter(const QString &letter);
    QString claimTheLetter();
    QString claimTheRightLetter();
    void addPointsToComputer(int points);
    int getNumberOfPoints() const;
    void setNumberOfPoints(int newNumberOfPoints);
    bool wantToGetPrize();
    int chooseKey();
    int getNumberOfCurrentRightLetters();
    bool isExistsInRightLetters(QString letter);
};

#endif // PLAYER_H
