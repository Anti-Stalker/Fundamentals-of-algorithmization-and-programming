//
// Created by u on 23.02.24.
//
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

#include "matrixMath/matrixMath.h"
#pragma once

#ifndef N_NETWORK_H
#define N_NETWORK_H


class Network
{
private:
    static const int TYPE = 0;
    constexpr static const float L_RELU_DOWN_COEF = 0.01;
    constexpr static const float L_RELU_UP_COEF = 1;

    std::vector<int> layers = {64, 128, 32};
    std::vector<int> activateType = {0, 2, 2};
    std::vector<int> dropoutPercentOfZeros = {0, 20, 0};
    float alpha = 1;
    int packetSize = 5;
    bool dropoutUsage = true;

    int t = 0;
    float error = 0;
    int errorDerivativeType = 2;

    std::vector<std::vector<float> > a, b;
    std::vector<std::vector<std::vector<float> > > weights;
    std::vector<std::vector<int> > dropout;
    std::vector<std::vector<float> > db, delta;
    std::vector<std::vector<std::vector<float> > > dw;

    void initialize();

    static void activate(float &x, int type = TYPE);
    static void activate(std::vector<float> &x, int type = TYPE);
    static void activateDerivative(float &x, float &y, int type = TYPE);
    static void activateDerivative(std::vector<float> &x, std::vector<float> &y, int type = TYPE);

    static void errorDerivative(std::vector<float> &x, std::vector<float> &y, int type);

    void propagate();
    void backPropagation(std::vector<float> &y);
    void correct();

public:
    void setAlpha(float _alpha);
    void setPacketSize(int _packetSize);
    void setDropoutUsage(bool _dropoutUsage);
    void setError(float _error);
    void setLayers(std::vector<int> &_layers);
    void setLayer(int layer, int size);
    void setActivateType(std::vector<int> &_activateType);
    void setActivateType(int layer, int _activateType);
    void setDropoutPercentOfZeros(std::vector<int> &_dropoutPercentOfZeros);
    void setDropoutPercentOfZeros(int layer, int percent);

    void fit(std::vector<float> &start);
    void printW();
    void printA();
    void printB();

    int predict(std::vector<float> &start, int num);
    float train(std::vector<float> &start, std::vector<float> &y);
    float get(int num);

    int getDropoutUsage();
    int getSize();
    int getStartSize();
    int getOutputSize();

    void save(const std::string& s = "fastSave");
    void load(std::string s);
    void otupit();

    Network(std::string s = "fastSave");
    Network(std::vector<int>& layers);
};


#endif //N_NETWORK_H
