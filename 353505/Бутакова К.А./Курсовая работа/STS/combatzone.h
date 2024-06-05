#ifndef COMBATZONE_H
#define COMBATZONE_H

#include "combatlogic.h"
#include <QGraphicsView>
class MapCell;
class CharacterUnit;
class CombatLogic;
class AnimationControl;


class CombatZone : public QGraphicsView {
    Q_OBJECT
public:
    // about itself
    explicit CombatZone(QGraphicsScene &scene, QWidget *parent = 0);
    void generateBattleField(const int size = 10);
    void generatePlayer(int n);
    void generateEnemy(int n);
    void generateObstacle(int type);
    void clearField();

    // battle system
    CombatLogic *m_CombatLogic;

    // about role
    void setRoleOnMap(CharacterUnit* role, int x_idx, int y_idx);
    QVector<CharacterUnit*> PlayerList;
    QVector<CharacterUnit*> EnemyList;

    // about ground index
    QPointF getGPos(int x, int y);
    int getGCoorX(int x, int y);
    int getGCoorY(int x, int y);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    MapCell** GroundArray;
    double m_BlockLenght;
    int m_MapSize;

    QGraphicsScene *m_Scene;

    std::string roleActionState; // ATTACK, MOVE
    bool checkIfActive(CharacterUnit* role);
    void removeRole(CharacterUnit* role);
    CharacterUnit* roleOnFocus;
    MapCell* groundOnFocus;

    AnimationControl *RoleAnimationControl;

signals:
    void sendRoleOnFocus(CharacterUnit*);
    void sendBattleSystemMessage(QString);

    void freezeUser(bool);

    void AIdone();

    void playerAllDied();
    void enemyAllDied();
    void WinOrLose(QString msg);

public slots:
    void GroundSelectedChange(MapCell* block);
    void RoleSelectedChange(CharacterUnit* role);
    void RoleActionSelectionChange(std::string status);
    void RoundChanged(QString team, int);

private slots:
    void setRoleRange(CharacterUnit* role, std::string note);
    void RoleIsKilled(CharacterUnit* target);

    friend class CombatZone;
};

#endif
