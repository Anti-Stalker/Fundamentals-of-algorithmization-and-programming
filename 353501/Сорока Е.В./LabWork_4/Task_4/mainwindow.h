#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRandomGenerator>
#include "vector.h"

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
    void on_input_fv_clicked();

    void on_input_sv_clicked();

    void on_assignBut_clicked();

private:
    Ui::MainWindow *ui;
    Vector<int> *first;
    Vector<int> *second;

};
#endif // MAINWINDOW_H
