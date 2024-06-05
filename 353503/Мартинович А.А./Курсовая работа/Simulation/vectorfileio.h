#ifndef VECTORFILEIO_H
#define VECTORFILEIO_H

#include <QFile>
#include <QDataStream>
#include <QVector>

class VectorFileIO {
public:
    static bool writeToFile(const QVector<QVector<int>>& myVector, const QString& fileName);

    static bool readFromFile(QVector<QVector<int>>& myVector, const QString& fileName);
};

#endif // VECTORFILEIO_H
