#include "letters.h"


int Letters::getCurrentNumber() const
{
    return currentNumber;
}


bool Letters::addLetter()
{
    if (currentNumber < 7)
    {
        ++currentNumber;
        return true;
    }

    return false;
}


void Letters::removeLetter()
{
    --currentNumber;
}
