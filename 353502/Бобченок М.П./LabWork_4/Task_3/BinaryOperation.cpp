//
// Created by u on 25.05.24.
//

#include "BinaryOperation.h"

BinaryOperation::BinaryOperation()
{
    left = new Expression;
    right = new Expression;
}

double BinaryOperation::evaluate()
{
    double l = left->evaluate();
    double r = right->evaluate();

    switch(operation)
    {
        case(PLUS):
            return l + r;

        case(MINUS):
            return l - r;

        case(MULTIPLY):
            return l * r;

        case(DIVIDE):
            return l / r;
    }
}

BinaryOperation::BinaryOperation(Expression *left, Operation operation, Expression *right) : left(left), right(right), operation(operation) {}

