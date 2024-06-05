//
// Created by volodya-petarda on 3/28/24.
//

#ifndef NEURALNETWORK_BASENEURALNETWORK_H
#define NEURALNETWORK_BASENEURALNETWORK_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ActivationTypes.h"
#include "../linear_algebra/CPULinearAlgebra.h"

class BaseNeuralNetwork {
public:
    virtual void printA(){};
    virtual void printB(){};
    virtual void printWeights(){};
    virtual void setActivationType(const std::vector<ActivationType> &types){};
    virtual void setErrorActivationType(ActivationType activationType){};
    virtual std::pair<float, bool> train(float *x, float *y, float alpha = 1.0, int batchSize = 1){};
    virtual float* predict(float *x){};
    virtual void save(const std::string& path = "save.txt"){};
    virtual void load(const std::string& path = "save.txt"){};
};


#endif //NEURALNETWORK_BASENEURALNETWORK_H
