// MainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "animal.h"
#include "input.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QFile* file1;
    QFile* file2;
    QFile* file3;
    QFile* file4;
    QFile* file5;
    Animal zver;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void getNewA(QString b, Animal a);

private:
    Ui::MainWindow *ui;
    QString newA;
};

#endif // MAINWINDOW_H
