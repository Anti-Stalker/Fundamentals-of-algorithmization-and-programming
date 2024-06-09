#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QStringList>
#include <QFile>
#include <QTextBrowser>
#include <QTextStream>
#include <fstream>
#include <QMessageBox>
#include <QCoreApplication>
#include <QInputDialog>
#include <ship.h>
#include <structinputdialog.h>

class FileWorker
{
public:
    FileWorker(QTextBrowser*);

    QString inputText;

    const QStringList files = {"Sharafanovich.txt", "SharafanovichLab6_0.txt",
                               "SharafanovichLab6_1.txt", "SharafanovichLab6_2.bin", "SharafanovichLab6_3.txt"};

    void CreateNonExistingFiles();

    void SaveTextToFile(const QString&);
    void LoadTextFromFile(const QString&);

    void SaveArrayToFile(const QString&);
    void LoadArrayFromFile(const QString&);

    void SaveStructToFile(const QString&);
    void LoadStructsFromFile(const QString&);

    void SaveStructToBinaryFile(const QString&);
    void LoadStructsFromBinaryFile(const QString&);

    void SaveSentenceToFile(const QString&);
    void LoadSentencesFromFile(const QString&);
private:
    Ship a;
    StructInputDialog* structDialog;

    QTextBrowser* output;
    QTextStream outputStream;
    QString outputText;
};

#endif // FILEWORKER_H
