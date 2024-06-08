#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>
#include "myhashtable.h" // Подключаем заголовочный файл MyHashTable

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
    void on_SearchButton_clicked();
    void on_FindMaxStackButton_clicked();

    void on_tableIndexSpinBox_valueChanged(int index);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QVector<MyHashTable*> hashTables;

    void updateSearchTimesAndGraph(const QVector<double> &searchTimes);
};

#endif // MAINWINDOW_H
