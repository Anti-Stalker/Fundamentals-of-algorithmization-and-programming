#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "house.h"

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
    void toUppercase();

    void on_pushButton_clicked();

    void showAllHoses();

private:
    Ui::MainWindow *ui;
    House houseInitializingString;
    House houseAssignValues;
    House houseForPtr;
    House *housePtr = &houseForPtr;
    House houseUser;
    QString stringOfPayments;

};
#endif // MAINWINDOW_H
