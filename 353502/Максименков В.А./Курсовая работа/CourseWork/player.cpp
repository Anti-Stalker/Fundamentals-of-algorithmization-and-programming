#include "player.h"


int Player::getNumberOfPoints() const
{
    return numberOfPoints;
}


void Player::setNumberOfPoints(int newNumberOfPoints)
{
    numberOfPoints = newNumberOfPoints;
}


bool Player::wantToGetPrize()
{
    srand(time(0));
    int temp = 1 + rand() % MAX_PROCENT;
    return (temp >= (MAX_PROCENT / 2) ? true : false);
}


int Player::chooseKey()
{
    srand(time(0));
    int temp = 1 + rand() % 3;
    return temp;
}


int Player::getNumberOfCurrentRightLetters()
{
    return currentRightLetters.size();
}


bool Player::isExistsInRightLetters(QString letter)
{
    QString temp = "";

    for (int i = 0; i < currentRightLetters.size(); ++i)
    {
        temp = "";
        temp.push_back(currentRightLetters[i]);
        if (letter == temp)
        {
            return true;
        }
    }

    return false;
}


bool Player::isExists(const QString &whatFind, const QString &whereFind)
{
    QString currentLetter;

    if (whereFind.size() == 0)
    {
        return false;
    }

    for (int i = 0; i < whereFind.size(); ++i)
    {
        currentLetter = "";
        currentLetter.push_back(whereFind[i]);
        if (whatFind == currentLetter)
        {
            return true;
        }
    }

    return false;
}


Player::Player(const QString &answer, int level)
{
    QString temp, currentLetter;

    for (int i = 0; i < answer.size(); ++i)
    {
        currentLetter = "";
        currentLetter.push_back(answer[i]);
        if (!isExists(currentLetter, temp))
        {
            temp.push_back(currentLetter);
        }
    }

    for (int i = 0; i < temp.size(); ++i)
    {
        currentRightLetters.push_back(QString(temp[i]));
    }

    for (int i = 1; i < ALPHABET.size(); ++i)
    {
        currentLetter = "";
        currentLetter.push_back(ALPHABET[i]);
        if (!isExists(currentLetter, temp))
        {
            currentFakeLetters.push_back(currentLetter);
        }
    }

    this->level = level;
}


void Player::removeRightLetter(const QString &letter)
{
    QVector<QString> temp;

    for (int  i = 0; i < currentRightLetters.size(); ++i)
    {
        if (currentRightLetters[i] == letter) continue;
        else
        {
            temp.push_back(currentRightLetters[i]);
        }
    }
    currentRightLetters = temp;
}


void Player::removeFakeLetter(const QString &letter)
{
    QVector<QString> temp;

    for (int  i = 0; i < currentFakeLetters.size(); ++i)
    {
        if (currentFakeLetters[i] == letter) continue;
        else
        {
            temp.push_back(currentFakeLetters[i]);
        }
    }
    currentFakeLetters = temp;
}


QString Player::claimTheLetter()
{
    int generatingLetter = 0;
    QString ans = "";
    int temp = 1 + (rand() % MAX_PROCENT);
    srand(time(0));

    if (currentFakeLetters.size() == 0)
    {
        generatingLetter = rand() % currentRightLetters.size();
        ans = currentRightLetters[generatingLetter];
        return ans;
    }

    if (level != EASY_LEVEL && currentRightLetters.size() == 1)
    {
        generatingLetter = rand() % currentRightLetters.size();
        ans = currentRightLetters[generatingLetter];
        return ans;
    }

    if (temp <= level)
    {
        generatingLetter = rand() % currentRightLetters.size();
        ans = currentRightLetters[generatingLetter];
    }
    else
    {
        generatingLetter = rand() % currentFakeLetters.size();
        ans = currentFakeLetters[generatingLetter];
    }

    return ans;
}


QString Player::claimTheRightLetter()
{
    srand(time(0));
    int generatingLetter = rand() % currentRightLetters.size();
    QString ans = currentRightLetters[generatingLetter];
    return ans;
}


void Player::addPointsToComputer(int points)
{
    numberOfPoints += points;
}








