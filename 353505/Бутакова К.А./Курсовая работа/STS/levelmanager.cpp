#include "combatzone.h"
#include "combatlogic.h"
#include "levelmanager.h"
#include "battleinterface.h"
#include "chatacterunit.h"
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QCloseEvent>


LevelManager::LevelManager(QMainWindow *parent) : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-400, -400, 800, 800);
    Field = new CombatZone(*scene, this);
    Field->setScene(scene);
    Field->setBackgroundBrush(QPixmap(":/background/bg.png"));

    right = new rightUi(this);
    right->setFixedWidth(500);

    QObject::connect(right, &rightUi::sendRoleAction, Field, &CombatZone::RoleActionSelectionChange);
    QObject::connect(Field, &CombatZone::sendRoleOnFocus, right, &rightUi::RoleOnFocusChanged);

    QObject::connect(Field, &CombatZone::sendBattleSystemMessage, right, &rightUi::BattleSystemMessageReceived);
    QObject::connect(Field->m_CombatLogic, &CombatLogic::sendCombatLogicMessage, right, &rightUi::BattleSystemMessageReceived);

    QObject::connect(right, &rightUi::sendTurnEnding, Field->m_CombatLogic, &CombatLogic::RoundEnd);
    QObject::connect(Field->m_CombatLogic, &CombatLogic::sendRoundStart, right, &rightUi::RoundChanged);
    QObject::connect(Field->m_CombatLogic, &CombatLogic::sendRoundStart, Field, &CombatZone::RoundChanged);

    QObject::connect(Field, &CombatZone::WinOrLose, this, &LevelManager::ExitGame);
    QObject::connect(Field, &CombatZone::AIdone, right, &rightUi::sendTurnEnding);
    QObject::connect(Field, &CombatZone::freezeUser, this, &LevelManager::StopEvent);

    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(Field);
    mainLayout->addWidget(right);
    w = new QWidget(this);
    this->setCentralWidget(w);
    w->setLayout(mainLayout);
}

void LevelManager::CreateBattleField(int player, int enemy, int map, int obstacle)
{
    Field->generateBattleField(map);
    Field->generatePlayer(player);
    Field->generateEnemy(enemy);
    Field->generateObstacle(obstacle);
    Field->m_CombatLogic->MapInit(Field);
}

void LevelManager::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, tr("Exiting Level"),
                                                                tr("Exit?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        this->hide();
        event->ignore();
        emit backToMenu();
    }
}

void LevelManager::startLevel(LevelManager* lv)
{
    if(lv == this)
    {
        this->show();
        Field->m_CombatLogic->startGame();
    }
}

void LevelManager::ExitGame(QString msg)
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QLabel{min-width: 200px;}");
    msgBox.setText(msg);
    msgBox.setWindowTitle("Good Game!");
    msgBox.exec();
    StopEvent(true);
    this->close();
}
