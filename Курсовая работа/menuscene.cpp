#include "menuscene.h"
#include "game.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDir>
#include <QPainter>

MenuScene::MenuScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setBackgroundBrush(QBrush(QColor(0, 0, 0, 255)));
    setSceneRect(0, 0, Game::RESOLUTION.width(), Game::RESOLUTION.height());
    loadPixmaps();
    m_tetrisTitleItem = new QGraphicsPixmapItem(m_tetrisTitlePixmap.scaled(320, m_tetrisTitlePixmap.height()));
    addItem(m_tetrisTitleItem);
    m_startItem = new QGraphicsPixmapItem(m_startTextPixmap);
    addItem(m_startItem);

    createItemPos();
}

void MenuScene::loadPixmaps()
{
    if( !m_tetrisTitlePixmap.load(":/images/tetris_title.png") )
    {
        qDebug() << "Failed to load: " << ":/images/tetris_title.png";
    }

    if( !m_startTextPixmap.load(":/images/start_text.png") )
    {
        qDebug() << "Failed to load: " << ":/images/start_text.png";
    }

 }

void MenuScene::createItemPos()
{
    m_tetrisTitleItem->setPos(150,200);
    m_startItem->setPos(240, 400);

}

void MenuScene::renderScene()
{
    QString fileName = QDir::currentPath() + QDir::separator() + "game_menu.png";
    QRect rect = sceneRect().toAlignedRect();
    QImage image(rect.size(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter painter(&image);
    render(&painter);
    image.save(fileName);
    qDebug() << "saved " << fileName;
}

void MenuScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(
        event->scenePos().x() > m_startItem->x() && event->scenePos().x() < (m_startItem->x() + m_startItem->boundingRect().width()) &&
        event->scenePos().y() > m_startItem->y() && event->scenePos().y() < (m_startItem->y() + m_startItem->boundingRect().height())

        )
    {
        qDebug() << "Start clicked";
        emit startClicked();
    }

    QGraphicsScene::mousePressEvent(event);
}


