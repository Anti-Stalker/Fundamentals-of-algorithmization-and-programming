#include "coinsimulation.h"

#include <cmath>

CoinSimulation::CoinSimulation() : gen(std::random_device()()) {}

CoinSimulation::~CoinSimulation() {}

double CoinSimulation::calculateWeightedAngle(double angle, double force, double mass) {
    // Ускорение свободного падения, м/с^2
    double gravity = 9.81;

    // Момент инерции, кг * м^2
    double momentOfInertia = mass * gravity * 0.5; // Применяем эмпирический коэффициент для примера

    // Момент силы, Н * м
    double torque = force * 0.5; // Применяем эмпирический коэффициент для примера

    // Угловое ускорение, рад/с^2
    double angularAcceleration = torque / momentOfInertia;

    // Шаг интегрирования, секунды
    double timeStep = 0.01;

    // Интегрируем угловое ускорение для получения конечного угла
    double finalAngle = angle + angularAcceleration * timeStep + 0.5 * angularAcceleration * timeStep * timeStep;

    // Обеспечиваем, чтобы угол был в пределах от 0 до 360 градусов
    while (finalAngle > 360.0) {
        finalAngle -= 360.0;
    }
    while (finalAngle < 0.0) {
        finalAngle += 360.0;
    }

    return finalAngle;
}

double CoinSimulation::simulateCoinTossProbability(double tilt, int numTosses, double force, double mass) {
    std::uniform_real_distribution<> dis(0.0, 1.0);

    int headsCount = 0;
    for (int i = 0; i < numTosses; ++i) {
        double randomNumber = dis(gen);
        double weightedAngle = calculateWeightedAngle(tilt, force, mass);
        double probabilityOfHeads = 0.5 + 0.5 * cos(weightedAngle * M_PI / 180.0);
        if (randomNumber < probabilityOfHeads)
            ++headsCount;
    }

    return static_cast<double>(headsCount) / numTosses;
}


