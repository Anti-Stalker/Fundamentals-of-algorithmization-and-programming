#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "sorting.h"
#include "binsearch.h"

enum Sort_Type{
    Quick = 0,
    Merge = 1,
    Heap = 2,
    Interpolation = 3
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void FillArray();
    void PrintLine();
    void DisplayArray();

private slots:
   void on_CreateArray_clicked();

    void on_SortBox_currentIndexChanged(int index);

    void on_SortButton_clicked();

    void on_SearchButton_clicked();

private:
    Ui::MainWindow *ui;

    Sort_Type Curr_Sorting = Quick;

    QString Output_Array = "";

    bool IsSorted = false;

    int *arr;
    int size = 0;
    int counter = 0;
};
#endif // MAINWINDOW_H
