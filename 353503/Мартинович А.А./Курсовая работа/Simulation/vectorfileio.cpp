#include "vectorfileio.h"

bool VectorFileIO::writeToFile(const QVector<QVector<int>> &myVector, const QString &fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream stream(&file);

        for (auto &v: myVector) {
            QString res = "";
            for (auto &g: v) {
                res += QString::number(g);
                res += " ";
            }
            res+='\n';
            stream << res;
        }

        file.close();
        return true;
    }
    return false;
}

bool VectorFileIO::readFromFile(QVector<QVector<int>> &myVector, const QString &fileName) {
    myVector.clear();
    int i = 0;

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream stream(&file);
        while (!stream.atEnd()) {
            QVector<int> v;
            myVector.push_back(v);
            QString value;
            stream >> value;
            QStringList numberList = value.split(" ");
            for (const QString& num : numberList) {
                    bool ok;
                    if (num == '\n') continue;
                    int intValue = num.toInt(&ok);
                    if (ok) {
                        myVector[i].push_back(intValue);
                    } else {
                        return false;
                    }
                }
            i++;
        }
        file.close();
        return true;
    }
    return false;
}

