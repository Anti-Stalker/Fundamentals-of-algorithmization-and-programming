#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "HashTable.h"
#include <QTimer>
#include <QElapsedTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    HashTable<int> a = HashTable<int>(16), b = HashTable<int>(64), c = HashTable<int>(128), d = HashTable<int>(2048);
    void fillTables();
};
#endif // MAINWINDOW_H
