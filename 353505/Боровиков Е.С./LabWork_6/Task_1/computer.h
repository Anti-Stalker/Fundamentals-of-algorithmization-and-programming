#ifndef COMPUTER_H
#define COMPUTER_H

#include <QChar>

struct Computer
{
    int ramSizeGB;                         // Хранит объем оперативной памяти в гигабайтах
    double cpuSpeedGHz;                    // Хранит скорость процессора в гигагерцах
    char brandInitial;                     // Хранит начальную букву бренда компьютера
    bool isLaptop;                         // Хранит информацию о том, является ли компьютер ноутбуком (true/false)
    static QChar modelName[50];             // Хранит название модели компьютера
    static int performanceScores[10];      // Хранит оценки производительности компьютера
};

#endif // COMPUTER_H
