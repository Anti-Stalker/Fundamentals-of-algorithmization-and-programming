#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map.h>
#include <city.h>
#include <road.h>
#include <trip.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimeLine>

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
    void on_generate_clicked();

    void on_exit_clicked();

    void on_addTruck_clicked();

    void on_deleteTruck_clicked();

    void on_createTrip_clicked();

    void on_startTrip_clicked();

    void on_deleteTrip_clicked();

    void on_checkStats_clicked();

private:
    void goTrip(Trip* trip);
    void goTruck(Truck* truck, std::vector<Road*> path);
    void move(QPointF start, QPointF finish,  Road* road, Truck* truck);


    void begin();
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Map* map;
    std::vector<Trip*> trips;
    std::vector<QLabel*> labels;
    std::vector<QPoint> positions;
    std::vector<QLabel*> roadsLabels;

    void showMap();
    void placeLabels();

    void hideLables();
    void showLables();

    void addTruck(Truck* truck);
    void removeTruck();
    void printRoads();
    QColor getColor(QString color);
    QPoint getPos(int num);

    int countOfTruck = 0;
    int allMaxLoadCapacity = 0;

    int allKg = 0;
    float allKm = 0;
};
#endif // MAINWINDOW_H
