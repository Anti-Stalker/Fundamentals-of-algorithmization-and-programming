#ifndef STATE_H
#define STATE_H

#endif // STATE_H

struct State
{
    int population;
    double area;
    char name[20];
    bool independent;
    char currency[4];
    static constexpr int firstAndLastState[2] = {0, 2011};
};
