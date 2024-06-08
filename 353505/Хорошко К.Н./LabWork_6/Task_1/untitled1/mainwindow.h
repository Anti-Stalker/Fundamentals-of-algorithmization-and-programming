#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    struct enemy{
        int paws = 0;
        double weight = 0;
        bool isHouse = false;
        QChar firstNameSymbol;
    };


    static QChar array_gender[100];
    static double array_age[100];

    QVector<enemy> Enemy;

    enemy nullEnemy;
    enemy firstEnemy;
    enemy secondEnemy;
    int i = -1;

private slots:
    void myclick();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
