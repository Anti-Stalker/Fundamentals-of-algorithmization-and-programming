#include "combatzone.h"
#include "mapcell.h"
#include "chatacterunit.h"
#include "combatlogic.h"
#include "datahub.h"
#include "algorithms.h"
#include "animationcontrol.h"

#include <QKeyEvent>
#include <QThread>
#include <QEventLoop>
#include <QTimer>

void waiter(int time = 1000)
{
    QEventLoop *eventloop = new QEventLoop;
    QTimer::singleShot(time, eventloop, &QEventLoop::quit);
    eventloop->exec();
}

CombatZone::CombatZone(QGraphicsScene &scene, QWidget *parent) :
    QGraphicsView(parent), m_Scene(&scene), roleOnFocus(nullptr), groundOnFocus(nullptr)
{
    m_BlockLenght = FieldData::lenght;
    roleActionState = "MOVE";
    m_CombatLogic= new CombatLogic;
    connect(this, &CombatZone::playerAllDied, [=](){ emit sendBattleSystemMessage("You Lose!"); emit WinOrLose("You Lose!"); });
    connect(this, &CombatZone::enemyAllDied, [=](){ emit sendBattleSystemMessage("You Win!"); emit WinOrLose("You Win!"); });

    RoleAnimationControl = new AnimationControl;

}


void CombatZone::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Plus :
        scale(1.2, 1.2);
        break;
    case Qt::Key_Minus :
        scale(1 / 1.2, 1 / 1.2);
        break;
    }
    QGraphicsView::keyPressEvent(event);
}

void CombatZone::generateBattleField(const int size)
{
    int space = 0.5;
    m_MapSize = size;
    double offset = (m_MapSize * m_BlockLenght + (m_MapSize-1)*space) / 2 - m_BlockLenght / 2;
    GroundArray = new MapCell*[m_MapSize];
    for(int i = 0; i < m_MapSize; ++i)
    {
        GroundArray[i] = new MapCell[m_MapSize];
    }

    for(int i = 0; i < m_MapSize; ++i)
    {
        for(int j = 0; j < m_MapSize; ++j)
        {
            GroundArray[i][j].setColor(colorUsed::None_Brust, colorUsed::None_Pen);

            double x = i * (m_BlockLenght + space) - offset;
            double y = j * (m_BlockLenght + space) - offset;
            GroundArray[i][j].setPos(x, y);
            GroundArray[i][j].setCoor(i, j);
            GroundArray[i][j].setZValue(-1);
            connect(&GroundArray[i][j], &MapCell::GroundIsSelected, this, &CombatZone::GroundSelectedChange);
            m_Scene->addItem(&GroundArray[i][j]);
        }
    }
}

void CombatZone::generatePlayer(int n)
{
    for(int i = 0; i < n; ++i)
    {
        CharacterUnit *role;
        if(i%3 == 0)
        {
            role = new CharacterUnit(characterStatus::archer, m_BlockLenght, m_BlockLenght);
        }
        else
        {
            role = new CharacterUnit(characterStatus::soldier, m_BlockLenght, m_BlockLenght);
        }
        role->setOnMap(GroundArray[0][i].pos(), GroundArray[0][i].getCoorX(), GroundArray[0][i].getCoorY());
        GroundArray[0][i].getCoorInfo();
        role->setZValue(1);
        connect(role, &CharacterUnit::RoleIsSelected, this, &CombatZone::RoleSelectedChange);
        connect(role, &CharacterUnit::KillRole, this, &CombatZone::RoleIsKilled);
        connect(role, &CharacterUnit::statusGifRequest, RoleAnimationControl, &AnimationControl::StatusRequest);
        connect(role, &CharacterUnit::stopGif, RoleAnimationControl, &AnimationControl::StopGif);
        connect(RoleAnimationControl, &AnimationControl::sendUpdatePng, role, &CharacterUnit::PngUpdate);
        connect(RoleAnimationControl, &AnimationControl::sendUpdateGif, role, &CharacterUnit::GifUpdate);

        m_Scene->addItem(role);
        PlayerList.push_back(role);
    }
    return;
}

void CombatZone::generateEnemy(int n)
{
    for(int i = 0; i < n; ++i)
    {
        CharacterUnit *role = new CharacterUnit(characterStatus::skeleton, m_BlockLenght, m_BlockLenght);
        role->setOnMap(GroundArray[m_MapSize-1][m_MapSize-1-i].pos(), GroundArray[m_MapSize-1][m_MapSize-1-i].getCoorX(), GroundArray[m_MapSize-1][m_MapSize-1-i].getCoorY());
        role->setZValue(1);
        connect(role, &CharacterUnit::RoleIsSelected, this, &CombatZone::RoleSelectedChange);
        connect(role, &CharacterUnit::KillRole, this, &CombatZone::RoleIsKilled);
        connect(role, &CharacterUnit::statusGifRequest, RoleAnimationControl, &AnimationControl::StatusRequest);
        connect(role, &CharacterUnit::stopGif, RoleAnimationControl, &AnimationControl::StopGif);
        connect(RoleAnimationControl, &AnimationControl::sendUpdatePng, role, &CharacterUnit::PngUpdate);
        connect(RoleAnimationControl, &AnimationControl::sendUpdateGif, role, &CharacterUnit::GifUpdate);
        m_Scene->addItem(role);
        EnemyList.push_back(role);
    }
}

void CombatZone::generateObstacle(int type)
{
    switch (type)
    {
        case 1:
        {
            for(int i = 2; i < m_MapSize - 2; ++i)
            {
                GroundArray[i][i].setObstacle(true);
                GroundArray[i][m_MapSize-i-1].setObstacle(true);
                GroundArray[i][i].update();
                GroundArray[i][m_MapSize-i-1].update();
            }
        }
        break;

        case 2:
        default:
        {
            if(m_MapSize > 6)
            {
                for(int i = 2; i < m_MapSize - 2; ++i)
                {
                    GroundArray[3][i].setObstacle(true);
                    GroundArray[m_MapSize - 3 - 1][i].setObstacle(true);
                    GroundArray[3][i].update();
                    GroundArray[m_MapSize - 3 - 1][i].update();
                }
            }
        }
        break;

    }
}

void CombatZone::clearField()
{
    for(int i = 0; i < m_MapSize; ++i)
    {
        for(int j = 0; j < m_MapSize; ++j)
        {
            GroundArray[i][j].setColor(colorUsed::None_Brust, colorUsed::None_Pen);
            GroundArray[i][j].update();
        }
    }
    return;
}

void CombatZone::setRoleOnMap(CharacterUnit* role, int x_idx, int y_idx)
{
    emit sendBattleSystemMessage(QString("%1: %2 (%3, %4) is now move to (%5, %6)!").arg(role->getTeam()).arg(role->getClass()).arg(role->getCoorX()).arg(role->getCoorY()).arg(x_idx).arg(y_idx));
    PathfindingAlgorithm pf;
    pf.init(m_MapSize, m_CombatLogic->ObstacleMap);
    pf.setPoint(role->getCoorX(), role->getCoorY(), x_idx, y_idx);
    pf.FindPath();
    pf.PrintPath();

    if(!pf.m_path.isEmpty())
    {
        for(int i = 0; i < pf.m_path.size(); ++i)
        {
            int x = pf.m_path[i].first;
            int y = pf.m_path[i].second;
            role->MoveTo(&GroundArray[x][y]);
            waiter(animation::TIME_PRE_BLOCK);
        }
        emit role->stopGif(role);
        role->setMoved(true);
    }
}

QPointF CombatZone::getGPos(int x, int y)
{
    return GroundArray[x][y].pos();
}

int CombatZone::getGCoorX(int x, int y)
{
    return GroundArray[x][y].getCoorX();
}

int CombatZone::getGCoorY(int x, int y)
{
    return GroundArray[x][y].getCoorY();
}

bool CombatZone::checkIfActive(CharacterUnit* role)
{
    bool tmp = (roleActionState == "ATTACK" ? role->isAttacked() : role->isMoved());

    if(tmp == false)
    {
        return true;
    }
    else
    {
        emit sendBattleSystemMessage( QString("This role is unable to %1!").arg(QString::fromStdString(roleActionState)));
        return false;
    }
}

void CombatZone::removeRole(CharacterUnit* role)
{
    if(role->getTeam() == "Player")
    {
        int i = PlayerList.indexOf(role);
        if(i != -1)
        {
            delete role;
            PlayerList.remove(i);
        }
        else
        {
            emit sendBattleSystemMessage("ERROR! Player NOT FOUND!");
        }
    }
    else if(role->getTeam() == "Enemy")
    {
        int i = EnemyList.indexOf(role);
        if(i != -1)
        {
            delete role;
            EnemyList.remove(i);
        }
        else
        {
            emit sendBattleSystemMessage("ERROR! Enemy NOT FOUND!");
        }
    }
    if(PlayerList.isEmpty())
    {
        emit playerAllDied();
    }
    if(EnemyList.isEmpty())
    {
        emit enemyAllDied();
    }
}

void CombatZone::GroundSelectedChange(MapCell* block)
{
    printf("block (%d, %d) is clicked.\n", block->getCoorX(), block->getCoorY());
    printf("pos: (%d, %d)\n", static_cast<int>(block->pos().x()), static_cast<int>(block->pos().y()));

    QColor blockColor = block->getBrust();
    if(blockColor == colorUsed::MoveRange_Brust)
    {
        freezeUser(true);
        clearField();

        emit roleOnFocus->statusGifRequest(roleOnFocus, "MOVE");
        setRoleOnMap(roleOnFocus, block->getCoorX(), block->getCoorY());

        waiter(animation::TIME_PRE_BLOCK * (abs(roleOnFocus->getCoorX() - block->getCoorX()) + abs(roleOnFocus->getCoorY() - block->getCoorY())));
        freezeUser(false);
    }
    else if(blockColor == colorUsed::None_Brust)
    {
        clearField();
        roleOnFocus = nullptr;
        emit sendRoleOnFocus(roleOnFocus);
    }
    groundOnFocus = block;
    m_CombatLogic->updateMap();
}

void CombatZone::RoleSelectedChange(CharacterUnit* role)
{
    if(roleOnFocus != nullptr)
    {
        if(roleOnFocus->getTeam() == role->getTeam())
        {
            if(checkIfActive(role))
            {
                clearField();
                roleOnFocus = role;
                setRoleRange(role, roleActionState);
                emit sendBattleSystemMessage( QString("%1: %2 (%3, %4) is selected.").arg(roleOnFocus->getTeam()).arg(roleOnFocus->getClass()).arg(roleOnFocus->getCoorX()).arg(roleOnFocus->getCoorY()) );
            }
        }
        else if(roleActionState == "ATTACK")
        {
            if(checkIfActive(roleOnFocus))
            {
                int del_x = abs(role->getCoorX() - roleOnFocus->getCoorX());
                int del_y = abs(role->getCoorY() - roleOnFocus->getCoorY());
                if(roleOnFocus->m_data.AttackRange() >= del_x + del_y)
                {
                    printf("you are trying to attack.\n");
                    freezeUser(true);
                    clearField();
                    emit sendBattleSystemMessage( QString("%1: %2 (%3, %4) Attack!").arg(roleOnFocus->getTeam()).arg(roleOnFocus->getClass()).arg(roleOnFocus->getCoorX()).arg(roleOnFocus->getCoorY()) );
                    roleOnFocus->Attack(role);
                    freezeUser(false);
                }
                else
                {
                    printf("Too far to attack!\n");
                    emit sendBattleSystemMessage( QString("Too far to attack!"));
                }
            }
        }
    }
    else
    {
        printf("first!\n");
        if(role->getTeam() != m_CombatLogic->getWhoseTurn())
        {
            emit sendRoleOnFocus(role);
            roleOnFocus = nullptr;
            return;
        }
        else if(checkIfActive(role))
        {
            roleOnFocus = role;
            setRoleRange(role, roleActionState);
            emit sendBattleSystemMessage( QString("%1: %2 (%3, %4) is selected.").arg(roleOnFocus->getTeam()).arg(roleOnFocus->getClass()).arg(role->getCoorX()).arg(role->getCoorY()) );
        }
    }
    emit sendRoleOnFocus(roleOnFocus);
    m_CombatLogic->updateMap();
}

void CombatZone::RoleActionSelectionChange(std::string status)
{
    roleActionState = status;
    clearField();
    if(roleOnFocus != nullptr && checkIfActive(roleOnFocus))
    {
        setRoleRange(roleOnFocus, roleActionState);
    }
    else
    {
        roleOnFocus = nullptr;
    }
    if(status == "ATTACK")
    {
        printf("CombatZone: ATTACK!\n");
        emit sendBattleSystemMessage(QString("You choose to ATTACK!"));
    }
    else if(status == "MOVE")
    {
        printf("CombatZone: MOVE!\n");
        emit sendBattleSystemMessage(QString("You choose to MOVE!"));
    }
}

void CombatZone::setRoleRange(CharacterUnit* role, std::string note)
{
    if(role == nullptr) return;
    int x = role->getCoorX(), y = role->getCoorY();
    int range = (note == "ATTACK" ? role->m_data.AttackRange() : role->m_data.MoveRange());
    QColor brust = (note == "ATTACK" ? colorUsed::AttackRange_Brust : colorUsed::MoveRange_Brust);

    int xTail = (x + range >= m_MapSize ? m_MapSize - 1 : x + range);
    int yTail = (y + range >= m_MapSize ? m_MapSize - 1 : y + range);

    for(int i = (x - range > 0 ? x - range : 0); i <= xTail; ++i)
    {
        for(int j = (y - range > 0 ? y - range : 0); j <= yTail; ++j)
        {
            int w = abs(x - i), h = abs(y - j);
            if(w + h <= range){
                GroundArray[i][j].setColor(brust, colorUsed::Selected_Pen);
                GroundArray[i][j].update();
            }
        }
    }
}

void CombatZone::RoleIsKilled(CharacterUnit* target)
{
    // ai
    emit target->statusGifRequest(target, "DIE");
    emit sendBattleSystemMessage(target->getClass() + " was Killed!");
    waiter(animation::DIE_DELAY);
    removeRole(target);
    roleOnFocus = nullptr;
    emit sendRoleOnFocus(roleOnFocus);
}

void CombatZone::RoundChanged(QString team, int) // from CombatLogic::RoundEnd
{
    printf("\tCombatZone: RoundChanged\n");
    // clear focus
    roleOnFocus = nullptr;
    clearField();
    emit sendRoleOnFocus(roleOnFocus);

    if(team == "Player")
    {
        for(auto item : PlayerList)
        {
            item->TurnStartInit();
        }
        for(auto item : EnemyList)
        {
            item->Iced();
        }
    }
    else if(team == "Enemy")
    {
        for(auto item : EnemyList)
        {
            item->TurnStartInit();
        }
        for(auto item : PlayerList)
        {
            item->Iced();
        }
        if(!EnemyList.isEmpty())
        {
            freezeUser(true);
            for(auto enemy : EnemyList)
            {
                m_CombatLogic->AutoPlay(enemy, PlayerList);
                waiter(500);
            }
            freezeUser(false);
            emit AIdone();
        }
    }
}

