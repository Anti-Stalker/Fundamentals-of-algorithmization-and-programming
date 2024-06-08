#include "mainwindow.h"
#include "TileWidget.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "levelgenerator.h"
#include "character.h"
#include "const.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), centralWidget(new QWidget), layout(new QGridLayout), level(GLOBAL_WIDTH, GLOBAL_HEIGHT)
{
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 30 * GLOBAL_WIDTH, 30 * GLOBAL_HEIGHT);
    LevelGenerator *levelGenerator = new LevelGenerator(GLOBAL_WIDTH, GLOBAL_HEIGHT);
    Character *character = new Character(levelGenerator, scene , this);

    createLevel(levelGenerator);

    setWindowState(Qt::WindowFullScreen);
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < layout->count(); ++i) {
        QWidget *widget = layout->itemAt(i)->widget();
        if (widget) {
            delete widget;
        }
    }
    delete layout;
    delete centralWidget;
}

void MainWindow::createLevel(LevelGenerator *levelGenerator) {
    const int width = levelGenerator->getWidth();
    const int height = levelGenerator->getHeight();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            TileWidget *tileWidget = new TileWidget(centralWidget);
            tileWidget->setType(levelGenerator->getTileType(x, y));
            layout->addWidget(tileWidget, y, x);
        }
    }
}
