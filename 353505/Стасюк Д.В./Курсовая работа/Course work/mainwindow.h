#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtWidgets/qtablewidget.h"
#include <QMainWindow>
#include <modelviewer.h>
#include <QQmlApplicationEngine>
#include <orders.h>
#include <createorderwindow.h>
#include <heapsort.h>

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
    QQmlApplicationEngine engine;

private slots:
    void on_openModelButton_clicked();
    void on_tableWidget_cellClicked(int row, int column);

    void on_createOrderButton_clicked();

    void on_sortByPriceButton_clicked();

    void on_sortByVolumeButton_clicked();

    void on_sortByDateButton_clicked();

    void on_updateButton_clicked();

private:
    Ui::MainWindow *ui;
    CreateOrderWindow *createOrderW;
    Orders orders;
    void show_vector_in_table(std::vector<Order> v);

};
#endif // MAINWINDOW_H
