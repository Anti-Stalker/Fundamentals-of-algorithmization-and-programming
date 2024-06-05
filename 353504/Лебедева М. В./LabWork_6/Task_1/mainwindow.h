#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "worker.h"

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

    bool check();
    void setStructs();
    std::string toString(Worker x);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Worker worker_1, worker_2, worker_3, *worker_4, *worker_base=new Worker();
    Worker &worker_5=*worker_base;
    //bool init=false;
};
#endif // MAINWINDOW_H
