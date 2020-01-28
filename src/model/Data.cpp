//
// Created by ich on 1/28/20.
//

#include <model/Data.h>

std::map<Entity*, Coordinate> Data::entityToCoordinateMapping;
std::map<int, std::map<int, Entity*>> Data::coordinateToEntityMapping;
int Data::fieldWidth;
int Data::fieldHeight;

