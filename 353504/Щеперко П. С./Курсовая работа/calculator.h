#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtMath>
#include <QVector>
#include <QtMath>
#include "constants.h"
#include "bullet/bullet_condition.h"
#include "integration_method.h"

class Calculator
{
public:
    double velocity;
    double ballisticCoefficient;
    double diameter;
    double weight;
    double airDensity;
    double windSpeed;
    double bulletConstant;
    double windRatio;
    double deviation;
    ushort range;
    ushort rows;
    QVector<BulletCondition> bulletConditions;
    QVector<double> distance;
    QVector<double> drop;

    Calculator();
    void CalculateBulletConditions(IntegrationMethod integrationMethod);

private:
    inline double BulletDrop(double timeOfFlight);
    inline double BulletEnergy();
    inline double Acceleration(double RungeKuttaStep);
    inline void UpdateBulletConstant();
    inline void CalculateDeviation();

    inline double UpdateVelocityEuler();
    inline void UpdateVelocityRungeKutta();

    inline double DistanceTrapezoid();
    inline double DistanceSimpson();
    inline double DistanceRungeKutta();
    inline double CalculateDistance(IntegrationMethod integrationMethod);
};

#endif // CALCULATOR_H
