#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "UI/game.h"
#include "UI/menu.h"

#include <qgraphicsscene.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qspinbox.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    
    setUiToMenu();
}

void MainWindow::setUiToGame(int w, int h, bool hardmode) {
    if (menu != nullptr) {
        menu->deleteLater();
        menu = nullptr;
    }

    game = new Game(hardmode, ui->widget);
    ui->widget->layout()->addWidget(game);
    game->grabKeyboard();

    int cellSize;
    if (hardmode) { 
        cellSize = 32;
    } else {
        cellSize = 20;
    }

    game->setMaze(w, h, cellSize);
    connect(game, &Game::exitToMenu, this, &MainWindow::setUiToMenu);
    adjustSize();
}

void MainWindow::setUiToMenu() {
    if (game != nullptr) {
        game->deleteLater();
        game = nullptr;
    }


    adjustSize();
    menu = new Menu(ui->widget);
    ui->widget->layout()->addWidget(menu);
    ui->widget->adjustSize();
    menu->adjustSize();     
    connect(menu, &Menu::startGame, this, &MainWindow::setUiToGame);
}