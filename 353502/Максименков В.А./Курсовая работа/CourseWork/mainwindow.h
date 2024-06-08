#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTimer>
#include <QDebug>
#include "game.h"
#include "background.h"
#include <QGraphicsItem>

const int TIME_FOR_STOP_TIMER = 80;
const QString INFORMATION_HEADER = "Ошибка авторизации";
const QString INFORMATION_TEXT = "Введите имя пользователя!";
const QString INFORMATION_LONG_NAME = "Имя не должно превышать 10 символов!";

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

private:
    Ui::MainWindow *ui;
    Game* game;
    QTimer* timer;
    QGraphicsScene* scene;
    Background* background;

    int sec = 0;
    int level = EASY_LEVEL;

    void startGame();
    void exitGame();
    void showMenu();

private slots:
    void onTimeout();
    void on_comboBox_activated(int index);
};
#endif // MAINWINDOW_H
