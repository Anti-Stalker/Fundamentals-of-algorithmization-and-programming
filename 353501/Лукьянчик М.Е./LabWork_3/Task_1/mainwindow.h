#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class DecimalToBinary : public QObject
{
    Q_OBJECT
public:
    explicit DecimalToBinary(QObject *parent = nullptr);

    QString convert(const QString& decimal);

signals:
    void binaryResult(const QString& binary);

private:
    QString convertIntPart(int intPart, int fracPart);
    QString convertFracPart(double fraclPart, int maxFracDigits);
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onBinaryResult(const QString& binary);
    void performConversion();

private:
    Ui::MainWindow *ui;
    DecimalToBinary *converter;
};


#endif // MAINWINDOW_H


