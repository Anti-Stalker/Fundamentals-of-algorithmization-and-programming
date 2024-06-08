#ifndef LETTERS_H
#define LETTERS_H

#include <QMap>

class Letters
{
private:
    int currentNumber = 0;

public:
    Letters() = default;

    bool addLetter();
    void removeLetter();
    int getCurrentNumber() const;
};

#endif // LETTERS_H
