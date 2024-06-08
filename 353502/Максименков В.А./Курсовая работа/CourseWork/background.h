#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsItem>
#include <QPainter>
#include <QImage>

const QString BACKGROUND_IMAGE = "/home/vlad/Загрузки/Backgroung.jpg";
const QString BACKGROUND_FOR_LETTERS_IMAGE = "/home/vlad/Загрузки/BackgroundForLetters.webp";
const QString BACKGROUND_FOR_MENU_IMAGE = "/home/vlad/Загрузки/BackgroundForMenu.jpg";
const QString BACKGROUND_FOR_GAME_IMAGE = "/home/vlad/Загрузки/BackgroundForGame.jpeg";

class Background : public QGraphicsItem
{
private:
    QImage background;
    QRectF targetRectForBackground;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public:
    Background(int forWhat);
};

#endif // BACKGROUND_H
