//
// Created by volodya-petarda on 3/13/24.
//

#ifndef NEURALNETWORK_CPUNEURALNETWORK_H
#define NEURALNETWORK_CPUNEURALNETWORK_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ActivationTypes.h"
#include "../linear_algebra/CPULinearAlgebra.h"
#include "BaseNeuralNetwork.h"


class CPUNeuralNetwork : public BaseNeuralNetwork{
public:
    CPUNeuralNetwork();
    CPUNeuralNetwork(std::vector<int> sizes);

    void printA() override;
    void printB() override;
    void printWeights() override;
    void setActivationType(const std::vector<ActivationType> &types) override;
    void setErrorActivationType(ActivationType activationType) override;
    std::pair<float, bool> train(float *x, float *y, float alpha = 1.0, int batchSize = 1) override;
    float* predict(float *x) override;
    void save(const std::string& path = "save.txt") override;
    void load(const std::string& path = "save.txt") override;
private:
    int layers;
    std::vector<int> sizes;
    ActivationType errorType;
    std::vector<ActivationType> activationType;
    float ***weights, ***deltWeights;
    float **a, **b, **delt, **deltB;

    void createArrays();
    void setInput(float *x);
    void forwardPropagation();
    void backwardPropagation(float *y);
    void doUpdate(float alpha);
};


#endif //NEURALNETWORK_CPUNEURALNETWORK_H
