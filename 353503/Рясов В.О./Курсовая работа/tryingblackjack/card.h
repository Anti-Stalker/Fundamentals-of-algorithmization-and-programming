#ifndef CARD_H
#define CARD_H
#include <QString>

class Card
{
public:
    Card(QString suit, QString value);
    QString getSuit() { return _suit; }
    QString getValue() { return _value; }
private:
    QString _image_path;
    QString _suit;
    QString _value;
};

#endif // CARD_H
