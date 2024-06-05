//
// Created by volodya-petarda on 3/28/24.
//

#ifndef NEURALNETWORK_GPUNEURALNETWORK_H
#define NEURALNETWORK_GPUNEURALNETWORK_H

#include <iostream>
#include "BaseNeuralNetwork.h"
#include "cublas_v2.h"
#include "../linear_algebra/GPULinearAlgebra.h";

class GPUNeuralNetwork : public BaseNeuralNetwork{
public:
    GPUNeuralNetwork();
    GPUNeuralNetwork(std::vector<int> sizes);

    void printA() override;
    void printB() override;
    void printWeights() override;
    void setActivationType(const std::vector<ActivationType> &types) override;
    void setErrorActivationType(ActivationType activationType) override;
    std::pair<float, bool> train(float *x, float *y, float alpha = 1.0, int batchSize = 1) override;
    float* predict(float *x) override;
    void save(const std::string& path = "save.txt") override;
    void load(const std::string& path = "save.txt") override;
    void setInput(float *x);
    void forwardPropagation();
private:
    int batchStep = 0;
    int layers;
    std::vector<int> sizes;
    ActivationType errorType;
    std::vector<ActivationType> activationType;
    float **weights, **deltWeights;
    float **a, **b, **delt, **deltB;
    float *y;

    void createArrays();
    void backwardPropagation(float *y);
    void doUpdate(float alpha);
};


#endif //NEURALNETWORK_GPUNEURALNETWORK_H
