#ifndef MAP_H
#define MAP_H

#include <vector>
#include "city.h"
#include "road.h"
#include <QLabel>

class Map{
public:
    Map();
    static Map* randomMap();

    std::vector <City*> getCities();
    std::vector <Road*> getRoads();
    std::vector <std::vector<Road*>> getPathsDKSTR(std::vector<std::vector<Road*>> result, std::vector<Road*> currPath, City* end, City* start);
    City* getBase();
    Road* getRoadFromCities(City* s1, City* s2);
    std::vector<Road*> getRoadsFromCity(City* city);
    std::vector<std::vector<Road*>> getPathsBFS(std::vector<std::vector<Road*>> result, std::vector<Road*> currPath, City* end, City* start);

private:
    Map(std::vector <City*> cities, std::vector <Road*> roads);

    std::vector <City*> cities;
    std::vector <Road*> roads;

};

#endif // MAP_H
