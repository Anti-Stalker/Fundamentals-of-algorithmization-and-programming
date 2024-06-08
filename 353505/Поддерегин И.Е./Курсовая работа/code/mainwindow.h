#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>

#include <boat.h>
#include <sail.h>
#include <saill.h>
#include <RandomGenerator.h>

static double i=290,i2= 410, j=650, j2=525, k=0;
static int quantityOfAIBoats = 10;
static int *coordinatesArr = new int[20] {110,190,270,350,430,510,590,670,750,830,
                                          150,130,310,390,470,550,630,710,710,110};
static int l=0;
static double c=0.1;
static long long score=0;
static bool inCollision=false;

static bool secondInCollision=false;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setVisibilityNewGame(bool b);

private slots:
    void on_action_triggered();

    void on_startBttn_clicked();

    void leftTimerSlot();

    void rightTimerSlot();

    void artificialTimerSlot1();
    void artificialTimerSlot2();
    void artificialTimerSlot3();
    void artificialTimerSlot4();
    void artificialTimerSlot5();
    void artificialTimerSlot6();
    void artificialTimerSlot7();
    void artificialTimerSlot8();
    void artificialTimerSlot9();
    void artificialTimerSlot10();
    void artificialTimersFunc(int temp);

    void spawnTimerSlot();

    void caseFunc();

    void nullScene();

    void generatePos();

    void bonus();

    void on_action_3_triggered();

private:
    Ui::MainWindow *ui;
    Boat *playerBoat;
    Boat *artificialBoat = new Boat[10];
    Sail *playerSail;
    Sail *artificialSail = new Sail[10];
    SailL *playerSailL;
    SailL *artificialSailL = new SailL[10];
    QGraphicsScene *playScene;
    QTimer *leftTimer;
    QTimer *rightTimer;
    QTimer *artificialTimer= new QTimer[10];
    QTimer *spawnTimer ;
    QTimer *colissionTimer;


protected:
    void keyPressEvent(QKeyEvent *e);
};
#endif // MAINWINDOW_H
