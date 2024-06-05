#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "object.h"
#include "QTimer"
#include "field.h"
#include "drawergl.h"
#include "graphic.h"
#include "settingsmenu.h"
#include "QFileDialog"
#include "createpopulationmenu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void newWorldSettings();
    void newPopulationSettings();

    void showMenu();
    void showPopulationMenu();

    void saveGenomsButtonClick();
    void loadGenomsButtonClick();

private:
    Ui::MainWindow *ui;
    Field *field;
    Graphic *graphic;
};
#endif // MAINWINDOW_H
