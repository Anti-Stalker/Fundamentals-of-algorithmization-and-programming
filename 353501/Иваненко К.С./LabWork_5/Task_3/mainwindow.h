#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bitset.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static const size_t bsetSize = 512;
    Bitset<bsetSize> bitset;

    void updateBitset();
    void updateInfo();

private slots:
    void on_flipButton_clicked();
    void on_flipIndexButton_clicked();

    void on_setIndexButton_clicked();
    void on_setButton_clicked();

    void on_resetIndexButton_clicked();
    void on_resetButton_clicked();

    void on_testIndexButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H