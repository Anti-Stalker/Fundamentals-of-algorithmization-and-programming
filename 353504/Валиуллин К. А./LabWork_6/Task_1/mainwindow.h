#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "Motocycle.h"

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

protected slots:
    void explicitInit(long long *values, QString &str2, QString &str3);
    void separatlyInit(long long *values, QString &str2, QString &str3);

    void formStr2(Motorcycle &motorcycle, QString &str2);
    void formStr3(Motorcycle &motorcycle, QString &str3, long long *values);
    void initializeMotorcycleViaPointer(Motorcycle *motorcycle, QString &str2, QString &str3, long long *values);
    void initializeMotorcycleViaReference(Motorcycle &motorcycle, QString &str2, QString &str3, long long *values);
    void initializeByClient(QString &str2, QString &str3);
    void clearStrs(QString &str3, QString &str1, QString &str2);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Motorcycle Motorcycle1, Motorcycle2, Motorcycle3, Motorcycle4, Motorcycle5;
    Motorcycle *motorcyclePtr = &Motorcycle4;
    Motorcycle &motorcycleRef = Motorcycle5;
    QString str1, str2, str3;
};

#endif // MAINWINDOW_H
