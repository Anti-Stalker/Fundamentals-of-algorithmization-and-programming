//
// Created by u on 27.02.24.
//

#include <ctime>
#include <deque>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <unordered_map>
#include "../Network/Network.h"
#include "../settings/paths.h"


#pragma once

#ifndef N_MENU_H
#define N_MENU_H

void parse();

void poschitatVocabular();

void read(std::string s, std::unordered_map<std::string, int> &a);

void read(std::string s, std::unordered_map<int, std::string> &a);

void refactor();

void refactorStringToDeque(std::string s, std::deque<std::string> &a);

void otupit(Network &n);

void predict(Network &n, std::string adam, int num, int kol = 20);

void testAuto(Network &n);

void train(Network &n);

void setAlpha(Network &n);

void setPacketSize(Network &n);

void setLayers(Network &n);

void setLayer(Network &n);

void setActivation(Network &n);

void setActivations(Network &n);

void outputWeights(Network &n);

void outputA(Network &n);

void setDropoutUsage(Network &n);

void setDropoutPercentOfZeros(Network &n);

void setDropoutPercentOfZerosOnLayer(Network &n);

void makeLayerConvolutional(Network &n);

void fastSave(Network &n);

void save(Network &n);

void load(Network &n);

#endif //N_MENU_H
