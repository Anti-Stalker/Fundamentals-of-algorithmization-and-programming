#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "employee.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Employee employee1 = {
        1001,
        3500.0,
        "Manager",
        true
    };



    Employee employee2;
    employee2.id = 1002;
    employee2.salary = 4500.0;
    strcpy(employee2.position, "Engineer");
    employee2.isFullTime = true;

    Employee employee3;
    Employee* employeePtr = &employee3;
    employeePtr->id = 1003;
    employeePtr->salary = 5500.0;
    strcpy(employeePtr->position, "Manager");
    employeePtr->isFullTime = true;

    Employee employee4;
    Employee& employeeRef = employee4;
    employeeRef.id = 1004;
    employeeRef.salary = 6500.0;
    strcpy(employeeRef.position, "Marketer");
    employeeRef.isFullTime = true;

    printStruct(employee1.id, employee1.salary, employee1.position, employee1.isFullTime);
    printStruct(employee2.id, employee2.salary, employee2.position, employee2.isFullTime);
    printStruct(employeePtr->id, employeePtr->salary, employeePtr->position, employeePtr->isFullTime);
    printStruct(employeeRef.id, employeeRef.salary, employeeRef.position, employeeRef.isFullTime);

    connect(ui->enter_button, &QPushButton::clicked, this, &MainWindow::createInUi);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createInUi()
{
    Employee employee5;
    employee5.id = ui->id_box->value();
    employee5.salary = ui->salary_box->value();
    strcpy(employee5.position, ui->position_box->currentText().toStdString().c_str());
    employee5.isFullTime = ui->full_time_box->isChecked();
    printStruct(employee5.id, employee5.salary, employee5.position, employee5.isFullTime);
}

