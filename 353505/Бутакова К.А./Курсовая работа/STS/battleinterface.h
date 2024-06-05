#ifndef RIGHTUI_H
#define RIGHTUI_H


#include <QWidget>
#include <QSize>

class CharacterUnit;
class QPushButton;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QPlainTextEdit;

class rightUi : public QWidget
{
    Q_OBJECT
public:
    rightUi(QWidget* parent = 0);
    ~rightUi();

private:
    QLabel *gameTitle;
    QVBoxLayout *gameTitleLayout;

    QPushButton *btnAttack;
    QPushButton *btnMove;
    QHBoxLayout *btnLayout;

    QLabel *roleTeamLabel;
    QLabel *roleClassLabel;
    QLabel *roleHPLabel;
    QLabel *roleATKLabel;
    QLabel *roleActionLabel;
    QGridLayout *infoLayout;
    QLabel *battleRecordTitle;
    QPlainTextEdit *battleRecordBox;
    QPushButton *btnClearBattleRecord;
    QVBoxLayout *battleRecordLayout;
    QLabel *TurnsNumberLabel;
    QLabel *WhoseTurnLabel;
    QPushButton *btnEndTurn;
    QVBoxLayout *turnControllerLayout;

    QVBoxLayout *mainLayout;
    QFont *LabelFont;
    QFont *LargeButtonFont;
    QFont *SmallButtonFont;

    void initTitleBox();
    void initDataBox();
    void initBattleRecord();
    void initTurnController();

signals:
    void sendRoleAction(std::string);
    void sendTurnEnding();

public slots:
    void RoleOnFocusChanged(CharacterUnit* role);
    void BattleSystemMessageReceived(QString message);
    void RoundChanged(QString team, int round);

private slots:
    void RoleActionSelectionChanged(std::string status);


};

#endif
