#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bitset.h"

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
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_pushButton_clicked();

    void on_All_clicked();

    void on_Count_clicked();

    void on_Flip_clicked();

    void on_None_clicked();

    void on_Reset_clicked();

    void on_Set_clicked();



    void on_Size_clicked();

    void on_Test_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    size_t size;
    size_t num;

    BitSet *set;

};
#endif // MAINWINDOW_H
