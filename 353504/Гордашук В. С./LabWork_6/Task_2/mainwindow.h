#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QRegularExpressionValidator>
#include <QInputDialog>
#include <QDataStream>
#include "state.h"

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
    int operation;
    QFile *file = new QFile("GordashukLab20.txt");
    QFile *file2 = new QFile("GordashukLab20_0.txt");
    QFile *file3 = new QFile("GordashukLab20_1.txt");
    QFile *file4 = new QFile("GordashukLab20_2.bin");
    QFile *file5 = new QFile("GordashukLab20_3.txt");
    void fileRead();
    void arrayFile();
    void readArray();
    void createStruct();
    void readStruct();
    void createBinStruct();
    void readBinStruct();
    void sentRead();
    QString printState(State *state);

public slots:
    void stop();
    void textWrite();
    void sentencesWrite();
    void menu();

private slots:
    void on_operate_clicked();

signals:
    void operationChanged();

private:
    Ui::MainWindow *ui;
    bool stoped = false;
};
#endif // MAINWINDOW_H
