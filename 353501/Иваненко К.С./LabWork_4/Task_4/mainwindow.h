#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector.h"
#include "table.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    vector<int> tmp = {1,2,3,4,5,6};
    table myTable;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_push_backbutton_clicked();
    void on_resizebutton_clicked();
    void on_atbutton_clicked();
    void on_endbutton_clicked();
    void on_beginbutton_clicked();
    void on_capacitybutton_clicked();
    void on_clearbutton_clicked();
    void on_emptubutton_clicked();
    void on_erasebutton_clicked();
    void on_pop_backbutton_clicked();
    void on_sizebutton_clicked();
    void on_insertbutton_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H