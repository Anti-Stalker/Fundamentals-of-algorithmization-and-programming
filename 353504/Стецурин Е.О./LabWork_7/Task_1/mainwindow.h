#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "queuezxc.h"

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
    void on_push_back_clicked();

    void on_push_front_clicked();

    void on_pop_back_clicked();

    void on_pop_front_clicked();

    void on_front_clicked();

    void on_back_clicked();

    void on_empty_clicked();

    void on_print_clicked();

    void on_clear_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_task_clicked();

private:
    Ui::MainWindow *ui;
    Queue<long long> queue;
    Queue<long long> queue2;
    int numOfQueue=1;
};
#endif // MAINWINDOW_H
