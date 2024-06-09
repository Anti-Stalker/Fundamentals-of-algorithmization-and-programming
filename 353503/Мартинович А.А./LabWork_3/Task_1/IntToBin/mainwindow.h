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

#include "QDebug"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent);
    ~MainWindow() override = default;

private:
    void CalculateDecimalToBinary();

    QString DecimalToBinary(const long double decimal, const int16_t decimalPrecision);
    QString DecimalPartToBinary(int64_t decimalPart, QString resultString = "");
    QString PartialPartToBinary(double partialPart, const int16_t decimalPrecision, QString resultString = "");

    QWidget* converterWidget;
    QVBoxLayout *hLayout;

    QRegularExpressionValidator* doubleValidator;

    QLineEdit *decimalInputLineEdit;
    QSpinBox *decimalPrecisionLineEdit;
    QLineEdit *binaryOutputLineEdit;

    QPushButton *calculateButton;

};
#endif // MAINWINDOW_H
