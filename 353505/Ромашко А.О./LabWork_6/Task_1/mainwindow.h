#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLabel>

#include "buisnessman.h"

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
    QString str(){return this->forSecond;}
private slots:


    void on_lineEdit_name_textChanged(const QString &arg1);

    void on_lineEdit_wear_textChanged(const QString &arg1);

    void on_checkBox_new_stateChanged(int arg1);

    void on_spinBox_cost_valueChanged(int arg1);

    void on_doubleSpinBox_float_valueChanged(double arg1);

    void on_pushButton_clicked();

    void on_spinBox_id_valueChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Buisnessman *man;
    void print();
    int* arr[3];
    QString arrs;
    bool flagname=false,flagwear=false,flagcost=false,flagfloat=false;
    QString forSecond;

};
#endif // MAINWINDOW_H
