#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myhashtable.h"

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
    void on_InsertButton_clicked();

    void on_FindMaxStackButton_clicked();



    void on_GenerateButton_clicked();

    void on_FindButton_clicked();

    void on_RemoveButton_clicked();

private:
    Ui::MainWindow *ui;
    MyHashTable hashTable;
};
#endif // MAINWINDOW_H
