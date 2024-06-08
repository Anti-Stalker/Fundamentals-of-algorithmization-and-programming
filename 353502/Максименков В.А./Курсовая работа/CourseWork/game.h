#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QFile>
#include <QCoreApplication>
#include <QVector>
#include <QTextBrowser>
#include <QPushButton>
#include <QPair>
#include <QGraphicsScene>
#include <QTimer>
#include <QTime>
#include <QtMultimedia/QMediaPlayer>
#include <QUrl>
#include <QMessageBox>

#include "player.h"
#include "baraban.h"
#include "background.h"
#include "arrow.h"
#include "key.h"
#include "letters.h"
#include "car.h"
#include "prize.h"
#include "prizeimage.h"

const int NUMBER_OF_TASKS = 25;
const int MAX_NUMBER_OF_LETTERS = 12;
const int MEDIUM_VOLUME = 50;
const int FREQUENCY_OF_TIMER = 1000 / 60;
const QString FILE_WITH_TASKS = "/home/vlad/QTprojects/PoleChudes/tasks.txt";
const QString SUCCESSFUL_FILE_OPENING = "Файл успешно открыт!";
const QString ERROR_FILE_OPENING = "Не удалось открыть файл!!!";
const QString ENABLED_COLOR_MODE = "background-color: rgb(46, 194, 126); color: rgb(200, 0, 0);";
const QString DISABLED_COLOR_MODE = "background-color: rgb(46, 194, 126); color: rgb(0, 0, 180);";
const QString DEFAULT_COLOUR_MODE = "background-color: rgb(205, 171, 143);\ncolor: rgb(36, 31, 49);";
const QString GREEN_COLOUR_MODE = "background-color: green; color: rgb(36, 31, 49);";
const QString RED_COLOUR_MODE = "background-color: red; color: rgb(36, 31, 49);";
const QString PURPLE_COLOUR_MODE = "background-color: purple; color: rgb(36, 31, 49)";

const QString SOUND_FOR_BARABAN = "/home/vlad/Загрузки/baraban.mp3";
const QString MUSIC_FOR_BEGINING = "/home/vlad/Загрузки/pole-chudes-fanfary-1.mp3";
const QString MUSIC_FOR_THE_RIGHT_KEY = "/home/vlad/Загрузки/pole_auto.mp3";
const QString SOUND_FOR_RIGHT_LETTER = "/home/vlad/Загрузки/pole_letter_correct.mp3";
const QString SOUND_FOR_PRIZES = "/home/vlad/Загрузки/prizes.mp3";
const QString OPEN_THE_LETTERS = "/home/vlad/Загрузки/Откройте!.mp3";
const QString NO = "/home/vlad/Загрузки/Нет (2).mp3";
const QString SOUND_FOR_WRONG_LETTER = "/home/vlad/Загрузки/pole_letter_wrong.mp3";
const QString MUSIC_FOR_BARABAN = "/home/vlad/Загрузки/baraban_1995_hq.mp3";
const QString SOUND_FOR_SUPERGAME = "/home/vlad/Загрузки/pole-chudes-super-igra-2.mp3";
const QString MUSIC_FOR_SUPERGAME = "/home/vlad/Загрузки/pole_cudes-60-seconds.mp3";
const QString SOUND_FOR_SECTOR_PLUS = "/home/vlad/Загрузки/Сектор плюс.mp3";
const QString SOUND_FOR_BANKROT = "/home/vlad/Загрузки/Банкрот2 .mp3";
const QString SOUND_FOR_SECTOR_KEY = "/home/vlad/Загрузки/SectorKey.mp3";
const QString SOUND_FOR_SECTOR_PRIZE = "/home/vlad/Загрузки/Сектор приз.mp3";
const QString SOUND_FOR_RIGHT_WORD = "/home/vlad/Загрузки/ПравильноеСлово.mp3";
const QString SOUND_FOR_WRONG_WORD = "/home/vlad/Загрузки/nevernoe-slovo.mp3";

const QString TEXT_FOR_BARABAN = "Вращайте барабан";
const QString TEXT_FOR_SECTOR_PLUS = "Сектор ПЛЮС на барабане! \nОткройте любую букву";
const QString TEXT_FOR_SECTOR_KEY = "Сектор КЛЮЧ на барабане!";
const QString TEXT_FOR_SECTOR_PRIZE = "Сектор ПРИЗ на барабане!\n Будете брать или останетесь в игре?";
const QString TEXT_FOR_SECTOR_BANKROT = "Ой! А вы - бынкрот. Переход хода";
const QString PRIZE = "ПРИЗ!";
const QString WANT_PRIZE = "Я хочу ПРИЗ!";
const QString WANT_MONEY = "Я беру деньги!";
const QString WANT_PLAY = "Буду играть";
const QString OPEN = "Откройте!";
const QString GAME_OVER = "Игра окончена";

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    void setUserName(const QString &newUserName);
    void setAnswer(const QString &newAnswer);
    void setQuestion(const QString &newQuestion);
    void setLevel(int newLevel);

signals:
    void giveup();

private slots:
    void onTimeout();

private:
    QVector<QTextBrowser*> letters;
    QVector<QPushButton*> buttons;
    QVector<QPushButton*> keyButtons;
    QVector<QString> russianLetters;
    QVector<QPushButton*> prizeButtons;
    QVector<QLabel*> priceLabels;

    Ui::Game *ui;
    QString userName;
    QString currentPlayer = PLAYER;
    QString answer, question;
    Player* player1, *player2;
    QGraphicsScene* scene, *sceneForKeys, *sceneForCar, *sceneForLetters, *sceneForMenu, *sceneForGame, *sceneForPrizes;
    Background* backgroundForLetters, *backgroundForMenu, *backgroundForGame;
    Baraban* baraban;
    Arrow* arrow;
    Key* key1, *key2, *key3;
    Letters* letteres;
    Car* car;
    Prize* prize;
    PrizeImage* prizeImage;
    QTimer* timer, *timerForSupergame;
    QMediaPlayer *music = new QMediaPlayer;

    QString currentChosenLetter = "";
    QString currentRemovedPlayer = "";
    int answerLength = 0;
    int numberOfCurrentChosenLetter = 0;
    int level = 0;
    int currentTime = 60;

    int microRotations = 0;
    int playerPoints = 0;
    int prizeCounter = 0;
    int state = 1; // 1 - кнопки с буквами бесполезны
                        // 2 - останавливает вызовы всех функций
                            // 3 - супер-игра
    bool isSectorPlus = false;
    bool isPlus = false;

    void stopTime(int sec = 1);
    void hideExtraBrowsers();
    void processLetterPress();
    void deactivateChosenMode(const QString &letter);
    int findPressedLetter();
    int findPressedKey();
    void playMusic(QString musicNow);
    void processMusicChange(QMediaPlayer::State newState);
    void rotateBaraban();
    bool isExists(const QString& letter);
    void openingLettersFunction(const QString &letter);
    void openLetter(int number, const QString &letter);
    void processClaimedLetter();
    void processSelectedKey(int number);
    void playAI();
    void processCurrentSector(int sector);
    void processSectorPlus();
    void processSectorBankrot();
    void processSectorKey();
    void processSectorPrize();
    void processPointSector();
    void addPoints();
    void selectKey();
    void openChosenLetter();
    void choosePlay();
    void choosePrize();
    void traidingWithPrize();
    void removeThePlayer();
    void getMoney();
    void answerTheWord();
    void claimTheWord();
    void rejectAnswerTheWord();
    void giveUPandShowMenu();
    void checkIfEnd();

    void showPrizes();
    void processClaimedPrize();
    int findClaimedPrize();
    void choosePrizes();
    void startSupergame();
    void rejectSupergame();
    void showAllPrizes(bool isSuperprize);
    QPair<QString, QString> readSupergameTaskFromFile(int index);
    void openChosenLettersInSupergame();
    bool processLetterInSupergame(int numberOfLetter);
    void checkAnswerInSupergame();
    void changeTimeValue();
};

#endif // GAME_H
