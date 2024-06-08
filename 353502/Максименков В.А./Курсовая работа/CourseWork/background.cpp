#include "background.h"


QRectF Background::boundingRect() const
{
    return targetRectForBackground;
}


void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawImage(targetRectForBackground, background);
}


Background::Background(int forWhat)
{
    switch (forWhat) {
    case 1: // для меню
        background = QImage(BACKGROUND_IMAGE);
        targetRectForBackground = QRectF(0, 0, 1115, 615);
        break;
    case 2: // для букв
        background = QImage(BACKGROUND_FOR_LETTERS_IMAGE);
        targetRectForBackground = QRectF(0, 0, 1055, 235);
        break;
    case 3: // для меню
        background = QImage(BACKGROUND_FOR_MENU_IMAGE);
        targetRectForBackground = QRectF(0, 0, 295, 235);
        break;
    case 4: // для gameplay
        background = QImage(BACKGROUND_FOR_GAME_IMAGE);
        targetRectForBackground = QRectF(0, 0, 1345, 565);
        break;
    default:
        throw 1;
        break;
    }

}
