#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QMessageBox>

#include "rocket.h"
#include "flames.h"

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

private slots:
    void on_returnButton_clicked();
    void on_launchButton_clicked();
    void onAnimationUpFinished();
    void onAnimationDownFinished();
    void removeFlames();
    void showEvent(QShowEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Rocket *rocket;
    Flames *flames;
    QTimer *timerUp, *timerDown;
    bool isReturned = true;
};
#endif // MAINWINDOW_H
