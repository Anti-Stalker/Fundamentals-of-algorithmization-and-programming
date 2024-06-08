#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "game.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QElapsedTimer>

class QSoundEffect;
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QObject* parent = nullptr);
    void start();
    void stop();

private:
    void renderScene();
    Game game;
    QGraphicsPixmapItem* m_background, *m_tiles, *m_frame;

    const float timePerFrame;
    QTimer *timer;

    void applyBestMove();
    Point nearestNeighbor();
    void drawScore();
    void drawGameState();

    void drawActiveFigure();

    void moveFigure();
    void breadthFirstSearch();
    void depthFirstSearch();
    void drawBackground();
    void countingSortByEmptyCells(std::vector<int>& arr);
    std::vector<Point> depthFirstSearch(Point start, Point end);

    void rotateFigure();

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
private slots:
    void update();
signals:
    void goToMenuActivated();
};

#endif // GAMESCENE_H

