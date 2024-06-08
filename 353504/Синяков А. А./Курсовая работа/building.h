#ifndef BUILDING_H
#define BUILDING_H

#include <QGraphicsPathItem>
#include <QString>

class Building : public QGraphicsPathItem
{
public:
    Building(QString &type, int population = 0, int cost = 0, QGraphicsItem *parent = nullptr);

    int getPopulation() const { return population; }
    int getCost() const { return cost; }
    void setPopulation(int value) { population = value; }
    QString getType() ;

private:
    int population;
    int cost;
    QString type;
    void createHouse();
    void createFactory();
    void createStore();
    void createPark();
    void createSkiResort();
    void createForest();

};

#endif // BUILDING_H
