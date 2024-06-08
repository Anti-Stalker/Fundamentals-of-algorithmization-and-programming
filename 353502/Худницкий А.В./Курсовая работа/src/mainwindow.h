#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include "levelgenerator.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    void createLevel(LevelGenerator *levelGenerator);

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createLevel();

    QWidget *centralWidget;
    QGridLayout *layout;
    LevelGenerator level;
};

#endif // MAINWINDOW_H
