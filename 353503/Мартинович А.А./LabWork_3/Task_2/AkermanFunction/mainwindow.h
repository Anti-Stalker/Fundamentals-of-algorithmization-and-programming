#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QVBoxLayout"
#include "QLabel"
#include "QLineEdit"
#include "QSpinBox"
#include "QRegularExpressionValidator"
#include "QRegularExpression"
#include "QPushButton"
#include "QHash"
#include "QPair"

#include "QDebug"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent);
    ~MainWindow() override = default;

private:
    void CalculateAckermanFunction();

    int64_t AckermanFunction(int64_t m, int64_t n, QHash<QPair<int64_t, int64_t>, int64_t> &ackermanMemo);

    QWidget* converterWidget;
    QVBoxLayout *hLayout;

    QSpinBox *numberMLine;
    QSpinBox *numberNLine;
    QLineEdit *outputResultLine;

    QPushButton *calculateButton;

};
#endif // MAINWINDOW_H
