//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_DATA_H
#define POPULATIONDYNAMICS_DATA_H

#include <map>
#include <utility>

using Coordinate = std::pair<int,int>;

enum coordinate {ROW, COLUMN};

class Entity;
struct Data {
    static int fieldWidth;
    static int fieldHeight;
    static std::map<int, std::map<int, Entity*>> coordinateToEntityMapping;
    static std::map<Entity*, Coordinate> entityToCoordinateMapping;
};

#endif //POPULATIONDYNAMICS_DATA_H
