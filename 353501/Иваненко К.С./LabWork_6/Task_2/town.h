#pragma once

#define TOWN_H
#ifdef TOWN_H

#include <QString>
#include <qtmetamacros.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class Town
{
public:
    Town() = default;
    Town(std::string create)
    {
        using std::istringstream;
        istringstream ss(create);
        std::string tmp;

        std::getline(ss, tmp, '|');
        if (tmp.size() > 50)
        {
            throw std::invalid_argument("Name is too big");
            return;
        }

        for (int i = 0; i < tmp.size(); ++i)
        {
            data.name[i] = tmp[i];
        }
        for (int i = tmp.size(); i < 50; ++i)
        {
            data.name[i] = QChar(0);
        }

        std::getline(ss, tmp, '|');
        data.population = std::stoi(tmp);
        if (!data.population)
        {
            throw std::invalid_argument("Invalid size");
        }

        std::getline(ss, tmp, '|');
        if (tmp.size() != 3 || tmp[0] != ' ' || tmp[2] != ' ')
        {
            throw std::invalid_argument("Wrong region");
        }
        data.region = tmp[1];

        std::getline(ss, tmp, '|');
        if (tmp != " true" && tmp != " false" && tmp != " +" && tmp != " -" &&
            tmp != " 0" && tmp != " 1")
        {
            throw std::invalid_argument("Wrong Is Capital Value: " + tmp);
        }
        data.isCapital = (tmp == " true" || tmp == " 1" || tmp == " +");

        if (!ss)
        {
            throw std::invalid_argument("Bad mayor selection");
        }
    }

    std::string to_string(QChar separator)
    {
        using std::ostringstream;
        ostringstream os{};

        os << QString(&data.name[0]).toStdString();
        os << ' ' << QString(separator).toStdString() << ' ';
        os << std::setprecision(5) << data.population;
        os << ' ' << QString(separator).toStdString() << ' ';
        os << QString(data.region).toStdString();
        os << ' ' << QString(separator).toStdString() << ' ';
        os << (data.isCapital ? '+' : '-');

        return os.str();
    }

    ~Town(){};

private:
    struct Data
    {
        int population;
        QChar region;
        bool isCapital;
        QChar name[50];
    };
    Data data;
};

#endif // TOWN_H