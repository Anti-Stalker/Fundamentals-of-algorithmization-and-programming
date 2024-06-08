//
// Created by u on 25.05.24.
//

#include "Expression.h"

#ifndef TASK3_NUMBER_H
#define TASK3_NUMBER_H


class Number : public Expression
{
private:
    double val;

public:
    double evaluate() override;
    explicit Number(double val);
};


#endif //TASK3_NUMBER_H
