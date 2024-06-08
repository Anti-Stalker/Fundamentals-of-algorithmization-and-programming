#ifndef BARABAN_H
#define BARABAN_H

#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include <QImage>
#include <cmath>

const int RADIUS = 150;
const int RADIUS_OF_SECTOR_PLUS = 16;
const double PI = 3.1416;
const int NUMBER_OF_SECTORS = 9;
const double MAX_ANGLE = 360.0;
const int PART_OF_ANGLE = 20;
const int RANGE_OF_NUMBER_OF_ROTATIONS = 10;
const int NUMBER_OF_MICROROTATIONS = 1500;
const int HALFANGLE_OF_ONE_SECTOR = 20;
const int SIZE_OF_PICTURES = 60;
const int X_POSITION_OF_BANKROT = 20;
const int Y_POSITION_OF_BANKROT = 50;
const int X_POSITION_OF_PRIZE = 25;
const int Y_POSITION_OF_PRIZE = -120;
const QString BANKROT_IMAGE = "/home/vlad/Загрузки/bankrot.png";
const QString CHEST_IMAGE = "/home/vlad/Загрузки/chest.png";
const QString KEY_ON_BARABAN_IMAGE = "/home/vlad/Загрузки/Key-Free-PNG-Image.png";
const QString FIVE_HUNDRED_IMAGE = "/home/vlad/Загрузки/500.jpeg";
const QString SIX_HUNDRED_IMAGE = "/home/vlad/Загрузки/600.jpeg";
const QString SEVEN_HUNDRED_IMAGE = "/home/vlad/Загрузки/700.jpeg";
const QString EIGHT_HUNDRED_IMAGE = "/home/vlad/Загрузки/800.jpeg";
const QString TEN_HUNDRED_IMAGE = "/home/vlad/Загрузки/1000.jpeg";

class Baraban : public QGraphicsItem
{
private:
    QPointF center = QPointF(0, 0);
    QVector<QPointF> points;
    double currentAngle = 0;
    QImage bankrot, prize, key;
    QImage five, six, seven, eight, ten;

    int shortLength = RADIUS_OF_SECTOR_PLUS/2;
    int longLength = 3*RADIUS_OF_SECTOR_PLUS/2;

public:
    Baraban();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void rotationFunction();
    int evaluateCurrentSector();

private slots:
    void advance(int phase) override;

};

#endif // BARABAN_H
