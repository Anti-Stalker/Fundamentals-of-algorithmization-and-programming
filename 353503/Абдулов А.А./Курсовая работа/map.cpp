#include "map.h"
#include "base.h"
#include <QRandomGenerator>
#include <queue>

Map::Map(){

}

Map::Map(std::vector <City*> cities, std::vector <Road*> roads){
    this->cities = cities;
    this->roads = roads;
}

std::vector <City*> Map::getCities(){
    return cities;
}

std::vector <Road*> Map::getRoads(){
    return roads;
}

City* Map::getBase(){
    return cities[0];
}


bool equals(City* s1, City* s2){
    return s1->getName() == s2->getName();
}

bool equals(Road* r1, Road* r2){
    return r1->getS1()->getName() == r2->getS1()->getName()
           && r1->getS2()->getName() == r2->getS2()->getName();
}

bool equals(std::vector<Road*> path1, std::vector<Road*> path2){
    int size1 = path1.size();
    int size2 = path2.size();

    if(size1 == size2){
        for(int i = 0; i < size1; i++){
            if(!equals(path1[i], path2[i])){
                return false;
            }
        }
    }else
        return false;

    return true;
}

//alg2

bool isCrossOver(float m, float c, QPoint p){
    float x0 =-m*c/(m*m+1);
    float y0 =-c/(m*m+1);

    float dist = sqrt((x0-p.x())*(x0-p.x()) + (y0-p.y())*(y0-p.y()));

    bool isCrossOver;
    const int RADIUS = 25;

    if(dist > RADIUS){
        isCrossOver = false;
    }else{
        isCrossOver = true;
    }

    return isCrossOver;
}

//alg2


bool isValid(std::vector <QPoint> centres){
    std::vector <QPoint> centres4 = centres;
    int size = centres.size();

    for(int i = 0; i < size; i++){
        QPoint p1 = centres[i];

        for(int j = 0; j < size; j++){
            QPoint p2 = centres[j];

            for(int d = 0; d < size; d++){
                if(i != j && i != d && j != d){
                    QPoint p3 = centres[d];
                    double square = std::abs( (p2.x()-p1.x())*(p3.y()-p1.y()) - (p3.x()-p1.x())*(p2.y()-p1.y()) )/2;
                    double line = sqrt(pow(p1.x()-p2.x(), 2) + pow(p1.y()-p2.y(), 2));
                    double distance = square / line;
                    if(distance < 45){
                        return false;
                    }
                }
            }
        }
    }

    //alg1,2

    for(int i = 0; i < size; i++){
        QPoint p1 = centres[i];

        for(int j = i + 1; j < size - 1; j++){
            QPoint p2 = centres[j];

            float m = (p2.y()-p1.y())/(p2.x()-p1.x());
            float c = p1.y()-p1.x()*m;

            for(int d = 0; d < size; d++){
                if(d != i && d != j){
                    QPoint p3 = centres[d];
                    if(isCrossOver(m,c,p3)){
                        return false;
                    }
                }
            }
        }
    }

    //alg1,2

    return true;
}

std::vector <QPoint> randomCentres(){
    std::vector <QPoint> centres;
    for(int i = 0; i < 7; i++){
        int x = QRandomGenerator::global()->bounded(1001,1801);
        int y = QRandomGenerator::global()->bounded(81,901);

        centres.push_back(*(new QPoint(x,y)));
    }
    return centres;
}

std::vector <Road*> randomRoads(std::vector <City*> cities){
    std::vector <Road*> roads;
    for(int i = 0; i < 5; i++){
        for(int j = i+2; j < 7; j++){
            int randNum = QRandomGenerator::global()->bounded(70);
            int maxSpeed = QRandomGenerator::global()->bounded(6,12) * 10;
            Road* randRoad = new Road(cities[i], cities[j], maxSpeed);
            if(randNum < 5){
                roads.push_back(randRoad);
            }
        }
    }


    return roads;
}

Map* Map::randomMap(){
    std::vector <QPoint> centres;

    do{
        centres = randomCentres();
    }while(!isValid(centres));

    std::vector <City*> cities;

    City* BASE = new Base("Base", centres[0]);
    City* Minsk = new City("Minsk", centres[1]);
    City* Gomel = new City("Gomel", centres[2]);
    City* Brest = new City("Brest", centres[3]);
    City* Vitebsk = new City("Vitebsk", centres[4]);
    City* Mogilev = new City("Mogilev", centres[5]);
    City* Grodno = new City("Grodno", centres[6]);

    cities.push_back(BASE);
    cities.push_back(Minsk);
    cities.push_back(Gomel);
    cities.push_back(Brest);
    cities.push_back(Vitebsk);
    cities.push_back(Mogilev);
    cities.push_back(Grodno);


    std::vector <Road*> roads;

    int maxSpeed = QRandomGenerator::global()->bounded(8,22) * 10;
    Road* mainRoad = new Road(BASE, Minsk, maxSpeed);

    maxSpeed = QRandomGenerator::global()->bounded(8,22) * 10;
    Road* MskGml = new Road(Minsk, Gomel, maxSpeed);

    maxSpeed = QRandomGenerator::global()->bounded(8,22) * 10;
    Road* GmlBrst = new Road(Gomel, Brest, maxSpeed);

    maxSpeed = QRandomGenerator::global()->bounded(8,22) * 10;
    Road* BrstVtbsk = new Road(Brest, Vitebsk, maxSpeed);

    maxSpeed = QRandomGenerator::global()->bounded(8,22) * 10;
    Road* VtbskMglv = new Road(Vitebsk, Mogilev, maxSpeed);

    maxSpeed = QRandomGenerator::global()->bounded(8,22) * 10;
    Road* MglvGrdn = new Road(Mogilev, Grodno, maxSpeed);

    roads = randomRoads(cities);

    roads.push_back(mainRoad);
    roads.push_back(MskGml);
    roads.push_back(GmlBrst);
    roads.push_back(BrstVtbsk);
    roads.push_back(VtbskMglv);
    roads.push_back(MglvGrdn);

    return new Map(cities, roads);
}

bool contains(std::vector<Road*> vec, Road* r){
    for(Road* currRoad : vec){
        if(equals(currRoad, r)){
            return true;
        }
    }
    return false;
}

Road* Map::getRoadFromCities(City* s1, City* s2){
    for(Road* r : roads){
        if( (equals(r->getS1(), s1) && equals(r->getS2(), s2)) || (equals(r->getS1(), s2) && equals(r->getS2(), s1)) ){
            return r;
        }
    }
    return nullptr;
}

std::vector<Road*> Map::getRoadsFromCity(City* city){
    std::vector<Road*> res;
    for(Road* r : roads){
        if( equals(r->getS1(), city) || equals(r->getS2(), city)) {
            res.push_back(r);
        }
    }
    return res;
}

City* getNextCity(Road* r, City* c){
    City* nextCity;

    if(!equals(r->getS1(), c)){
        nextCity = r->getS1();
    }else
        nextCity = r->getS2();

    return nextCity;
}

bool isContained(std::vector<Road*> currPath, Road* road){
    for(Road* r : currPath){
        if(equals(r,road)){
            return true;
        }
    }
    return false;
}

std::vector<std::vector<Road*>> Map::getPathsDKSTR(std::vector<std::vector<Road*>> result, std::vector<Road*> currPath, City* end, City* start){
    if(equals(start, end)){
        result.push_back(currPath);
        return result;
    }

    std::vector<Road*> roadsOfCity = getRoadsFromCity(start);

    for(Road* currentRoad : roadsOfCity){
        if(!isContained(currPath, currentRoad)){
            currPath.push_back(currentRoad);
            City* next = getNextCity(currentRoad, start);
            result = getPathsDKSTR(result, currPath, end, next);
            currPath.erase(currPath.end());
        }
    }

    return result;
}

std::vector<std::vector<Road*>> Map::getPathsBFS(std::vector<std::vector<Road*>> result, std::vector<Road*> currPath, City* end, City* start) {
    std::queue<std::tuple<City*, std::vector<Road*>>> queue;
    queue.push(std::make_tuple(start, currPath));

    while (!queue.empty()) {
        auto [currentCity, currentPath] = queue.front();
        queue.pop();

        if (equals(currentCity, end)) {
            result.push_back(currentPath);
            continue;
        }

        std::vector<Road*> roadsOfCity = getRoadsFromCity(currentCity);
        for (Road* currentRoad : roadsOfCity) {
            if (!isContained(currentPath, currentRoad)) {
                std::vector<Road*> newPath = currentPath;
                newPath.push_back(currentRoad);
                City* nextCity = getNextCity(currentRoad, currentCity);
                queue.push(std::make_tuple(nextCity, newPath));
            }
        }
    }

    return result;
}





