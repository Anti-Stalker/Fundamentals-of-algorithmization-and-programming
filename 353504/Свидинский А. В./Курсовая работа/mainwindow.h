// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QTimer>
#include "hoverbutton.h"
#include "statsbars.h"
#include "statsgraph.h"
#include "clickergame.h"
#include "skillcheck.h"
#include "random.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void keyPressEvent(QKeyEvent *event);

    void on_startGameButton_clicked();

    void on_clickerButton_clicked();

    void on_acceptButton_clicked();

    void on_declineButton_clicked();

    void on_characterButton_clicked();

    void on_restartButton_clicked();

    void on_exitButton_clicked();

    void on_acceptButton_hovered();

    void on_declineButton_hovered();

    void on_restartButton_hovered();

    void on_exitButton_hovered();

    void on_optionButtons_unhovered();

    void on_endGameButtons_unhovered();

    void on_graphButton_hovered();

    void on_graphButton_unhovered();

    void resetGame();

    void game_plot();

    void updateStats();

    void updateGreenBar();

    void setCharacterGif(QString character, QString borderColor);

    void fadeAnimation(QGraphicsEffect *opacityEffect, QWidget *widget);

    void switchToGameScene();

    void setElderTitanGif() {
        setCharacterGif("elder_titan", "#32CD32");
    }

    void setAntimageGif() {
        setCharacterGif("antimage", "#32CD32");
    }

    void setAxeGif() {
        setCharacterGif("axe", "#32CD32");
    }

    void setBountyHunterGif() {
        setCharacterGif("bounty_hunter", "red");
    }

    void setEarthShakerGif() {
        setCharacterGif("earthshaker", "red");
    }

    void setInvokerGif() {
        setCharacterGif("invoker", "#32CD32");
    }

    void setPudgeGif() {
        setCharacterGif("pudge", "red");
    }

    void setNevermoreGif() {
        setCharacterGif("nevermore", "red");
    }

    void setSvenGif() {
        setCharacterGif("sven", "red");
    }

    void setWispGif() {
        setCharacterGif("wisp", "white");
    }

    void setDazzleGif() {
        setCharacterGif("dazzle", "white");
    }

    void setGabenGif() {
        setCharacterGif("gaben", "white");
    }

    void setTryhardGif() {
        setCharacterGif("tryhard", "white");
    }

    void setClickerVictoryGif() {
        setCharacterGif("earthshaker_victory", "white");
    }

    void setClickerLostGif() {
        setCharacterGif("earthshaker_lost", "white");
    }

    void setHighFiveGif() {
        setCharacterGif("high_five", "white");
    }

    void setAntimageDyingGif() {
        setCharacterGif("antimage_dying", "white");
    }

    void setDazzleTpGif() {
        setCharacterGif("dazzle_tp", "white");
    }

    void setConvincingAxeGif() {
        setCharacterGif("convincing_axe", "white");
    }

    void setAxeDyingGif() {
        setCharacterGif("axe_dying", "white");
    }

    void setDazzleJustifiedGif() {
        setCharacterGif("dazzle_justified", "white");
    }

    void on_stackedWidget_currentChanged(int arg1);

    void on_skillcheckButton_clicked();

    void updateSkillCheckBar();

    void stopAllMovies();

    void skillcheckEndGame();

private:
    Ui::MainWindow *ui;
    QPushButton *characterButton;
    HoverButton *acceptButton; // Объявляю указатели на подклассы кнопок
    HoverButton *declineButton;
    HoverButton *restartButton;
    HoverButton *exitButton;
    HoverButton *graphButton;
    StatsBars *statsBars;
    StatsGraph *statsGraph;
    ClickerGame *redBar;
    ClickerGame *greenBar;
    SkillCheck *skillCheckBar;
    QTimer *greenBarTimer;
    QTimer *skillCheckTimer;
    bool skillCheckGameStarted;
    bool actionapproved = true;
    bool isquestion = true;
    bool rhetorical = false;
    bool clickerGameEnded = false;
    bool clickerGameVictory = true;
    bool skillcheckGameEnded = false;
    bool skillcheckGameVictory = false;
    int redBarValue = 100;
    int greenBarValue = 100;
    int dialogStep = 0;
    int wealth = 50;
    int power = 50;
    int intelligence = 50;
    int decency = 50;
    int rng_skillcheck;
    int clickCount = 0;
    int maxStat;
    RandomNumberGenerator rng;

    std::unique_ptr<QMovie> characterMovie;
    std::unique_ptr<QMovie> menu_background;
    std::unique_ptr<QMovie> game_background;
    std::unique_ptr<QMovie> end_backgorund;
    std::unique_ptr<QMovie> endgame_background;
    std::unique_ptr<QMovie> skillcheck_background;
    std::unique_ptr<QMovie> endgame_label;
    std::unique_ptr<QMovie> skillcheck_label;
    std::unique_ptr<QMovie> skillcheck_text;
    std::unique_ptr<QMovie> restart_label;
    std::unique_ptr<QMovie> exit_label;
    std::unique_ptr<QMovie> clicker_label;
    std::unique_ptr<QMovie> shaker_fight_background;
    std::unique_ptr<QMovie> shaker_fight_label;
};

#endif // MAINWINDOW_H
