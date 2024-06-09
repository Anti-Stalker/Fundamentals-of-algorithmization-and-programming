#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "airplane.h"

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
    void on_pushButton_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

private:
    Ui::MainWindow *ui;
   // void Struct();

    Airplane initWithStr;
    Airplane initWithUi;
   // Airplane initWithPtr;
   // Airplane initWithReference;

    void Str();
    void Ptr();
   // void Reference();


};
#endif // MAINWINDOW_H
