#pragma once

#include <qcontainerfwd.h>
#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include "Song.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Subtask3;
}
QT_END_NAMESPACE


class Subtask3 : public QWidget {
    Q_OBJECT
public:
    Subtask3(QWidget *parent = nullptr);
    ~Subtask3();

signals:

private slots:
    void initializeStruct();
    void saveTxt(Song song);
    void saveBin(Song song);
    void readTxt();
    void readBin();

protected:
    QVector<Song> songs;

    QString filenameTxt = "/home/marahetters/OAIP-Labs/Sem 2/Lab6/Subtask3.txt";
    QString filenameBin = "/home/marahetters/OAIP-Labs/Sem 2/Lab6/Subtask3.bin";

    Ui::Subtask3 *ui;
};
