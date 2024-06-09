#ifndef FILEINPUTOUTPUT_H
#define FILEINPUTOUTPUT_H

#include <QString>
#include <QVector>
#include <Plant.h>

static const QString pathToSimpleParagraph
    = "/Users/egortishkevic/LabWork_6/Files/TishkevichLab6.txt";
static const QString pathToArray
    = "/Users/egortishkevic/LabWork_6/Files/TishkevichLab6_0.txt";
static const QString pathToTxtStruct
    = "/Users/egortishkevic/LabWork_6/Files/TishkevichLab6_1.txt";
static const QString pathToBinStruct
    = "/Users/egortishkevic/LabWork_6/Files/TishkevichLab6_2.bin";
static const QString pathToListSentences
    = "/Users/egortishkevic/LabWork_6/Files/TishkevichLab6_3.txt";

class FileInputOutput
{
public:
    static void writeToFile(const QString &fileName, const QString &text);
    static QString readFromFile(const QString &fileName);

    static void writeArrayToFile(const QString &fileName, const QVector<float> &arr);
    static QString readArrayFromFile(const QString &fileName);

    static void writeStructToTxtFile(const QString &fileName, const Plant &plant);
    static QVector<Plant> readStructFromTxtFile(const QString &fileName);

    static void writeStructToBinFile(const QString &fileName, const Plant &plant);
    static QVector<Plant> readStructFromBinFile(const QString &fileName);

    static void appendSentenceToFile(const QString &fileName, const QString &text);
};

#endif // FILEINPUTOUTPUT_H
