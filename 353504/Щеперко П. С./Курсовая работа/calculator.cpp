#include "calculator.h"

Calculator::Calculator()
    : velocity(0)
    , ballisticCoefficient(0)
    , diameter(0)
    , weight(0)
    , airDensity(0)
    , windSpeed(0)
    , range(0)
    , rows(0)
    , bulletConditions(0)
{}

inline double Calculator::BulletDrop(double timeOfFlight)
{
    return G * pow(timeOfFlight, 2) / 2.0;
}

inline double Calculator::BulletEnergy()
{
    return weight * pow(velocity, 2) / 2.0;
}

inline double Calculator::Acceleration(double RungeKuttaStep = 0)
{
    //уравнение сопротивления воздуха, использованное
    //для вычисления ускорения пули по закону Ньютона
    const double S = M_PI * pow(((diameter) / 2.0), 2);
    return -0.5 * airDensity * ballisticCoefficient * S * pow(velocity + RungeKuttaStep, 2)
           / (weight);
}

inline void Calculator::UpdateBulletConstant()
{
    //15 является базовой константой для данного
    //эмпирического метода полученного с использованием
    //пули .308 массой  от 10,2 до 13,6 (11,9 среднее)
    bulletConstant = 15 * (weight * 1000 / 11.9);
}

inline void Calculator::CalculateDeviation()
{
    UpdateBulletConstant();
    const double yardsHudredsDistance = range * YARDS_IN_METERS / 100;
    const double milesPerHourWindSpeed = windSpeed * MILES_PER_HOUR_IN_METERS_PER_SECOND;
    const double MOA = yardsHudredsDistance * windRatio * milesPerHourWindSpeed / bulletConstant;
    //2.9089 перевод MOA в сантиметры
    deviation = MOA * MILLIRADIANS_IN_MOA * range / 100;
}

inline double Calculator::UpdateVelocityEuler()
{
    //использование метода Эйлера для решения
    //дифференциального уравнения вида
    //dv = a(v) * dt
    velocity += Acceleration() * dt;
    return velocity;
}

inline void Calculator::UpdateVelocityRungeKutta()
{
    //использование метода Рунге-Кутта для решения
    //дифференциального уравнения вида
    //dv = a(v) * dt
    double k1 = Acceleration() * dt;
    double k2 = Acceleration(k1 / 2.0) * dt;
    double k3 = Acceleration(k2 / 2.0) * dt;
    double k4 = Acceleration(k3) * dt;
    velocity += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
}

inline double Calculator::DistanceTrapezoid()
{
    double oldVelocity = velocity;
    UpdateVelocityRungeKutta();
    return (oldVelocity + velocity) / 2.0 * dt;
}

inline double Calculator::DistanceSimpson()
{
    double old_velocity = velocity;
    double mid_velocity = velocity + Acceleration() / 2 * dt;
    UpdateVelocityEuler();
    return dt / 6 * (old_velocity + 4 * mid_velocity + velocity);
}

inline double Calculator::DistanceRungeKutta()
{
    double oldVelocity = velocity;

    double k1 = oldVelocity * dt;
    double k2 = (oldVelocity + k1 / 2) * dt;
    double k3 = (oldVelocity + k2 / 2) * dt;
    double k4 = (oldVelocity + k3) * dt;

    UpdateVelocityRungeKutta();

    return (k1 + 2*k2 + 2*k3 + k4) / 6;
}

inline double Calculator::CalculateDistance(IntegrationMethod integrationMethod)
{
    switch (integrationMethod) {
    case Trapezoid:
        return DistanceTrapezoid();
        break;
    case Simpson:
        return DistanceSimpson();
        break;
    case Runge_Kutta:
        return DistanceRungeKutta();
        break;
    }
}

void Calculator::CalculateBulletConditions(IntegrationMethod integrationMethod)
{
    bulletConditions.resize(rows);
    distance.clear();
    drop.clear();
    const double rowDistatance = static_cast<double> (range) / rows;
    double distance = 0;
    double drop = 0;
    double time = 0;
    for (int row = 1; row <= rows;) {
        //проверка на
        //текущее расстояние ~ расстояние текущего ряда таблицы
        if (distance > range - (rowDistatance * (rows - row))) {
            //заполнение состояния пули
            bulletConditions[row - 1].distance = rowDistatance * row;
            bulletConditions[row - 1].velocity = velocity;
            bulletConditions[row - 1].energy = BulletEnergy();
            bulletConditions[row - 1].drop = drop
                                             * 100.0; //умножение на 100 для перевода в сантиметры
            bulletConditions[row - 1].timeOfFlight = time;
            ++row;
        }

        this->distance.push_back(distance);
        this->drop.push_back(-drop);

        distance += CalculateDistance(integrationMethod);
        drop = BulletDrop(time);
        time += dt;
    }
    CalculateDeviation();
}