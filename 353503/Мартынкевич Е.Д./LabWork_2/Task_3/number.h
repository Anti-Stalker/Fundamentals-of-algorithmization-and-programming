#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
public:
    Number(double numb);
    double evaluate();

private:
    double numb;
};

#endif // NUMBER_H
