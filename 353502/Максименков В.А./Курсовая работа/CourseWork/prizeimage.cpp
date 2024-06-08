#include "prizeimage.h"


PrizeImage::PrizeImage(int numberOfPrize)
{
    switch (numberOfPrize) {
    case 1:
        _prize = QImage(COFFECUTTER_IMAGE);
        break;
    case 2:
        _prize = QImage(IRON_IMAGE);
        break;
    case 3:
        _prize = QImage(MULTYCOOKER_IMAGE);
        break;
    case 4:
        _prize = QImage(MICROWAVE_IMAGE);
        break;
    case 5:
        _prize = QImage(TV_IMAGE);
        break;
    case 6:
        _prize = QImage(WASHING_MACHINE_IMAGE);
        break;
    case 7:
        _prize = QImage(COMPUTER_IMAGE);
        break;
    case 8:
        _prize = QImage(AUTOMOBILE_IMAGE);
        break;
    case 9:
        _prize = QImage(DELTAPLAN_IMAGE);
        break;
    default:
        _prize = QImage(MONEY_IMAGE);
        break;
    }
}


QRectF PrizeImage::boundingRect() const
{
    return targetRect;
}


void PrizeImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawImage(targetRect, _prize);
}







