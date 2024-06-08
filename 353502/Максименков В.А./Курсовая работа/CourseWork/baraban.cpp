#include "baraban.h"


void Baraban::advance(int phase)
{
    if (phase) rotationFunction();
}


Baraban::Baraban()
{
    QPointF tempPoint;
    double angle = (2 * PI) / NUMBER_OF_SECTORS;
    for (int i = 0; i < NUMBER_OF_SECTORS; ++i)
    {
        tempPoint = QPointF(RADIUS * cos(angle * i), RADIUS * sin(angle * i));
        points.push_back(tempPoint);
    }

    bankrot = QImage(BANKROT_IMAGE);
    prize = QImage(CHEST_IMAGE);
    key = QImage(KEY_ON_BARABAN_IMAGE);
    five = QImage(FIVE_HUNDRED_IMAGE);
    six = QImage(SIX_HUNDRED_IMAGE);
    seven = QImage(SEVEN_HUNDRED_IMAGE);
    eight = QImage(EIGHT_HUNDRED_IMAGE);
    ten = QImage(TEN_HUNDRED_IMAGE);
}


QRectF Baraban::boundingRect() const
{
    return QRectF(-RADIUS, -RADIUS, 2*RADIUS, 2*RADIUS);
}


void Baraban::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawEllipse(center, RADIUS, RADIUS);
    for (int i = 0; i < NUMBER_OF_SECTORS; ++i)
    {
        painter->drawLine(center, points[i]);
    }

    painter->setBrush(Qt::red);
    painter->drawEllipse(QPointF(-(2*RADIUS)/3, 0), RADIUS_OF_SECTOR_PLUS, RADIUS_OF_SECTOR_PLUS);

    painter->setBrush(Qt::green);
    painter->drawRect(-(shortLength/2)-(2*RADIUS)/3, -(longLength/2), shortLength, longLength);
    painter->drawRect(-(longLength/2)-(2*RADIUS)/3, -(shortLength/2), longLength, shortLength);

    painter->drawImage(QRectF(X_POSITION_OF_BANKROT, Y_POSITION_OF_BANKROT, SIZE_OF_PICTURES, SIZE_OF_PICTURES), bankrot);
    painter->drawImage(QRectF(X_POSITION_OF_PRIZE, Y_POSITION_OF_PRIZE, SIZE_OF_PICTURES, SIZE_OF_PICTURES), prize);
    painter->drawImage(QRectF(RADIUS/2, 20, 40, 40), key);

    painter->rotate(-20);
    painter->drawImage(QRectF(RADIUS/2, -20, 40, 40), five);

    painter->rotate(-80);
    painter->drawImage(QRectF(RADIUS/2, -20, 40, 40), eight);

    painter->rotate(-40);
    painter->drawImage(QRectF(RADIUS/2, -20, 40, 40), seven);

    painter->rotate(-80);
    painter->drawImage(QRectF(RADIUS/2, -20, 40, 40), six);

    painter->rotate(-40);
    painter->drawImage(QRectF(RADIUS/2, -20, 40, 40), ten);
}


void Baraban::rotationFunction()
{
    currentAngle += (PI / PART_OF_ANGLE);
    if (currentAngle >= MAX_ANGLE) currentAngle -= MAX_ANGLE;
    setTransformOriginPoint(boundingRect().center());
    setRotation(currentAngle);
    update();
}


int Baraban::evaluateCurrentSector()
{
    if ((currentAngle >= 0 && currentAngle <= HALFANGLE_OF_ONE_SECTOR) || (currentAngle >= (NUMBER_OF_SECTORS * 2 - 1) * HALFANGLE_OF_ONE_SECTOR)) return 1;
    int temp = floor(currentAngle/HALFANGLE_OF_ONE_SECTOR);
    if (temp % 2 == 0) temp -= 1;
    return (temp-1)/2 + 2;
}
