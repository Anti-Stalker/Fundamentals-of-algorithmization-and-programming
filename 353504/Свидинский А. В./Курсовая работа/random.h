#ifndef RANDOM_H
#define RANDOM_H

#include <QDateTime>

class MainWindow;

class RandomNumberGenerator {
public:
    RandomNumberGenerator(int maxStat, int dialogStep);
    int generate(int min, int max);

private:
    unsigned int seed; // Семя генератора
    const unsigned int a = 1103515245; // Множитель
    unsigned int c; // Приращение
    const unsigned int m = 0x7FFFFFFF; // Модуль
};

#endif // RANDOM_H
