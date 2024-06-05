#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QDebug>
#include <QShowEvent>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include <QElapsedTimer>
#include <QLabel>
#include <QTime>
#include <QHBoxLayout>
#include <QFile>
#include "tile.h"
#include "generator.h"
#include "solver.h"


namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(bool mode, QWidget *parent = nullptr);
    ~GameWidget();
    void setPaletteW(QPalette palette);
    QPalette Palette;
private:

    bool mod = 0;// game 0 , solve 1
    int gridSize;
    QVector<QVector<Tile*>> gridTiles;
    bool shown;
    double tileSize;
    void showEvent(QShowEvent *event);
    void initializeScene();
    Ui::GameWidget *ui;
    QVector<std::pair<QColor, QColor>> colors;
    QGraphicsScene* scene;
    QVector<QPushButton*> buttons;
    QString styleSheet ;

    void hilightArea(Tile* tile);

    int selectedCol = -1;
    int selectedRow = -1;

    QVector<QVector<int>> numbersField;
    QVector<QVector<int>> ansField;

    Generator* generator;

    QPushButton* backB;
    QPushButton* solveB;
    QPushButton* clearAllB;
    QPushButton* clrTile;
    QPushButton* generateB;
    QPushButton* timerB;

    QPushButton* helpB1;
    QPushButton* helpB2;

    QLabel* timerLabel;
    QTimer* updateTimer;
    int elapsedSeconds = 0;
    void stopTimer();
    void restartTimer();
    void startTimer();

    QLabel* starLabel1;
    QLabel* starLabel2;
    QLabel* starLabel3;
    bool isStarActive[3]={true, true, true};
    QLabel* difficultyLabel;
    void resizeFunction();
    int lvlReaded = 0;
signals:
    void backToMenu();

private slots:
    void on_backB_clicked();
    void on_solveB_clicked();
    void on_clearAllB_clicked();
    void buttonClicked();
    void clrTile_Clicked();
    void generateB_Clicked();
    void updateTime();
    void on_timerB_clicked();
    void on_helpB1_clicked();
    void on_helpB2_clicked();


protected:
    void resizeEvent(QResizeEvent* event);

};

#endif // GAMEWIDGET_H
