#pragma once

#include "Maze/maze.h"

#include "UI/menu.h"
#include "UI/game.h"

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
  
public:
    MainWindow();

private slots:
    void setUiToGame(int w, int h, bool hardmode);
    void setUiToMenu();

private:
    QGraphicsScene *scene;
    Maze *maze = nullptr;

protected:
    Ui::MainWindow *ui;
    Menu *menu = nullptr;
    Game *game = nullptr;
};
