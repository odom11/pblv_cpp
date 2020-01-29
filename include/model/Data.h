//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_DATA_H
#define POPULATIONDYNAMICS_DATA_H

#include <map>
#include <utility>
#include <Bimap.h>

using Coordinate = std::pair<int,int>;

enum coordinate {ROW, COLUMN};

class Entity;
struct Data {
    static int fieldWidth;
    static int fieldHeight;
    static Bimap<Entity, Coordinate> mapping;
};

#endif //POPULATIONDYNAMICS_DATA_H
