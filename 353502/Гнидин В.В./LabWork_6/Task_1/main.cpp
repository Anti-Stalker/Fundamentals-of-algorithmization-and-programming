#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

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

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Computer Information");

    QLineEdit idLineEdit;
    QLineEdit lengthLineEdit;
    QLineEdit typeLineEdit;
    QLineEdit isBrokenLineEdit;
    QLineEdit nameLineEdit;
    QLineEdit numberOfFiksikesLineEdit;

    QPushButton submitButton("Submit");

    QFormLayout formLayout;
    formLayout.addRow("ID:", &idLineEdit);
    formLayout.addRow("Size:", &lengthLineEdit);
    formLayout.addRow("Type:", &typeLineEdit);
    formLayout.addRow("Is broken (1 for yes, 0 for no):", &isBrokenLineEdit);
    formLayout.addRow("Name:", &nameLineEdit);
    formLayout.addRow("Number of fiksikes:", &numberOfFiksikesLineEdit);
    formLayout.addRow(&submitButton);

    QLabel computer1Label;
    QLabel computer2Label;
    QLabel computer3Label;
    QLabel computer4Label;
    QLabel computer5Label;

    formLayout.addRow("Computer 1:", &computer1Label);
    formLayout.addRow("Computer 2:", &computer2Label);
    formLayout.addRow("Computer 3:", &computer3Label);
    formLayout.addRow("Computer 4:", &computer4Label);
    formLayout.addRow("Computer 5:", &computer5Label);

    window.setLayout(&formLayout);

    QObject::connect(&submitButton, &QPushButton::clicked, [&]() {
        Computer newComputer;
        newComputer.computerId = idLineEdit.text().toInt();
        newComputer.computerSize = lengthLineEdit.text().toDouble();
        newComputer.computerType = typeLineEdit.text().isEmpty() ? '\0' : typeLineEdit.text().at(0).toLatin1();
        newComputer.isBroken = isBrokenLineEdit.text().toInt();
        qstrcpy(newComputer.computerName, nameLineEdit.text().toUtf8().constData());
        newComputer.numberOfFiksikes = numberOfFiksikesLineEdit.text().toInt();

        computer1Label.setText(QString::number(newComputer.computerId) + " | " + QString::number(newComputer.computerSize) + " | " +
                               newComputer.computerType + " | " + (newComputer.isBroken ? "true" : "false") + " | " +
                               QString(newComputer.computerName) + " | " + QString::number(newComputer.numberOfFiksikes));

        Computer ship2;
        ship2.computerId = 2;
        ship2.computerSize = 100;
        ship2.computerType = 'A';
        ship2.isBroken = false;
        qstrcpy(ship2.computerName, "Some laptop");
        ship2.numberOfFiksikes = 30;

        computer2Label.setText(QString::number(ship2.computerId) + " | " + QString::number(ship2.computerSize) + " | " +
                               ship2.computerType + " | " + (ship2.isBroken ? "true" : "false") + " | " +
                               QString(ship2.computerName) + " | " + QString::number(ship2.numberOfFiksikes));

        Computer ship3;
        ship3.computerId = 3;
        ship3.computerSize = 1500;
        ship3.computerType = 'B';
        ship3.isBroken = true;
        qstrcpy(ship3.computerName, "Some good computer");
        ship3.numberOfFiksikes = 1000000;

        computer3Label.setText(QString::number(ship3.computerId) + " | " + QString::number(ship3.computerSize) + " | " +
                               ship3.computerType + " | " + (ship3.isBroken ? "true" : "false") + " | " +
                               QString(ship3.computerName) + " | " + QString::number(ship3.numberOfFiksikes));

        Computer ship4;
        Computer *ship4Ptr = &ship4;
        ship4Ptr->computerId = 4;
        ship4Ptr->computerSize = 1;
        ship4Ptr->computerType = 'A';
        ship4Ptr->isBroken = true;
        qstrcpy(ship4Ptr->computerName, "Compter without fik :(");
        ship4Ptr->numberOfFiksikes = 0;

        computer4Label.setText(QString::number(ship4Ptr->computerId) + " | " + QString::number(ship4Ptr->computerSize) + " | " +
                               ship4Ptr->computerType + " | " + (ship4Ptr->isBroken ? "true" : "false") + " | " +
                               QString(ship4Ptr->computerName) + " | " + QString::number(ship4Ptr->numberOfFiksikes));

        Computer ship5;
        Computer &ship5Ref = ship5;
        ship5Ref.computerId = 5;
        ship5Ref.computerSize = 120;
        ship5Ref.computerType = 'D';
        ship5Ref.isBroken = false;
        qstrcpy(ship5Ref.computerName, "Comp with neg fiks");
        ship5Ref.numberOfFiksikes = -100;

        computer5Label.setText(QString::number(ship5Ref.computerId) + " | " + QString::number(ship5Ref.computerSize) + " | " +
                               ship5Ref.computerType + " | " + (ship5Ref.isBroken ? "true" : "false") + " | " +
                               QString(ship5Ref.computerName) + " | " + QString::number(ship5Ref.numberOfFiksikes));
    });

    window.show();

    return app.exec();
}
