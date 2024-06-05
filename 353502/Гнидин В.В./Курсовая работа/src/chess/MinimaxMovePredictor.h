//
// Created by volodya-petarda on 4/6/24.
//

#ifndef NEURALNETWORK_MINIMAXMOVEPREDICTOR_H
#define NEURALNETWORK_MINIMAXMOVEPREDICTOR_H

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include "Board.h"

class MinimaxMovePredictor{
public:
    std::string predictMove(Board board, int DEPTH = 0, float priority = 0.001f);
protected:
    virtual std::vector<std::string> getMoves(Board board);
    virtual float evaluateBoard(Board board);
    float maxi(float alpha, float beta, Board board, int depth, float prior);
    float mini(float alpha, float beta, Board board, int depth, float prior);
};


#endif //NEURALNETWORK_MINIMAXMOVEPREDICTOR_H
