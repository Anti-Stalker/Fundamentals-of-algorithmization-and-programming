#ifndef WORKER_H
#define WORKER_H

struct Worker {
    int age;
    char gender; //M - man and W - woman
    bool works=false; //работает или нет в данный момент
    double salary;

    char* name;
    int vacationDays[2];

};

#endif // WORKER_H
