#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    int BinPow(int digit, int powder, int mod);
    void InterpolationSort(std::vector<int>& arr);

    void PrintArray(const std::vector<int>& arr);
    void FillArray(std::vector<int>& arr);

    int BinSearch(const std::vector<int>& arr, int l, int r, int num_to_find);

private slots:
    void on_SizeButton_clicked();

    void on_PowButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    bool IsSorted = false;

    std::vector<int> array;
    int size = 0;

    QString Output = "";
};
#endif // MAINWINDOW_H
