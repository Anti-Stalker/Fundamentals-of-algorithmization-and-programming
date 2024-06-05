#ifndef COMBATLOGIC_H
#define COMBATLOGIC_H

#include <QObject>
#include <QVector>
#include <QPair>
class CombatZone;
class CharacterUnit;

class CombatLogic : public QObject
{
    Q_OBJECT

public:
    CombatLogic(QObject* parent = 0);
    int getRound(){ printf("turn: %d\n", m_dTurn); return m_dTurn / 2 + 1; }
    QString getWhoseTurn(){ return WhoseTurn; }
    void StartRound();
    void StartTurn(QString team);
    void startGame();

    // about ai
    void AutoPlay(CharacterUnit* role, QVector<CharacterUnit*> &targetTeam);

    bool **ObstacleMap;
    void MapInit(CombatZone* field);
    void printMap();
    void updateMap();

    QPair<int, int> checkNearbyBlock(CharacterUnit* target);

public:
    CombatZone* Field;
    int m_dSize;
    int m_dTurn;
    QString WhoseTurn;

signals:
    void sendRoundStart(QString, int);
    void sendCombatLogicMessage(QString);


public slots:
    void RoundEnd();

};

#endif
