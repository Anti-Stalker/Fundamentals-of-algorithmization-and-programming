#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void pushElement();
    void popElement();

    void findMax();

private:
    Ui::MainWindow *ui;
    Queue<int> queue;
    int64_t _max = INT_FAST64_MIN;

};
#endif // MAINWINDOW_H
