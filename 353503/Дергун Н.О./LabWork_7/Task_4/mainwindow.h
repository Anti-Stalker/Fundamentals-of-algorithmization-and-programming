#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "HashTable.h"

#include <QChartView>
#include <QGridLayout>
#include <QLineSeries>
#include <QMainWindow>
#include <QPushButton>
#include <QRandomGenerator>
#include <QTableWidget>
#include <QtCharts>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


const int TABLE_SIZES[4] = {16, 64, 128, 2048};
const uint8_t MIN_STR_SIZE = 4;
const uint8_t MAX_STR_SIZE = 8;
const int NUM_TABLES = 4;
const int NUM_OCCUPANCY_LEVELS = 7;
const uint8_t SAMPLE_SIZE = 10;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

    StrHashTable<int> _table;
    QChartView* _chartViews[NUM_TABLES];
    QTableWidget* _tableWidget;

    void initUI();

    //helper funcs
    QString getRandStr(uint minSize, uint maxSize);
    QVector<QString> fillIn(uint size, StrHashTable<int>& table);
    void setTable(QGridLayout* layout);
    void collectData(size_t times[4][7]);
    void createSeries(size_t times[4][7], QLineSeries* series[4]);
    void configureCharts(QLineSeries* series[4], QChart* charts[4], QChartView* chartViews[4], QGridLayout* layout);
};
#endif // MAINWINDOW_H
