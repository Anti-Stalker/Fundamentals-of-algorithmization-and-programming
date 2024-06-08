#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hashtable.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Solve * solve;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fullfilltables();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
