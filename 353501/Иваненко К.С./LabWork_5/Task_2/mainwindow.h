#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_strlenbutton_clicked();

    void on_strcpybutton_clicked();

    void on_strncpybutton_clicked();

    void on_strcatbutton_clicked();

    void on_strncatbutton_clicked();

    void on_strcmpbutton_clicked();

    void on_strncmpbutton_clicked();

    void on_strerrbutton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H