#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "LineSolveHashTable.h"
#include "QuadFuncSolveHashTable.h"
#include <QGraphicsRectItem>
#include <ctime>
#include <random>
#include <QElapsedTimer>
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

    void print();
    void testing();
    void add_item(int i);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    LSHT* t11,*t12,*t13,*t14;
    QFSHT* t21,*t22,*t23,*t24;
    QGraphicsScene *scene;
    std::pair<unsigned short,long long> test[2050];
    std::mt19937 gen;
    QGraphicsRectItem * lt1,*lt2,*lt3,*lt4;
    QGraphicsRectItem * qt1,*qt2,*qt3,*qt4;
    long long result[8];
};
#endif // MAINWINDOW_H
