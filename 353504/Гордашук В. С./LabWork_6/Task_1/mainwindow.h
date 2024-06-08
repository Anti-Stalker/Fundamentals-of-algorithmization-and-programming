#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "state.h"

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
    QString printState(State state);
    QString printState(State *state);
    int i = 4;

private slots:
    void on_create_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
