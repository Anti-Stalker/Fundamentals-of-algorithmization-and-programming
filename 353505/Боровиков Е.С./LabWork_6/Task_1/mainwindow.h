#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "computer.h"

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

private:
    Ui::MainWindow *ui;
    Computer computer_1;
    Computer computer_2;
    Computer computer_3;
    Computer *computer_4 = &computer_2;
    Computer &computer_5 = computer_3;
    void showInfo();
};
#endif // MAINWINDOW_H
