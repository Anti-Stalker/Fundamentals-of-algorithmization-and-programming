#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QFileInfo>
#include <QInputDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QTextStream>
#include <iostream>
#include <fstream>

#include "Motocycle.h"

#define FILENAME "ВалиуллинЛаб20.txt"
#define FILEFORARRAY "ВалиуллинЛаб20_0.txt"
#define FILEFORSTRUCTS "ВалиуллинЛаб20_1.txt"
#define FILEBIN "ВалиуллинЛаб20_2.bin"
#define FILESENTENSES "ВалиуллинЛаб20_3.txt"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void WriteAndSaveText();
    void ReadText();

    void WriteAndSaveArray();
    void ReadArray();

    void WriteAndSaveStructTXT();
    void ReadStructTXT();

    void WriteAndSaveStructBIN();
    void ReadStructBIN();

    void WriteAndSaveSentences();
    void ReadSentences();

    void menu();

private:
    Ui::MainWindow *ui;
    Motorcycle motorcycle;
    const QChar separator = '!';
    QString motoTypesDiscription = "Введите категорию мотоцикла (D - Дорожные мотоциклы (Street Bikes) S - Спортивные мотоциклы (Sport Bikes)"
                                   " C - Круизеры (Cruisers) E - Эндуро и Кроссовые мотоциклы (Enduro/Motocross)";
};
#endif // MAINWINDOW_H
