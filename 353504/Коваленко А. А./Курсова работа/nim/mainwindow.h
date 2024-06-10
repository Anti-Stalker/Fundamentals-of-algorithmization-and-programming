#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nimgame.h"

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
    void on_startGameButton_clicked();
    void on_infoButton_clicked();
    void on_exitButton_clicked();
    void on_startGamePlayButton_clicked();
    void handleGameEnd(QString message);
    void on_humanMoveButton_clicked();
    void on_pileSpinBox_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    NimGame *game;
    void showGameSettings();
    void showGame();
    void updateGameState();
    bool isTwoPlayerMode;
    int maxTake;
};

#endif // MAINWINDOW_H

