
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "deque.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushBackButton_clicked();
    void on_pushFrontButton_clicked();
    void on_popBackButton_clicked();
    void on_popFrontButton_clicked();
    void on_clearButton_clicked();
    void updateDequeDisplay();

private:
    Ui::MainWindow *ui;
    Deque<int> deque;
};

#endif // MAINWINDOW_H
