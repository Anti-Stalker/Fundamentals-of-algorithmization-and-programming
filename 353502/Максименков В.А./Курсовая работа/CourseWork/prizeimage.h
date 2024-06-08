#ifndef PRIZEIMAGE_H
#define PRIZEIMAGE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QImage>

const QString MONEY_IMAGE = "/home/vlad/Загрузки/Деньги.jpg";
const QString COFFECUTTER_IMAGE = "/home/vlad/Загрузки/Кофемолка.jpg";
const QString IRON_IMAGE = "/home/vlad/Загрузки/Утюг.jpg";
const QString MULTYCOOKER_IMAGE = "/home/vlad/Загрузки/Мультиварка.jpg";
const QString MICROWAVE_IMAGE = "/home/vlad/Загрузки/Микроволновка.jpg";
const QString TV_IMAGE = "/home/vlad/Загрузки/Телевизор.webp";
const QString WASHING_MACHINE_IMAGE = "/home/vlad/Загрузки/Стиралка.jpeg";
const QString COMPUTER_IMAGE = "/home/vlad/Загрузки/Компьютер.jpeg";
const QString AUTOMOBILE_IMAGE = "/home/vlad/Загрузки/Automobile.jpeg";
const QString DELTAPLAN_IMAGE = "/home/vlad/Загрузки/Суперприз.webp";

class PrizeImage : public QGraphicsItem
{
private:
    QImage _prize;
    QRectF targetRect = QRectF(0, 0, 100, 100);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public:
    PrizeImage(int numberOfPrize);
};

#endif // PRIZEIMAGE_H
