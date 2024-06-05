#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <array>

struct Car
{
    int _maxAcceleration;
    double _velocity;
    char _acceleration;
    bool _isMoving;
    std::array<const char*, 2> _namesOfPassengers;
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

        return answer;
    }
};

#endif // CAR_H
