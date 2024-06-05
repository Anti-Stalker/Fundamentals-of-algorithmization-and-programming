#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <QFile>
#include <vector>
#include <QMovie>
#include <QPalette>
#include <QGraphicsDropShadowEffect>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QGraphicsView>
#include <QPainter>
#include <QTime>
#include <QKeyEvent>
#include <QTimer>

#include "player/player.h"
#include "heroes/hero.h"
#include "Stages/Farm/AnimatedRect.h"
#include "item.h"

#include "heroes/Lina/lina.h"
#include "heroes/Phoenix/phoenix.h"
#include "heroes/Venomancer/venomancer.h"
#include "heroes/DrowRanger/drowranger.h"
#include "heroes/DragonKnight/dragonknight.h"


#include "heroes/Lina/linadetails.h"
#include "heroes/Phoenix/phoenixdetails.h"
#include "heroes/Venomancer/venomancerdetails.h"
#include "heroes/DrowRanger/drowrangerdialog.h"
#include "heroes/DragonKnight/dragonknightdetails.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_addPlayer_cancel_clicked();

    void on_pushButton_2_clicked();


    void on_playersProfiles_button_clicked();

    void on_profiles_returnToMenu_clicked();

    void on_tableWidget_2_cellClicked(int row, int column);

    bool isPlayerExist(QString);

    bool isPlayerNameCorrect(QString);

    void readFromFile();
    void rewriteFile();

    void on_profilesTable_cellClicked(int row, int column);

    void on_deleteProfile_button_clicked();



    void on_createProfile_button_clicked();

    void on_playersProfiles_addButton_clicked();

    void on_playersProfiles_addCancel_clicked();

    void on_editProfile_button_clicked();

    void on_playersProfiles_editButton_clicked();

    void on_playersProfiles_editCancel_clicked();

    void on_pushButton_5_clicked();

    void on_endGame_button_clicked();

    void on_pushButton_3_clicked();

    void on_LinaDetails_button_clicked();

    void on_PhoenixChoose_button_clicked();

    void on_PhoenixDetails_button_clicked();

    void on_VenomancerChoose_button_clicked();

    void on_VenomancerDetails_button_clicked();

    void on_DRDetails_button_clicked();

    void on_DRChoose_button_clicked();

    void on_DKChoose_button_clicked();

    void on_DKDetails_button_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_startGame_clicked();

    void startAnimation1();
    void startAnimation2();
    void countdown();

    void onAnimationFinished1();
    void onAnimationFinished2();

    void stop_rect1();
    void stop_rect2();

    void on_shop_item1info_clicked();

    void on_shop_item2info_clicked();

    void on_shop_item3info_clicked();

    void on_pushButton_6_clicked();

    void on_shop_item1buy_clicked();

    void on_player1_about1_buttonInShop_clicked();

    void on_shop_item2buy_clicked();

    void on_shop_item3buy_clicked();

    void on_player1_about2_buttonInShop_clicked();

    void on_player1_about3_buttonInShop_clicked();

    void on_player2_about1_buttonInShop_clicked();

    void on_player2_about2_buttonInShop_clicked();

    void on_player2_about3_buttonInShop_clicked();

    void on_player1_aboutAb1_clicked();

    void on_player1_useAb1_clicked();

    void on_player1_aboutAb2_clicked();

    void on_player1_aboutAb3_clicked();

    void on_player2_aboutAb1_clicked();

    void on_player2_aboutAb2_clicked();

    void on_player2_aboutAb3_clicked();

    void on_player1_useAb2_clicked();

    void on_player1_useAb3_clicked();

    void on_player2_useAb1_clicked();

    void on_player2_useAb2_clicked();

    void on_player2_useAb3_clicked();

    void on_pushButton_14_clicked();

    void on_player1_useItem1_clicked();

    void useItem(int player, int item, int enemy, int);

    void on_player1_useItem2_clicked();

    void on_player1_useItem3_clicked();

    void on_player2_useItem1_clicked();

    void on_player2_useItem2_clicked();

    void on_player2_useItem3_clicked();

    void winner(int);

    void updateInvent();

    void on_pushButton_15_clicked();

    void on_sort_button_clicked();

    void shellSortDescending();
    void shellSortAscending();

    void on_player1Sur_clicked();

    void on_player2Sur_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_player1_aboutItem1_clicked();

    void on_player1_aboutItem2_clicked();

    void on_player1_aboutItem3_clicked();

    void on_player2_aboutItem1_clicked();

    void on_player2_aboutItem2_clicked();

    void on_player2_aboutItem3_clicked();

    void aboutItem(int, int);

    void on_player1_about1_button_clicked();

    void on_player1_about2_button_clicked();

    void on_player1_about3_button_clicked();

    void on_player2_about1_button_clicked();

    void on_player2_about2_button_clicked();

    void on_player2_about3_button_clicked();


    void on_pushButton_9_clicked();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::MainWindow *ui;

    //Player* players[100];
    std::vector<Player*> players;


    int selectedProfile;
    int playersCount = 0;

    std::vector<QString> selectedProfilesForGame;
    int currentChoosing = 0;

    std::vector<Hero> heroes;
    int currentHeroChoosing = 0;

    LinaDetails linaDetails;
    PhoenixDetails phoenixDetails;
    VenomancerDetails venomancerDetails;
    DrowRangerDialog drowRangerDetails;
    DragonKnightDetails dragonKnightDetails;

    bool isStageAnnouncement = false;
    bool isPlayer1Ready = false;
    bool isPlayer2Ready = false;

    bool isFarmStage = false;

    int stageCount = 1;

    QMovie *movie;
    QLabel *processLabel;

    AnimatedRect *rect1 = nullptr;
    AnimatedRect *rect2 = nullptr;
    QSequentialAnimationGroup *animationGroup1 = nullptr;
    QSequentialAnimationGroup *animationGroup2 = nullptr;
    QPoint yellowRectPos1;
    QPoint yellowRectPos2;
    int count;
    QTimer *timer = new QTimer(this);
    bool isFinished1 = false;
    bool isFinished2 = false;

    int finishedBoth = 0;

    int farmStages = 0;

    double speed = 1.0;

    bool farmStageFinished = false;

    int goldFarm = 100;

    int player1Received = 0;
    int player2Received = 0;

    int yellowRectSize = 70;

    void delay();

    std::vector<Item> items;
    std::vector<int> currentShop;
    int currentlyBuying = 0;

    int currentRound = 1;
    int rounds = 2;

    int P1ab1CD = 0;
    int P1ab2CD = 0;
    int P1ab3CD = 0;

    bool P1ab1used = false;
    bool P1ab2used = false;
    bool P1ab3used = false;

    int P2ab1CD = 0;
    int P2ab2CD = 0;
    int P2ab3CD = 0;

    bool P2ab1used = false;
    bool P2ab2used = false;
    bool P2ab3used = false;

    int battleOrder = 0;

    std::vector<Player*> currentPlayers;
    std::vector<Player*> tempPlayers;

    int sortState = 0;

    void clearGame();
};



#endif // MAINWINDOW_H
