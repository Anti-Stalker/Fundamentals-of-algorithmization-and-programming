#include "view.h"
#include "game.h"
#include "menuscene.h"
#include "gamescene.h"
#include <QApplication>
#include <QKeyEvent>

View::View(QWidget *parent)
    : QGraphicsView(parent), m_gameScene(new GameScene()), m_menuScene(new MenuScene())
{
    setScene(m_menuScene);
    resize(Game::RESOLUTION.width()+2, Game::RESOLUTION.height()+2);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    createConnections();
}

void View::createConnections()
{
    connect(m_gameScene, &GameScene::goToMenuActivated, this, &View::menu);
    connect(m_menuScene, &MenuScene::startClicked, this, &View::start);

}

void View::start()
{
    setScene(m_gameScene);
    m_gameScene->start();

}

void View::menu()
{
    setScene(m_menuScene);
}

void View::keyPressEvent(QKeyEvent *event)
{
    if( !event->isAutoRepeat() )
    {
        switch(event->key())
        {
        case Qt::Key_Z:
            QApplication::instance()->quit();
            break;

        }
    }
    QGraphicsView::keyPressEvent(event);
}

