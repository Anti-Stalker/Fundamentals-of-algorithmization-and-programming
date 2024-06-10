#ifndef NIMGAME_H
#define NIMGAME_H

#include <QObject>

class NimGame : public QObject
{
    Q_OBJECT
public:
    explicit NimGame(QObject *parent = nullptr, int numPiles = 3);
    void setInitialPiles(int *piles);
    bool checkEmpty();
    bool humanMove(int pile, int numItems);
    void aiMove(int maxTake);
    QString getWinner();
    int getPile(int index);
    int getNumPiles() const;

signals:
    void gameEnded(QString message);

private:
    int *piles;
    int numPiles;
    bool player1Turn = true;
};

#endif // NIMGAME_H
