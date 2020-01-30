//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_DATA_H
#define POPULATIONDYNAMICS_DATA_H

#include <map>
#include <utility>
#include <Bimap.h>

#include <model/Entity.h>
#include <Coordinate.h>


class Entity;
struct Data {
    static int fieldWidth;
    static int fieldHeight;
    static Bimap<Entity, Coordinate> mapping;
};

#endif //POPULATIONDYNAMICS_DATA_H
