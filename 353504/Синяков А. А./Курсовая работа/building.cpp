#include "building.h"
#include <QBrush>
#include <QPen>
#include <QPainterPath>

Building::Building(QString &type, int population, int cost, QGraphicsItem *parent)
    : QGraphicsPathItem(parent), population(population), cost(cost)
{
    if (type == "House") {
        createHouse();
    } else if (type == "Factory") {
        createFactory();
    } else if (type == "Store") {
        createStore();
    } else if (type == "Park") {
        createPark();
    } else if (type == "Ski Resort") {
        createSkiResort();
    } else if (type == "Forest") {
        createForest();
    }
}
void Building::createHouse()
{
    QPainterPath path;

    // Крыша
    path.moveTo(-20, -20);
    path.lineTo(0, -40);
    path.lineTo(20, -20);
    path.closeSubpath();
    setBrush(QBrush(Qt::darkRed));
    setPen(QPen(Qt::darkRed));
    setPath(path);

    // Основное здание
    QPainterPath base;
    base.addRect(-20, -20, 40, 40);
    QGraphicsPathItem *baseItem = new QGraphicsPathItem(base, this);
    baseItem->setBrush(QBrush(Qt::red));
    baseItem->setPen(QPen(Qt::black));

    // Окна
    QPainterPath window1, window2;
    window1.addRect(-15, -10, 10, 10);
    window2.addRect(5, -10, 10, 10);
    QGraphicsPathItem *windowItem1 = new QGraphicsPathItem(window1, this);
    QGraphicsPathItem *windowItem2 = new QGraphicsPathItem(window2, this);
    windowItem1->setBrush(QBrush(Qt::yellow));
    windowItem2->setBrush(QBrush(Qt::yellow));
    windowItem1->setPen(QPen(Qt::black));
    windowItem2->setPen(QPen(Qt::black));
}

void Building::createFactory()
{
    QPainterPath path;

    // Основное здание
    path.addRect(-30, -15, 60, 30);
    setBrush(QBrush(QColorConstants::Svg::brown));
    setPen(QPen(Qt::black));
    setPath(path);

    // Дымоход
    QPainterPath chimney;
    chimney.addRect(-20, -25, 10, 10);
    QGraphicsPathItem *chimneyItem = new QGraphicsPathItem(chimney, this);
    chimneyItem->setBrush(QBrush(Qt::darkGray));
    chimneyItem->setPen(QPen(Qt::black));

    // Окна
    QPainterPath window1, window2, window3, window4;
    window1.addRect(-25, -5, 10, 5);
    window2.addRect(-10, -5, 10, 5);
    window3.addRect(5, -5, 10, 5);
    window4.addRect(20, -5, 10, 5);
    QGraphicsPathItem *windowItem1 = new QGraphicsPathItem(window1, this);
    QGraphicsPathItem *windowItem2 = new QGraphicsPathItem(window2, this);
    QGraphicsPathItem *windowItem3 = new QGraphicsPathItem(window3, this);
    QGraphicsPathItem *windowItem4 = new QGraphicsPathItem(window4, this);
    windowItem1->setBrush(QBrush(Qt::yellow));
    windowItem2->setBrush(QBrush(Qt::yellow));
    windowItem3->setBrush(QBrush(Qt::yellow));
    windowItem4->setBrush(QBrush(Qt::yellow));
    windowItem1->setPen(QPen(Qt::black));
    windowItem2->setPen(QPen(Qt::black));
    windowItem3->setPen(QPen(Qt::black));
    windowItem4->setPen(QPen(Qt::black));
}

void Building::createStore()
{
    QPainterPath path;

    // Основное здание
    path.addRect(-25, -25, 50, 50);
    setBrush(QBrush(Qt::yellow));
    setPen(QPen(Qt::black));
    setPath(path);

    // Вывеска
    QPainterPath sign;
    sign.addRect(-15, -35, 30, 10);
    QGraphicsPathItem *signItem = new QGraphicsPathItem(sign, this);
    signItem->setBrush(QBrush(Qt::blue));
    signItem->setPen(QPen(Qt::black));

    // Окна
    QPainterPath window1, window2, window3, window4;
    window1.addRect(-20, -15, 10, 10);
    window2.addRect(10, -15, 10, 10);
    window3.addRect(-20, 5, 10, 10);
    window4.addRect(10, 5, 10, 10);
    QGraphicsPathItem *windowItem1 = new QGraphicsPathItem(window1, this);
    QGraphicsPathItem *windowItem2 = new QGraphicsPathItem(window2, this);
    QGraphicsPathItem *windowItem3 = new QGraphicsPathItem(window3, this);
    QGraphicsPathItem *windowItem4 = new QGraphicsPathItem(window4, this);
    windowItem1->setBrush(QBrush(Qt::white));
    windowItem2->setBrush(QBrush(Qt::white));
    windowItem3->setBrush(QBrush(Qt::white));
    windowItem4->setBrush(QBrush(Qt::white));
    windowItem1->setPen(QPen(Qt::black));
    windowItem2->setPen(QPen(Qt::black));
    windowItem3->setPen(QPen(Qt::black));
    windowItem4->setPen(QPen(Qt::black));
}
void Building::createPark()
{
    QPainterPath path;

    // Создаем зеленую область, представляющую парк
    path.addEllipse(-25, -25, 50, 50);
    setBrush(QBrush(Qt::green));
    setPen(QPen(Qt::green));
    setPath(path);
}

void Building::createSkiResort()
{
    QPainterPath path;

    // Основа горы (белая)
    path.moveTo(-30, 20);
    path.lineTo(-20, -20);
    path.lineTo(-10, 10);
    path.lineTo(0, -10);
    path.lineTo(10, 10);
    path.lineTo(20, -20);
    path.lineTo(30, 20);
    path.lineTo(-30, 20);
    path.closeSubpath();

    // Задаем заливку для основы горы в белый цвет
    QPainterPath basePath;
    basePath.addPolygon(path.toFillPolygon());
    QGraphicsPathItem *baseItem = new QGraphicsPathItem(basePath, this);
    baseItem->setBrush(QBrush(Qt::white));

    // Вершина горы (покрытая снегом, желтая)
    QPainterPath peakPath;
    peakPath.moveTo(0, -20);
    peakPath.lineTo(-10, -30);
    peakPath.lineTo(0, -40);
    peakPath.lineTo(10, -30);
    peakPath.lineTo(0, -20);

    // Задаем заливку для вершины горы в желтый цвет
    QGraphicsPathItem *peakItem = new QGraphicsPathItem(peakPath, this);
    peakItem->setBrush(QBrush(Qt::yellow));

    // Необходимо также задать обводку для вершины горы в черный цвет
    peakItem->setPen(QPen(Qt::black));
}

void Building::createForest()
{
    QPainterPath path;

    // Рисуем несколько елок
    path.moveTo(0, -25); // Вершина первой ели
    path.lineTo(-10, 0); // Левая нижняя точка
    path.lineTo(10, 0); // Правая нижняя точка
    path.lineTo(0, -25); // Возврат к вершине

    // Сдвигаем путь, чтобы нарисовать вторую ель
    path.moveTo(-20, -10); // Вершина второй ели
    path.lineTo(-30, 15); // Левая нижняя точка
    path.lineTo(-10, 15); // Правая нижняя точка
    path.lineTo(-20, -10); // Возврат к вершине

    // Сдвигаем путь, чтобы нарисовать третью ель
    path.moveTo(20, 5); // Вершина третьей ели
    path.lineTo(10, 30); // Левая нижняя точка
    path.lineTo(30, 30); // Правая нижняя точка
    path.lineTo(20, 5); // Возврат к вершине

    // Задаем цвет и обводку для елок
    setBrush(QBrush(Qt::darkGreen));
    setPen(QPen(Qt::darkGreen));
    setPath(path);
}
QString Building::getType()
{
    return type;
}
