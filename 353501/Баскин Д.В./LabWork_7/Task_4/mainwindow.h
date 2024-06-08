#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <hashtable.h>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
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
    void on_pushButton_reset_clicked();

    void on_pushButton_find_clicked();

private:
    Ui::MainWindow *ui;
    void UpdateInfo();
    HashTable* table16x = nullptr;
    HashTable* table64x = nullptr;
    HashTable* table128x = nullptr;
    HashTable* table2048x = nullptr;
};
#endif // MAINWINDOW_H
