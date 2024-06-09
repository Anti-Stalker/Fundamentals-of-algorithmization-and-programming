#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QVBoxLayout"
#include "QLabel"
#include "QLineEdit"
#include "QSpinBox"
#include "QIntValidator"
#include "QPushButton"

#include "QDebug"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent);
    ~MainWindow() override = default;

private:
    void RotateNumber();

    int64_t GetRotateNumber(int64_t number, int64_t temp = 0);

    QIntValidator *mintValidator;

    QWidget* converterWidget;
    QVBoxLayout *hLayout;

    QLineEdit *numberLine;
    QLineEdit *outputResultLine;

    QPushButton *calculateButton;

};
#endif // MAINWINDOW_H
