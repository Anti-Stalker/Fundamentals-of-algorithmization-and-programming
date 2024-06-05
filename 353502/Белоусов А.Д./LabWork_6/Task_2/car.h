#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <array>
#include <QString>

struct Car
{
    int _maxAcceleration;
    double _velocity;
    char _acceleration;
    bool _isMoving;
    std::array<std::string, 2> _namesOfPassengers;
    std::array<int, 2> _agesOfPassengers;

    std::string to_string(char separator = '_')
    {
        std::string answer;
        answer.append(std::to_string(_maxAcceleration).c_str());
        answer.push_back(separator);
        answer.append(std::to_string(_velocity).c_str());
        answer.push_back(separator);
        answer.append(std::to_string(_acceleration).c_str());
        answer.push_back(separator);
        answer.append(std::to_string(_isMoving).c_str());
        answer.push_back(separator);
        for (int i = 0;i<2;++i)
        {
            answer.append(_namesOfPassengers[i]);
            answer.push_back(separator);
        }
        for (int i = 0;i<2;++i)
        {
            answer.append(std::to_string(_agesOfPassengers[i]).c_str());
            answer.push_back(separator);
        }

        answer[answer.find(",")] = '.';

        return answer;
    }

    void from_string(std::string str, char separator = '_')
    {
        _maxAcceleration = QString::fromStdString(str.substr(0, str.find(separator))).toInt();
        str.erase(0, str.find(separator) + 1);
        _velocity = QString::fromStdString(str.substr(0, str.find(separator))).toDouble();
        str.erase(0, str.find(separator) + 1);
        _acceleration = QString::fromStdString(str.substr(0, str.find(separator))).toInt();
        str.erase(0, str.find(separator) + 1);
        _isMoving = QString::fromStdString(str.substr(0, str.find(separator))).toInt();
        str.erase(0, str.find(separator) + 1);
        _namesOfPassengers[0] = str.substr(0, str.find(separator)).c_str();
        str.erase(0, str.find(separator) + 1);
        _namesOfPassengers[1] = str.substr(0, str.find(separator)).c_str();
        str.erase(0, str.find(separator) + 1);
        _agesOfPassengers[0] = QString::fromStdString(str.substr(0, str.find(separator))).toInt();
        str.erase(0, str.find(separator) + 1);
        _agesOfPassengers[1] = QString::fromStdString(str.substr(0, str.find(separator))).toInt();
        str.erase(0, str.find(separator) + 1);
    }
};

#endif // CAR_H
