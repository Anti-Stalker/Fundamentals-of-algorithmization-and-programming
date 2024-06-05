//
// Created by volodya-petarda on 4/7/24.
//

#ifndef NEURALNETWORK_NEURALMINIMAXMOVEPREDICTOR_H
#define NEURALNETWORK_NEURALMINIMAXMOVEPREDICTOR_H
#include "MinimaxMovePredictor.h"
#include <set>
#include "../neural_network/BaseNeuralNetwork.h"

class NeuralMinimaxMovePredictor : public MinimaxMovePredictor{
public:
    NeuralMinimaxMovePredictor(BaseNeuralNetwork *predictor, BaseNeuralNetwork *evaluator);
protected:
    std::vector<std::string> getMoves(Board board) override;
    float evaluateBoard(Board board) override;
private:
    BaseNeuralNetwork *predictor;
    BaseNeuralNetwork *evaluator;
};


#endif //NEURALNETWORK_NEURALMINIMAXMOVEPREDICTOR_H
