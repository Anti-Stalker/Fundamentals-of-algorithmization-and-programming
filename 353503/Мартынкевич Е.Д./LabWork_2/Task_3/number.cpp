#include "number.h"

Number::Number(double numb)
{
    this->numb = numb;
}

double Number::evaluate()
{
    return this->numb;
}
