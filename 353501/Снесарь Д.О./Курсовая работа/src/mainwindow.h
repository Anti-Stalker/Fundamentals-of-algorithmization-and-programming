#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewidget.h"
#include "menu.h"
#include "info.h"
#include <QHBoxLayout>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStackedWidget* stackedWidget;
    GameWidget* gameWidget;
    GameWidget* solveWidget;
    Menu* menuWidget;
    Info* infoWidget;

    void switchToGameWidget();
};
#endif // MAINWINDOW_H
