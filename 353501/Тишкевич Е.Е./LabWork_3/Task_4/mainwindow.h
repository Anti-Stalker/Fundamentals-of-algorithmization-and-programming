#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <towers.h>

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

    void spinSlot(int);

    void startSlot();

    void restartSlot();

private:
    void moveDisc(int ,char ,char );
    void start(int , char , char , char );
    QGraphicsScene *scene;
    towers* hTowers;
    Ui::MainWindow *ui;
    int row = 1;
    bool stop=false;
};

#endif // MAINWINDOW_H
