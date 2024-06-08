#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialogButtonBox>
#include <QLabel>
#include <QString>
#include <QThread>
#include <QTimer>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void quitGame();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_backFromLevelMenu_clicked();

    void on_easyDiff_clicked();

    void on_mediumDiff_clicked();

    void on_hardDiff_clicked();

    void on_pauseButton_clicked();

    void on_resume_clicked();

    void on_quitGame_clicked();

    void on_doubleUp_clicked();

    void on_oneKButton_clicked();

    void on_fiveKButton_clicked();

    void on_tenKButton_clicked();

    void on_repeatButton_clicked();

    void on_betButton_clicked();

    void on_hitButton_clicked();

    void on_standButton_clicked();

    void on_splitButton_clicked();

    void switchToPlayButtons();
    void switchToSplitButtons(int index);
    void switchToBetButtons();

    void hideButtons();

    void initializeMoveOnSplit();
    void initializeCardLabels();
    void initializeCardSplitLabels();
    void initializePlayerScore();
    void initializePlayerSplitScore();
    void initializePlayerChips();
    void changeAmount(int index);
    void whoIsNow(int index);

    void playerTakesCard(const QPixmap& pixmap, int index);
    void playerTakesSplitCard(const QPixmap& pixmap, int index);

    void positionOfCards(int i);
    void positionOfSplitCards(int i);
    void positionOfScoreAndChips(int i);

    void startNewTurn();

    void showPlayerScore(int score, int index);
    void showPlayerSplitScore(int score, int index);
    void showPlayerChips(int chips, int index);

    void on_doubleButton_clicked();

    void on_splitStand_clicked();

    void on_splitHit_clicked();

private:
    int _amount_of_players;
    int _xPosition = 0;
    int _yPosition = 0;
    int cardSpacing = 50;
    int playerSpacing = 0;
    int splitmove = 100;
    Game _game;
    QTimer *_timer = new QTimer(this);
    QVector<QVector<QLabel*>> _card_labels;
    QVector<QVector<QLabel*>> _split_card_labels;
    QVector<QLabel*> _score;
    QVector<QLabel*> _split_score;
    QVector<QLabel*> _chips;
    QVector<int> _card_count;
    QVector<int> _split_card_count;
    QVector<int> _move_on_split;
    QDialogButtonBox *buttonBox;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
