#include "random.h"

RandomNumberGenerator::RandomNumberGenerator(int maxStat, int dialogStep)
{
    // Инициализация генератора текущим временем
    seed = QDateTime::currentMSecsSinceEpoch() & 0xFFFFFFFF;
    c = 1 << maxStat;

    // Если dialogStep четное, увеличиваем семя
    if (dialogStep % 2 == 0) {
        seed += dialogStep;
    }
}

int RandomNumberGenerator::generate(int min, int max) {
    // Обновление семени
    seed = (seed * a + c) & m;

    // Преобразование семени в число в заданном диапазоне
    int range = max - min + 1;
    int randomNumber = (seed % range) + min;

    return randomNumber;
}
