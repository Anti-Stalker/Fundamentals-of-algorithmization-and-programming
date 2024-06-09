#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paintereffects.h"
#include <QTimer>

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
    void update_scene();
    void on_figures_activated(int index);
    void resizeEvent(QResizeEvent *event);

    void on_create_clicked();

    void on_change_clicked();

    void setInfo();
    void paintEvent(QPaintEvent* );

    void on_radio2_pressed();

    void on_radio1_pressed();

    void rotateRight();
    void rotateLeft();

    void on_radio1_released();

    void on_radio2_released();

private:
    Ui::MainWindow *ui;
    PainterEffects* scene;
    QTimer* timer;
    QTimer* timer_for_rot;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
