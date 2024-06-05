#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculateButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<double> calculateMedians(const std::vector<double>& inputVector);
};

#endif // MAINWINDOW_H
