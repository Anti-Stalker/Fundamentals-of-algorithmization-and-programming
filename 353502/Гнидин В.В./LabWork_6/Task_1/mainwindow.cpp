#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QLabel>

struct Computer {
    int computerId;
    double computerSize;
    char computerType;
    bool isBroken;
    static const int maxNameLength = 20;
    char computerName[maxNameLength];
    static const int maxCrewSize = 100;
    int numberOfFiksikes;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    setWindowTitle("Computer Information");

    QLineEdit idLineEdit;
    QLineEdit lengthLineEdit;
    QLineEdit typeLineEdit;
    QLineEdit dockedLineEdit;
    QLineEdit nameLineEdit;
    QLineEdit crewLineEdit;

    QPushButton submitButton("Submit");

    QFormLayout formLayout;
    formLayout.addRow("ID:", &idLineEdit);
    formLayout.addRow("Size:", &lengthLineEdit);
    formLayout.addRow("Type:", &typeLineEdit);
    formLayout.addRow("Is broken (1 for yes, 0 for no):", &dockedLineEdit);
    formLayout.addRow("Name:", &nameLineEdit);
    formLayout.addRow("Number of fiksikes:", &crewLineEdit);
    formLayout.addRow(&submitButton);

    QLabel computer1Label;
    QLabel ship2Label;
    QLabel ship3Label;
    QLabel ship4Label;
    QLabel ship5Label;

    formLayout.addRow("Computer 1:", &computer1Label);
    formLayout.addRow("Computer 2:", &ship2Label);
    formLayout.addRow("Computer 3:", &ship3Label);
    formLayout.addRow("Computer 4:", &ship4Label);
    formLayout.addRow("Computer 5:", &ship5Label);

    setLayout(&formLayout);

    QObject::connect(&submitButton, &QPushButton::clicked, [&]() {
        Computer newShip;
        newShip.computerId = idLineEdit.text().toInt();
        newShip.computerSize = lengthLineEdit.text().toDouble();
        newShip.computerType = typeLineEdit.text().isEmpty() ? '\0' : typeLineEdit.text().at(0).toLatin1();
        newShip.isBroken = dockedLineEdit.text().toInt();
        qstrcpy(newShip.computerName, nameLineEdit.text().toUtf8().constData());
        newShip.numberOfFiksikes = crewLineEdit.text().toInt();

        computer1Label.setText(QString::number(newShip.computerId) + " | " + QString::number(newShip.computerSize) + " | " +
                               newShip.computerType + " | " + (newShip.isBroken ? "true" : "false") + " | " +
                               QString(newShip.computerName) + " | " + QString::number(newShip.numberOfFiksikes));

        Computer ship2;
        ship2.computerId = 2;
        ship2.computerSize = 100.2;
        ship2.computerType = 'B';
        ship2.isBroken = false;
        qstrcpy(ship2.computerName, "Sea Voyager");
        ship2.numberOfFiksikes = 30;

        ship2Label.setText(QString::number(ship2.computerId) + " | " + QString::number(ship2.computerSize) + " | " +
                           ship2.computerType + " | " + (ship2.isBroken ? "true" : "false") + " | " +
                           QString(ship2.computerName) + " | " + QString::number(ship2.numberOfFiksikes));

        Computer ship3;
        ship3.computerId = 3;
        ship3.computerSize = 85.6;
        ship3.computerType = 'C';
        ship3.isBroken = true;
        qstrcpy(ship3.computerName, "Atlantis");
        ship3.numberOfFiksikes = 45;

        ship3Label.setText(QString::number(ship3.computerId) + " | " + QString::number(ship3.computerSize) + " | " +
                           ship3.computerType + " | " + (ship3.isBroken ? "true" : "false") + " | " +
                           QString(ship3.computerName) + " | " + QString::number(ship3.numberOfFiksikes));

        Computer ship4;
        Computer *ship4Ptr = &ship4;
        ship4Ptr->computerId = 4;
        ship4Ptr->computerSize = 80.3;
        ship4Ptr->computerType = 'A';
        ship4Ptr->isBroken = true;
        qstrcpy(ship4Ptr->computerName, "Oceanic");
        ship4Ptr->numberOfFiksikes = 70;

        ship4Label.setText(QString::number(ship4Ptr->computerId) + " | " + QString::number(ship4Ptr->computerSize) + " | " +
                           ship4Ptr->computerType + " | " + (ship4Ptr->isBroken ? "true" : "false") + " | " +
                           QString(ship4Ptr->computerName) + " | " + QString::number(ship4Ptr->numberOfFiksikes));

        Computer ship5;
        Computer &ship5Ref = ship5;
        ship5Ref.computerId = 5;
        ship5Ref.computerSize = 120.8;
        ship5Ref.computerType = 'D';
        ship5Ref.isBroken = false;
        qstrcpy(ship5Ref.computerName, "Starlight");
        ship5Ref.numberOfFiksikes = 55;

        ship5Label.setText(QString::number(ship5Ref.computerId) + " | " + QString::number(ship5Ref.computerSize) + " | " +
                           ship5Ref.computerType + " | " + (ship5Ref.isBroken ? "true" : "false") + " | " +
                           QString(ship5Ref.computerName) + " | " + QString::number(ship5Ref.numberOfFiksikes));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
