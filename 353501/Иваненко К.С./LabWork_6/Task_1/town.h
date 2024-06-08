#pragma once

#define TOWN_H
#ifdef TOWN_H

#include <QString>
#include <qtmetamacros.h>

class Town
{
public:
    Town()
    {
        data.name = "Mozyr";
        data.population = 111'801;
        data.area = 44.14;
        data.region = 'G';
        data.isCapital = true;
        data.mayoralElections[0] = 2016;
        data.mayoralElections[1] = 2020;
        data.mayoralElections[2] = 2024;
    };
    ~Town(){};

    QString name() { return data.name; }
    void setName(QString newName)
    {
        data.name = newName;
    }

    int population() { return data.population; }
    void setPopulation(int newPopulation)
    {
        data.population = newPopulation;
    }

    double area() { return data.area; }
    void setArea(double newArea)
    {
        data.area = newArea;
    }

    QChar region() { return data.region; }
    void setRegion(QChar newRegion)
    {
        data.region = newRegion;
    }

    bool isCapital() { return data.isCapital; }
    void setIsCapital(bool newEvil)
    {
        data.isCapital = newEvil;
    }

    long long mayoralElection(long long year = 2) { return data.mayoralElections[year]; }
    void setMayoralElection(long long newVal, long long year = 2)
    {
        data.mayoralElections[year] = newVal;
    }

    QString report()
    {
        QString result;
        result.append(name()).append(" | ");
        result.append(QString::number(population())).append(" | ");
        result.append(QString::number(area())).append(" | ");
        result.append(region()).append(" | ");
        result.append(isCapital() ? "true" : "false").append(" | ");
        result.append(QString("%1 | %2 | %3")
                          .arg(mayoralElection(0))
                          .arg(mayoralElection(1))
                          .arg(mayoralElection(2)));
        return result;
    }

private:
    struct Data
    {
        int population;
        double area;
        QChar region;
        bool isCapital;
        QString name;
        long long mayoralElections[3];
    };
    Data data;
};

#endif // TOWN_H