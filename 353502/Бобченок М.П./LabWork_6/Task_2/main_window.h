//
// Created by u on 30.05.24.
//

#ifndef TASK2_MAIN_WINDOW_H
#define TASK2_MAIN_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QEventLoop>
#include <QTimer>
#include <QMessageBox>
#include <QScrollArea>
#include <QString>
#include <fstream>
#include <string>
#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();

private:
    const std::string absolute = "../";
    const std::string surname = absolute + "БобченокЛаб20";
    const std::string paragraphFile = surname + ".txt";
    const std::string arrayFile = surname + "_0.txt";
    const std::string structFile = surname + "_1.txt";
    const std::string binaryFile = surname + "_2.bin";
    const std::string sentenceFile = surname + "_3.txt";

    QString input();
    void print(QString);

    void printMenu();

    void writeParagraphToFile(const std::string& filename);
    void readAndPrintParagraphFromFile(const std::string& filename);
    void writeArrayToFile(const std::string& filename, char delimiter);
    void readAndPrintArrayFromFile(const std::string& filename, char delimiter);
    void writeStructToFile(const std::string& filename);
    void readAndPrintStructsFromFile(const std::string& filename);
    void writeSentenceToFile(const std::string& filename);
    void readAndPrintSentencesFromFile(const std::string& filename);

    void saveShipToBinaryFile(const std::string& filename);
    void printShipsFromBinaryFile(const std::string& filename);

    Ui::main_window *ui;

    QEventLoop loop;
    QScrollArea *scrollArea;
};


#endif //TASK2_MAIN_WINDOW_H
