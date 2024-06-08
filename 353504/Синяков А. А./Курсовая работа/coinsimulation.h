#ifndef COIN_SIMULATION_H
#define COIN_SIMULATION_H

#include <random>

class CoinSimulation {
public:
    CoinSimulation();
    ~CoinSimulation();

    double simulateCoinTossProbability(double tilt, int numTosses, double force, double mass);
private:
    std::mt19937 gen;
    double calculateWeightedAngle(double angle, double force, double mass);
};

#endif // COIN_SIMULATION_H
