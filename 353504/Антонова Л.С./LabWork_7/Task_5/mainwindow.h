#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "deque.cpp"

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
    void on_pushButton_push_clicked();

    void on_pushButton_push_back_clicked();

    void on_pushButton_size_clicked();

    void on_pushButton_first_clicked();

    void on_pushButton_last_clicked();

    void on_pushButton_empty_clicked();

    void on_pushButton_pop_clicked();

    void on_pushButton_pop_back_clicked();

private:
    Ui::MainWindow *ui;

    Deque<int>* deque;
};
#endif // MAINWINDOW_H
