#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFile>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool Press = true;
    int k = 0;
    int l = -1;
    int m = 0;
    bool can = true;

    struct enemy{
        int paws = 0;
        double weight = 0;
        bool isHouse = false;
        QChar firstNameSymbol;
    };

        enemy Enemy;


private slots:
    void Enter();
    void Exec();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
