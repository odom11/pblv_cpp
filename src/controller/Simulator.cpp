//
// Created by ich on 1/28/20.
//

#include <controller/Simulator.h>
#include <model/Data.h>

void Simulator::enterNewEntity(Entity &entity, Coordinate &coordinate) {
    Data::entityToCoordinateMapping[&entity] = coordinate;
    Data::coordinateToEntityMapping[std::get<ROW>(coordinate)][std::get<COLUMN>(coordinate)] = &entity;
}

