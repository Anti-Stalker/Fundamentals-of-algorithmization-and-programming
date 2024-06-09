#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "iostream"

struct Employee {
    int id;
    double salary;
    char position[50];
    bool isFullTime;

    static const char positions[][50];
};

const char Employee::positions[][50] = {
    "Manager",
    "Engineer",
    "Accountant",
    "Marketer",
    "Janitor"
};


void printStruct(int id, double salary, char* position, bool isFullTime) {
    std::cout << "Employee: " << id << " | " << salary << " | " << position << " | " << (isFullTime ? "Yes" : "No") << std::endl;
}

#endif // EMPLOYEE_H
