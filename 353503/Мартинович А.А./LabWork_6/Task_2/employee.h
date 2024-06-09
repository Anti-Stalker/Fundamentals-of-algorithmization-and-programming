#ifndef EMPLOYEE_H
#define EMPLOYEE_H

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

#endif // EMPLOYEE_H
