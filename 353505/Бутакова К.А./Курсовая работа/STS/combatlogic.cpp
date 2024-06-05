#include "combatlogic.h"
#include "combatzone.h"
#include "mapcell.h"
#include "chatacterunit.h"
#include "algorithms.h"

#include <cstring>

extern void waiter(int time = 1000);

CombatLogic::CombatLogic(QObject* parent) : QObject(parent)
{
    WhoseTurn = "Player";
    m_dTurn = 0;
}

void CombatLogic::MapInit(CombatZone* field)
{
    Field = field;
    m_dSize = field->m_MapSize;
    ObstacleMap = new bool*[m_dSize];
    for(int i = 0; i < m_dSize; ++i)
    {
        ObstacleMap[i] = new bool[m_dSize];
    }

    updateMap();
}

void CombatLogic::printMap()
{
    for(int i = 0; i < m_dSize; ++i)
    {
        for(int j = 0; j < m_dSize; ++j)
        {
            printf("%d\t", ObstacleMap[j][i]);
        }
        printf("\n\n");
    }
}

void CombatLogic::updateMap()
{
    if(Field != nullptr)
    {
        for(int i = 0; i < m_dSize; ++i)
        {
            ObstacleMap[i] = new bool[m_dSize];
            for(int j = 0; j < m_dSize; ++j)
            {
                ObstacleMap[i][j] = Field->GroundArray[i][j].isObstacle();
            }
        }

        for(auto item : Field->PlayerList)
        {
            int x = item->getCoorX(), y = item->getCoorY();
            ObstacleMap[x][y] = true;
        }
        for(auto item : Field->EnemyList)
        {
            int x = item->getCoorX(), y = item->getCoorY();
            ObstacleMap[x][y] = true;
        }
    }
}

void CombatLogic::startGame()
{
    emit sendCombatLogicMessage(QString("Game Start!"));
    emit sendRoundStart("Player", getRound());
}

void CombatLogic::AutoPlay(CharacterUnit* role, QVector<CharacterUnit*> &targetTeam)
{
    emit sendCombatLogicMessage("Enemy is moving.");

    CharacterUnit* target = nullptr, *nearestTarget = nullptr;
    int MoveMin = 10e6, AtkMin = 10e6;
    for(auto item : targetTeam)
    {
        int range = role->getAtkRange();
        int dis = role->getDistance(item);
        printf("%d\t", dis);
        if(range >= role->getDistance(item))
        {
            if(dis < AtkMin)
            {
                AtkMin = dis;
                printf("%d %d\n", range, role->getDistance(item));
                target = item;
            }
        }
        if(dis < MoveMin)
        {
            MoveMin = dis;
            nearestTarget = item;
        }
    }
    printf("\n");
    if(target == nullptr && nearestTarget != nullptr)
    {
        QPair<int, int> point = checkNearbyBlock(nearestTarget);
        if(point.first != -1 && point.second != -1)
        {
            printf("No target could attack; move.\n");
            emit role->statusGifRequest(role, "MOVE");
            PathfindingAlgorithm pf;
            pf.init(m_dSize, ObstacleMap);
            pf.setPoint(role->getCoorX(), role->getCoorY(), point.first, point.second);
            pf.FindPath();
            for(int i = 0; i < ((role->getMoveRange() > pf.m_path.size()) ? pf.m_path.size() : role->getMoveRange()); ++i)
            {
                int x = pf.m_path[i].first;
                int y = pf.m_path[i].second;
                role->MoveTo(&(Field->GroundArray[x][y]));
                waiter(animation::TIME_PRE_BLOCK);
            }
            emit role->stopGif(role);
            role->setMoved(true);
        }
    }
    else
    {
        printf("could attack\n");
    }

    for(auto item : targetTeam)
    {
        int range = role->getAtkRange();
        if(range >= role->getDistance(item))
        {
            printf("%d %d\n", range, role->getDistance(item));
            target = item;
        }
    }

    if(target != nullptr)
    {
        role->Attack(target);
    }
    Field->roleOnFocus = nullptr;
    emit Field->sendRoleOnFocus(Field->roleOnFocus);
    updateMap();
}

QPair<int, int> CombatLogic::checkNearbyBlock(CharacterUnit* target)
{
    for(int i = -1; i <=1 ; ++i)
    {
        for(int j = -1; j <= 1; ++j)
        {
            int x = target->getCoorX() + i;
            int y = target->getCoorY() + i;
            if(x >=0 && x < m_dSize && x >= 0 && x < m_dSize)
            {
                if(ObstacleMap[x][y] == false)
                {
                    //sucess
                    return QPair<int, int>(x, y);
                }
            }
        }
    }
    return QPair<int, int>(-1, -1);
}

void CombatLogic::RoundEnd()
{
    printf("\tCombatLogic: RoundEnd\n");
    ++m_dTurn;
    if(WhoseTurn == "Player")
    {
        WhoseTurn = "Enemy";
        emit sendCombatLogicMessage("Player's Turn End.");
        printf("Player's Turn End.");
        emit sendRoundStart("Enemy", getRound());
    }
    else if(WhoseTurn == "Enemy")
    {
        WhoseTurn = "Player";
        emit sendCombatLogicMessage("Enemy's Turn End.");
         printf("Enemy's Turn End.");
        emit sendRoundStart("Player", getRound());
    }
    updateMap();
}
