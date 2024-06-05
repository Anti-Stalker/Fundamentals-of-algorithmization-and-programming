#pragma once

#include "../Maze/maze.h"

#include <qcontainerfwd.h>
#include <qframe.h>
#include <qlabel.h>
#include <qpixmap.h>
#include <qpoint.h>
#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Game;
}
QT_END_NAMESPACE


class Game : public QWidget {
    Q_OBJECT
public:
    Game(bool hardmode = false, QWidget *parent = nullptr);
    ~Game();

signals:
    void exitToMenu();

public slots:
    void setMaze(int width, int height, int cellSize = 20);

private slots:
    void updateScore(int score);
    void handlePause();

    void handlePowerupAdded(Powerup *powerup);
    void handlePowerupUsed(int index);
    void shift(QPointF offset);

private:
    QGraphicsScene *scene;

    Maze *maze = nullptr;
    Player *player = nullptr;
    QVector<QLabel*> powerupLabels;

    bool paused = false;

    int w, h;
    int size_x;
    int size_y;

    bool hardmode = true;

    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject* object, QEvent* event);

    void shiftToCenter();
protected:
    Ui::Game *ui;
};
