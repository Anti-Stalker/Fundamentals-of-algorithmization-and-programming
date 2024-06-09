#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QVBoxLayout"
#include "QTextEdit"
#include "QSpinBox"
#include "QPushButton"

#include "QDebug"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent);
    ~MainWindow() override = default;

private:


    QWidget* converterWidget;
    QVBoxLayout *hLayout;

    QSpinBox *heightTowerLine;
    QTextEdit *resultTextEdit;
    QPushButton *calculateButton;

    void Hanoi(int8_t height, int8_t start, int8_t finish);
    void StartHanoi();

};
#endif // MAINWINDOW_H
