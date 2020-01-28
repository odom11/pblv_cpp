//
// Created by ich on 1/28/20.
//

#include <controller/actions/MoveVisitor.h>
#include <model/Shark.h>
#include <model/Fish.h>
#include <model/Data.h>
#include <random>


bool isFree(Coordinate& coordinate) {
    int row = std::get<ROW>(coordinate);
    auto rowIt = Data::coordinateToEntityMapping.find(row);
    if (rowIt == Data::coordinateToEntityMapping.end()) {
        return true;
    }
    auto colIt = rowIt->second.find(std::get<COLUMN>(coordinate));
    return colIt == rowIt->second.end();
}

std::vector<Coordinate> freeNeighbours(const Coordinate& coordinate)  {
    auto modifyWidth = [&coordinate] (int num) {return ((num + Data::fieldHeight + std::get<ROW>(coordinate)) % Data::fieldHeight);};
    auto modifyHeight = [&coordinate] (int num) {return ((num + Data::fieldWidth + std::get<COLUMN>(coordinate)) % Data::fieldHeight);};

    Coordinate top = std::make_pair(modifyHeight(1), std::get<COLUMN>(coordinate));
    Coordinate bottom = std::make_pair(modifyHeight(-1), std::get<COLUMN>(coordinate));
    Coordinate left = std::make_pair(std::get<ROW>(coordinate), modifyWidth(-1));
    Coordinate right = std::make_pair(std::get<ROW>(coordinate), modifyWidth(1));
    std::vector<Coordinate> returnValue;
    for (Coordinate& item : std::array<Coordinate, 4>{top, bottom, left, right}) {
        if (isFree(item)) {
            returnValue.push_back(item);
        }
    }
    return returnValue;
}

void move(Entity& entity) {
    const Coordinate coordinate = Data::entityToCoordinateMapping.find(&entity)->second;
    auto&& neighbouring = std::move(freeNeighbours(coordinate));
    if (neighbouring.empty()) {
        return;
    }
    // remove old key
    auto rowIt = Data::coordinateToEntityMapping.find(std::get<ROW>(coordinate));
    auto colIt = rowIt->second.find(std::get<COLUMN>(coordinate));
    rowIt->second.erase(colIt);
    if (rowIt->second.empty()) {
        Data::coordinateToEntityMapping.erase(rowIt);
    }

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, neighbouring.size() - 1);
    auto newCoordinate = neighbouring.at(dist(rng));
    Data::coordinateToEntityMapping[std::get<ROW>(newCoordinate)][std::get<COLUMN>(newCoordinate)] = &entity;
    Data::entityToCoordinateMapping[&entity] = newCoordinate;
}

void MoveVisitor::doIt(Shark& shark) {
    move(shark);
}

void MoveVisitor::doIt(Fish &fish) {
    move(fish);
}
