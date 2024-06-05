#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "truck.h"
#include <QLabel>
#include <thread>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QGraphicsItem>

//BEGIN
void MainWindow::begin(){
    ui->graphicsView->resize(1920,1080);

    ui->allKg->setText("-");
    ui->allKm->setText("-");
    ui->red->setText("-");
    ui->green->setText("-");
    ui->blue->setText("-");
    ui->yellow->setText("-");

    ui->checkStats->setEnabled(false);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1920,1080);

    ui->colorBox->addItem("red");
    ui->colorBox->addItem("green");
    ui->colorBox->addItem("blue");
    ui->colorBox->addItem("yellow");

    ui->createTrip->setEnabled(false);
    ui->startTrip->setEnabled(false);
    ui->deleteTrip->setEnabled(false);

    ui->radioButtonTIME->click();

    map = Map::randomMap();

    QPoint centre = map->getBase()->getCentre();

    QPoint pos1(centre.x()-10, centre.y()-10);
    QPoint pos2(centre.x()+10, centre.y()-10);
    QPoint pos3(centre.x()-10, centre.y()+10);
    QPoint pos4(centre.x()+10, centre.y()+10);

    positions.push_back(pos1);
    positions.push_back(pos2);
    positions.push_back(pos3);
    positions.push_back(pos4);

    showMap();

    printRoads();

    ui->graphicsView->setScene(scene);

    placeLabels();

    ui->deleteTruck->setEnabled(false);

    std::vector<City*> cities = map->getCities();

    for(int i = 1; i < 7; i++){
        ui->cityBox->addItem(cities[i]->getName());
    }
}

//TABLE WITH ROADS
void MainWindow::printRoads(){

    for(QLabel* label : roadsLabels){
        label->clear();
        ui->roads->removeWidget(label);
    }
    roadsLabels.clear();

    int countOfRoads = map->getRoads().size();
    std::vector<Road*> roads = map->getRoads();
    for(int i = 0; i < countOfRoads; i++){
        Road* currRoad = roads[i];
        QString s1 = currRoad->getS1()->getName();
        QString s2 = currRoad->getS2()->getName();

        QString distance = QString::number((int)currRoad->getDistance());
        QString maxSpeed = QString::number(currRoad->getMaxSpeed());

        QString text = s1 + " ---("+distance+"km, "+ maxSpeed +"km/h)---> " + s2;

        QLabel* label = new QLabel(this);

        label->setStyleSheet("QLabel { color : white; }");

        ui->roads->addWidget(label);

        label->setText(text);
        roadsLabels.push_back(label);
    }
}

//HELP FUNCT
QColor MainWindow::getColor(QString color){
    QColor res;
    if(color == "red"){
        res = Qt::red;
    }else if(color == "green"){
        res = Qt::green;
    }else if(color == "blue"){
        res = Qt::blue;
    }else {
        res = Qt::yellow;
    }

    return res;
}

QString getColorSTR(QColor color){
    QString res;
    if(color == Qt::red){
        res = "red";
    }else if(color == Qt::green){
        res = "green";
    }else if(color == Qt::blue){
        res = "blue";
    }else
        res = "yellow";

    return res;
}

QPoint MainWindow::getPos(int num){
    return positions[num];
}

void MainWindow::hideLables(){
    for(QLabel* l : labels){
        l->hide();
    }
}

void MainWindow::showLables(){
    for(QLabel* l : labels){
        l->show();
    }
}

//PLACE LABLES
void MainWindow::placeLabels(){
    int size = map->getCities().size();
    std::vector<City*> cities = map->getCities();
    hideLables();
    labels.clear();
    for(int i = 0; i < size; i++){
        City* city = cities[i];
        labels.push_back(new QLabel(city->getName(), this));
    }

    for(int i = 0; i < size; i++){
        QPoint centre = cities[i]->getCentre();
        labels[i]->move(centre.x()-25, centre.y()-60);
    }

    showLables();
}

void MainWindow::showMap(){
    for(City* city : map->getCities()){
        scene->addItem(city);
    }

    for(Road* road : map->getRoads()){
        scene->addItem(road);
    }

    QGraphicsLineItem* l1 = new QGraphicsLineItem(950, 30, 1850, 30);
    QGraphicsLineItem* l2 = new QGraphicsLineItem(1850, 30, 1850, 950);
    QGraphicsLineItem* l3 = new QGraphicsLineItem(1850, 950, 950, 950);
    QGraphicsLineItem* l4 = new QGraphicsLineItem(950, 950, 950, 30);

    QPen pen;
    pen.setWidth(5);
    l1->setPen(pen);
    l2->setPen(pen);
    l3->setPen(pen);
    l4->setPen(pen);

    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    begin();
}

MainWindow::~MainWindow(){
    delete ui;
}

//RANDOM MAP
void MainWindow::on_generate_clicked(){
    map->getBase()->getTrucks().clear();

    map = Map::randomMap();

    printRoads();

    positions.clear();

    QPoint centre = map->getBase()->getCentre();

    QPoint pos1(centre.x()-10, centre.y()-10);
    QPoint pos2(centre.x()+10, centre.y()-10);
    QPoint pos3(centre.x()-10, centre.y()+10);
    QPoint pos4(centre.x()+10, centre.y()+10);

    positions.push_back(pos1);
    positions.push_back(pos2);
    positions.push_back(pos3);
    positions.push_back(pos4);

    scene->clear();

    showMap();

    placeLabels();
}

//EXIT FROM PROGRAM
void MainWindow::on_exit_clicked(){
    std::exit(0);
}

//ADD TRUCK
void MainWindow::addTruck(Truck* truck){
    scene->addItem(truck);
}

void MainWindow::on_addTruck_clicked(){
    ui->createTrip->setEnabled(true);
    ui->deleteTruck->setEnabled(true);
    ui->generate->setEnabled(false);
    ui->kgSpinBox->setMinimum(50);

    countOfTruck++;

    int maxSpeed = ui->spinBoxMAXSPEED->value();
    int maxLoadCapacity = ui->spinBoxMAXKG->value();
    QString colorSTR = ui->colorBox->currentText();
    QColor color = getColor(colorSTR);
    int num = map->getBase()->getTrucks().size();
    QPoint pos = getPos(num);

    Truck* truck = new Truck(maxSpeed, maxLoadCapacity, pos, color, num);

    QString info = QString::number(countOfTruck) + ".("+ colorSTR +")(km/h:"
                 + QString::number(maxSpeed) + ", maxKg:" + QString::number(maxLoadCapacity) + ")";

    int ind = ui->colorBox->currentIndex();
    ui->colorBox->removeItem(ind);

    ui->truckBox->addItem(info);

    map->getBase()->addTruck(truck);

    addTruck(truck);

    allMaxLoadCapacity += maxLoadCapacity;
    ui->kgSpinBox->setMaximum(allMaxLoadCapacity);

    if(countOfTruck == 4)
        ui->addTruck->setEnabled(false);
}

void MainWindow::on_deleteTruck_clicked(){
    ui->addTruck->setEnabled(true);

    int ind = ui->truckBox->currentIndex();
    ui->truckBox->removeItem(ind);

    Truck* delTruck = map->getBase()->getTrucks()[ind];

    int size = trips.size();

    for(int i = 0; i < size; i++){
        std::vector<Truck*> trucks = trips[i]->getTrucks();

        for(Truck* truck : trucks){
            if(truck->equals(delTruck)){
                ui->comboBoxOfTrips->removeItem(size-(i+1));
                trips.erase(trips.begin() + i);
            }
        }
    }

    size = trips.size();

    QColor delTruckColor = delTruck->getColor();
    QString colorSTR = getColorSTR(delTruckColor);

    if(delTruckColor == Qt::red){
        ui->red->setText("NONE");
    }else if(delTruckColor == Qt::green){
        ui->green->setText("NONE");
    }else if(delTruckColor == Qt::blue){
        ui->blue->setText("NONE");
    }else{
        ui->yellow->setText("NONE");
    }

    ui->colorBox->addItem(colorSTR);

    allMaxLoadCapacity -= delTruck->getMaxLoadCapacity();
    ui->kgSpinBox->setMaximum(allMaxLoadCapacity);

    countOfTruck--;

    std::vector<Truck*> newTruckList;

    int i = 0;

    for(Truck* truck : map->getBase()->getTrucks()){
        scene->removeItem(truck);

        float km = truck->getKM();
        int kg = truck->getKG();
        QColor color = truck->getColor();
        int maxSpeed = truck->getMaxSpeed();
        int maxLoadCapacity = truck->getMaxLoadCapacity();
        QPointF pos = getPos(truck->getNum());

        if(!truck->equals(delTruck)){
            newTruckList.push_back(new Truck(maxSpeed, maxLoadCapacity, QPointF(0,0), color, i));
            newTruckList[i]->setPos(pos);
            newTruckList[i]->addKM(km);
            newTruckList[i]->addKG(kg);
            i++;
        }

        delete truck;
    }

    map->getBase()->setTruckList(newTruckList);

    for(int i = 0; i < countOfTruck; i++){
        QString inf = ui->truckBox->itemText(i);
        QString num = QString::number(i+1);
        inf[0] = num[0];
        ui->truckBox->setItemText(i, inf);
    }

    for(Truck* truck : newTruckList){
        QPointF pos = getPos(truck->getNum());
        truck->setPos(getPos(truck->getNum()));
        truck->setRect(pos.x()-10, pos.y()-10, 20,20);
        scene->addItem(truck);
    }

    scene->update();

    if(trips.size() == 0){
        ui->startTrip->setEnabled(false);
        ui->deleteTrip->setEnabled(false);
    }


    if(countOfTruck == 0){
        ui->deleteTruck->setEnabled(false);
        ui->createTrip->setEnabled(false);
        ui->kgSpinBox->setMinimum(0);
        ui->kgSpinBox->setMaximum(0);
    }
}

//PATH FUNCT
std::vector<std::vector<Road*>> callGetAllPathsDKSTR(Map* map, City* endCity){
    std::vector<std::vector<Road*>> paths;
    std::vector<Road*> path;
    return map->getPathsDKSTR(paths, path, endCity, map->getBase());
}

std::vector<std::vector<Road*>> callGetAllPathsBFS(Map* map, City* endCity){
    std::vector<std::vector<Road*>> paths;
    std::vector<Road*> path;
    return map->getPathsBFS(paths, path, endCity, map->getBase());
}

double getPathDistance(std::vector<Road*> way){
    double distance = 0;

    for(Road* road : way){
        distance += road->getDistance();
    }

    return distance;
}

std::vector<Road*> getPathMinDistance(std::vector<std::vector<Road*>> allPaths){
    std::vector<Road*> result = allPaths[0];
    double minDistance = getPathDistance(allPaths[0]);

    for(std::vector<Road*> currentPath : allPaths){
        double newDistance = getPathDistance(currentPath);
        if(minDistance > newDistance){
            minDistance = newDistance;
            result = currentPath;
        }
    }

    return result;
}

int getMinSpeedBeetwenTrucks(std::vector<Truck*> trucks){
    int minSpeed = trucks[0]->getMaxSpeed();

    for(Truck* currentTruck : trucks){
        int maxSpeedOfCurrentTruck = currentTruck->getMaxSpeed();
        minSpeed = minSpeed > maxSpeedOfCurrentTruck ? maxSpeedOfCurrentTruck : minSpeed;
    }

    return minSpeed;
}

double getPathTime(std::vector<Road*> path, int truckSpeed){
    double time = 0;

    for(Road* road : path){
        int roadSpeed = road->getMaxSpeed();
        int newSpeed = (roadSpeed < truckSpeed ? roadSpeed : truckSpeed);

        time += road->getTime(newSpeed);
    }

    return time;
}

std::vector<Road*> getPathMinTime(std::vector<std::vector<Road*>> allPaths, std::vector<Truck*> trucks){
    std::vector<Road*> result = allPaths[0];
    int minSpeed = getMinSpeedBeetwenTrucks(trucks);
    double minTime = getPathTime(allPaths[0], minSpeed);

    for(std::vector<Road*> currentPath : allPaths){
        double curerentTime = getPathTime(currentPath, minSpeed);
        if(minTime > curerentTime){
            minTime = curerentTime;
            result = currentPath;
        }
    }

    return result;
}

std::vector<Truck*> getTruckSet(std::vector<Truck*> trucks, int kg){
    std::vector<Truck*> truckSet;
    int size = trucks.size();

    for(int i = 0; i < size - 1; i++){
        for(int j = i+1 ; j < size; j++){
            if(trucks[i]->getMaxLoadCapacity() < trucks[j]->getMaxLoadCapacity()){
                Truck* tmp = trucks[i];
                trucks[i] = trucks[j];
                trucks[j] = tmp;
            }
        }
    }

    int currKg = 0;
    for(Truck* currTruck : trucks){
        if(!currTruck->getStatus()){
            currKg += currTruck->getMaxLoadCapacity();
            truckSet.push_back(currTruck);
            if(currKg >= kg){
                return truckSet;
            }
        }
    }

    return truckSet;
}

//create trip
void MainWindow::on_createTrip_clicked(){
    ui->startTrip->setEnabled(true);
    ui->deleteTrip->setEnabled(true);

    bool isMinDist = ui->radioButtonMINDIST->isChecked();
    int kg = ui->kgSpinBox->value();

    City* endCity = map->getCities()[ui->cityBox->currentIndex()+1];

    std::vector<std::vector<Road*>> paths;
    std::vector<Road*> needPath;

    std::vector<Truck*> truckSet = getTruckSet(map->getBase()->getTrucks(), kg);

    if(isMinDist){
        paths = callGetAllPathsDKSTR(map, endCity);
        needPath = getPathMinDistance(paths);
    }else{
        paths = callGetAllPathsBFS(map, endCity);
        needPath = getPathMinTime(paths, truckSet);
    }

    trips.push_back( new Trip(kg, truckSet, needPath, isMinDist));
    ui->comboBoxOfTrips->addItem(trips[trips.size()-1]->getInfo());
}

float getTimeInRoad(float distance, int maxRoadSpeed, int maxTruckSpeed){

    if(maxRoadSpeed > maxTruckSpeed){
        return distance/maxTruckSpeed;
    }else
        return distance/maxRoadSpeed;
}

void MainWindow::move(QPointF start, QPointF finish,  Road* road, Truck* truck){
    QPointF p(0,0);
    truck->setPos(p);

    float time = getTimeInRoad(road->getDistance(), road->getMaxSpeed(), truck->getMaxSpeed()) * 1000;

    QTimeLine *timeLine = new QTimeLine(time);

    timeLine->setUpdateInterval(5);

    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation();

    animation->setItem(truck);
    animation->setTimeLine(timeLine);

    animation->setPosAt(0 , start);
    animation->setPosAt(1 , finish);

    QEventLoop* loop = new QEventLoop(timeLine);

    QObject::connect(timeLine, &QTimeLine::finished, loop, &QEventLoop::quit);

    timeLine->start();

    loop->exec();

    scene->update();
}

void MainWindow::goTruck(Truck* truck, std::vector<Road*> path){

    City* currentCity = path[0]->getS1();
    City* nextCity;

    int size = path.size();

    //GO AHEAD
    for(int i = 0; i < size; i++){
        Road* road = path[i];
        nextCity = road->getNextCity(currentCity);
        move(currentCity->getCentre(), nextCity->getCentre(), road, truck);
        currentCity = road->getNextCity(currentCity);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    //GO BACK
    for(int i = size-1; i >= 0; i--){
        Road* road = path[i];
        nextCity = road->getNextCity(currentCity);
        move(currentCity->getCentre(), nextCity->getCentre(), road, truck);
        currentCity = road->getNextCity(currentCity);
    }

    int num = truck->getNum()+1;

    if(num == 1){
        truck->moveBy(-10, -10);
    }else if(num == 2){
        truck->moveBy(10, -10);
    }else if(num == 3){
        truck->moveBy(-10, 10);
    }else
       truck->moveBy(10, 10);
}

void MainWindow::goTrip(Trip* trip){
    std::vector<Truck*> trucks = trip->getTrucks();
    std::vector<Road*> path = trip->getRoads();

    int kg = trip->getKg();

    for(Truck* truck : trip->getTrucks()){
        if(kg > truck->getMaxLoadCapacity()){
            truck->addKG(truck->getMaxLoadCapacity());
            kg -= truck->getMaxLoadCapacity();
        }else
            truck->addKG(kg);

        goTruck(truck, path);
    }
}

void MainWindow::on_startTrip_clicked(){
    int ind = ui->comboBoxOfTrips->currentIndex();

    ui->deleteTruck->setEnabled(false);
    ui->startTrip->setEnabled(false);
    ui->deleteTrip->setEnabled(false);
    ui->addTruck->setEnabled(false);
    ui->createTrip->setEnabled(false);

    Trip* trip = trips[ind];

    allKg += trip->getKg();

    float dist = getPathDistance(trip->getRoads());

    allKm += dist;

    trip->updateTruckDistance(dist);

    ui->comboBoxOfTrips->removeItem(ind);
    trips.erase(trips.begin()+ind);
    trip->setStatusOfTrucks(true);

    goTrip(trip);

    trip->setStatusOfTrucks(false);

    if(trips.size() == 0){
        ui->startTrip->setEnabled(false);
        ui->deleteTrip->setEnabled(false);
    }else{
        ui->startTrip->setEnabled(true);
        ui->deleteTrip->setEnabled(true);
    }

    if(countOfTruck < 4)
        ui->addTruck->setEnabled(true);

    ui->createTrip->setEnabled(true);
    ui->deleteTruck->setEnabled(true);
    ui->checkStats->setEnabled(true);
}

void MainWindow::on_deleteTrip_clicked(){
    int ind = ui->comboBoxOfTrips->currentIndex();
    ui->comboBoxOfTrips->removeItem(ind);
    trips.erase(trips.begin()+ind);

    if(trips.size() == 0){
        ui->startTrip->setEnabled(false);
        ui->deleteTrip->setEnabled(false);
    }
}

void MainWindow::on_checkStats_clicked(){
    ui->checkStats->setEnabled(false);

    ui->allKm->setText(QString::number(allKm));
    ui->allKg->setText(QString::number(allKg));

    for(Truck* truck : map->getBase()->getTrucks()){
        if(truck->getColor() == Qt::red){
            ui->red->setText("Kg:" + QString::number(truck->getKG()) + ", Km:" +  QString::number(truck->getKM()));
        }else if(truck->getColor() == Qt::green){
            ui->green->setText("Kg:" + QString::number(truck->getKG()) + ", Km:" +  QString::number(truck->getKM()));
        }else if(truck->getColor() == Qt::blue){
            ui->blue->setText("Kg:" + QString::number(truck->getKG()) + ", Km:" +  QString::number(truck->getKM()));
        }else{
            ui->yellow->setText("Kg:" + QString::number(truck->getKG()) + ", Km:" +  QString::number(truck->getKM()));
        }
    }

    ui->checkStats->setText("UPDATE STATS");
}

