//
// Created by volodya-petarda on 4/7/24.
//

#include "NeuralMinimaxMovePredictor.h"
#include "../linear_algebra/CPULinearAlgebra.h"

std::vector<std::string> NeuralMinimaxMovePredictor::getMoves(Board board) {

    float *x = board.extendedEncodeBoard();
    float *chances = predictor->predict(x);
    std::vector<std::string> result;
    std::set<std::string> inResult;
    const int UND = 1000, MOVES = 1000;
    for(int i = 0; i < UND; i++){
        int ind = getMaxIndex(chances, 64 * 64);
        if(chances[ind] < 0.001f)
            break;
        chances[ind] = 0;
        std::string move = Board::numberToUci(ind);
        if(!board.getIsWhiteMove())
            move = Board::reverseUci(move);
        if(board.isPossibleMove(move)){
            result.push_back(move);
            inResult.insert(move);
            if(result.size() >= MOVES)
                break;
        }
    }

    for(int i = 0; i < 64 * 64; i++){
        std::string move = Board::numberToUci(i);
        if(!board.isPossibleMove(move))
            continue;
        if(inResult.contains(move))
            continue;
        result.push_back(move);
    }

    delete[] x;
    delete[] chances;
    return result;
}

NeuralMinimaxMovePredictor::NeuralMinimaxMovePredictor(BaseNeuralNetwork *predictor, BaseNeuralNetwork *evaluator) {
    this->predictor = predictor;
    this->evaluator = evaluator;
}

float NeuralMinimaxMovePredictor::evaluateBoard(Board board) {
//    return MinimaxMovePredictor::evaluateBoard(board);

    float *x = board.extendedEncodeBoard();
    float *ev = evaluator->predict(x);
    float res = ev[0];
    delete[] x;
    delete[] ev;
    if(!board.getIsWhiteMove())
        res = 1 - res;
//    std::cout<<board.getIsWhiteMove()<<' '<<res<<'\n';
//    board.printBoard();
    return res;
}
