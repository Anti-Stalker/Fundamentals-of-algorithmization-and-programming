#include "prize.h"


int Prize::getPoints() const
{
    return points;
}


void Prize::setPoints(int newPoints)
{
    points = newPoints;
}


Prize::Prize()
{
    prices["Автомобиль"] = 2500;
    prices["Утюг"] = 300;
    prices["Телевизор"] = 700;
    prices["Кофемолка"] = 200;
    prices["Стиральная машина"] = 800;
    prices["Мультиварка"] = 500;
    prices["Компьютер"] = 1000;
    prices["Микроволновая печь"] = 600;
}


bool Prize::addPrize(QString prize)
{
    int price = prices[prize];

    if (points >= price)
    {
        points -= price;
        return true;
    }
    else
    {
        return false;
    }
}


void Prize::removePrize(QString prize)
{
    points += prices[prize];
}





















