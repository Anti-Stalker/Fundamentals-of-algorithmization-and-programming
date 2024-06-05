#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Deque.h"
#include <QMainWindow>
#include <QListWidget>

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
    void on_push_front_clicked();
    void on_pop_front_clicked();
    void on_push_back_clicked();
    void on_pop_back_clicked();
    void on_index_valueChanged(int arg1);
    void on_Clear_clicked();

private:
    Ui::MainWindow *ui;
    Deque<QString> _deque;

    void updateUI();
};
#endif // MAINWINDOW_H
