#ifndef NOTEBOOK_H
#define NOTEBOOK_H

struct Notebook {
    int year;                           // Год выпуска
    double price;                       // Цена
    char model[100];                    // Модель
    bool isAvailable;                   // Доступность
    static char operatingSystem[50];    // Операционная система
    static int performanceScores[5];    // Оценки производительности
};

#endif // NOTEBOOK_H
