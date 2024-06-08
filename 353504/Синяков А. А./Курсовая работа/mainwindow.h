#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "coinsimulation.h"
#include "qgraphicsscene.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <QTextEdit>
#include <QString>
#include <QTextEdit>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QTimer>
#include<QKeyEvent>
#include<QScrollBar>
#include "bowlingpin.h"

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
    void on_Start_clicked();
    void simulateCoinToss();
    void on_comboBox_activated(int index);
    void on_back_clicked();
    void startGame();
    void playerAction();
    void on_back_2_clicked();
    void on_addbuilding_clicked();
    void on_back_3_clicked();
    void moveBall();
    void on_addPinsButton_clicked();
    void on_startBowling_clicked();
    void on_back_4_clicked();

 protected:
 void mousePressEvent(QMouseEvent *event) override;
private:
    Ui::MainWindow *ui;

    QGraphicsScene* scene;
    QGraphicsScene* scene2;
    CoinSimulation* coinSimulator;

    void plotCoinTossProbabilityGraph(int maxTosses, double tilt, double force, double mass);
    void plotForceProbabilityGraph(int maxTosses, double tilt, double mass);

    int minFortressStrength = 100;
    int maxFortressStrength = 500;
    int numEvents;
    int playerFortressStrength;
    int computerFortressStrength;

    int getRandomNumber(int min, int max);
    void attackRandomEnemy(int& fortressStrength);
    void attackLightInfantry(int& fortressStrength);
    void attackHeavyCavalry(int& fortressStrength);
    void attackMagic(int& fortressStrength);
    int getDefenseStrategy();
    int getAttackStrategy();
    bool defendFortress(int defenseStrategy, int& fortressStrength);
    QString determineResult(int playerDefenses, int computerDefenses);
    void attackArchers(int& fortressStrength);
    void attackCatapults(int& fortressStrength);
    // Вероятности победы при атаке и защите (инициализируем значения)
    double attackWinProbability = 0.5; // Начальная вероятность победы при атаке
    double defenseWinProbability = 0.5; // Начальная вероятность победы при защите

    // Структура для хранения данных о предыдущих результатах атаки и защиты
    struct GameResult {
        bool playerWon;
        bool computerWon;
    };

    // Вектор для хранения истории результатов игры
    std::vector<GameResult> gameResults;

    // Обновление вероятностей победы при атаке и защите на основе новой информации
    void updateProbabilities(int playerFortressStrength, int computerFortressStrength, int defenseStrategy, int attackStrategy);

    // Метод для вычисления вероятности атаки на основе Байесовской сети
    double computeAttackWinProbability();

    // Метод для вычисления вероятности защиты на основе Байесовской сети
    double computeDefenseWinProbability();

    // Метод для выбора действия компьютера на основе Байесовской сети
    int getComputerAction(int defenseStrategy, int attackStrategy);
    int getPlayerFortressStrength();
    int getComputerFortressStrength();
    int gameCount = 0;

    //----------------------------------------------
    QGraphicsScene *scene3;
    int money ; // Изначальное количество денег
    int initialMoney;
    void setupScene();
    int getBuildingCost(QString type);
    int getBuildingPopulation(QString type);
    void updatePopulationLabel();
    int getTotalBuildingsCount();
    int getTotalPopulation();
    int getTotalCityCost();
    void removeAllBuildings();
    QPoint selectedCell;
    // Определяем вероятности перехода между состояниями
    double transitionMatrix[3][3] = {
        {0.8, 0.1, 0.1},  // Без катастроф
        {0.2, 0.7, 0.1},  // Землетрясение
        {0.1, 0.2, 0.7}   // Пожар
    };

    // Функция для моделирования катастрофы
    void simulateDisasterEvent();
    void handleEarthquake();
    void handleFire();
    // Определяем размеры и расположение клеток
    const int cellSize = 110; // Размер клетки
    const int numRows = 4;   // Количество строк
    const int numCols = 4;   // Количество столбцов
    const int startX = 50;   // Начальная позиция X
    const int startY = 50;   // Начальная позиция Y
    const int spacing = 20;  // Расстояние между клетками
    const int cornerRadius = 15; // Радиус закругления углов
    int gamesPlayed=0;
    void handleVictory();
    int randomPopulation;

    void addBowlingField();
    void addPinsToField(int pinCount);
    QGraphicsScene *scene4;
    QVector<BowlingPin*> pins;
    QGraphicsEllipseItem *ballItem;
    QPolygonF polygon1;
    QTimer *timer;
    qreal ballRadius;
    qreal speed;
    int remainingPins;
    int totalPinsKnockedDown;
    int totalPinsKnockedDownOverall;
    int totalThrows;  // количество бросков в текущем фрейме
    bool firstThrow;  // флаг для отслеживания первого броска в фрейме
    void resetGame();
};
#endif // MAINWINDOW_H
