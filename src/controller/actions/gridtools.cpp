//
// Created by ich on 1/30/20.
//
#include <array>
#include <vector>
#include <algorithm>

#include <Coordinate.h>
#include <model/Data.h>

std::array<Coordinate, 4> getAllNeighbours(Coordinate& coordinate) {
    int row = std::get<ROW>(coordinate);
    int col = std::get<COLUMN>(coordinate);
    auto transform = [] (int value, int limit) {return (value + limit) % limit;};
    auto top = std::make_pair(transform(row + 1, Data::fieldHeight), col);
    auto bottom = std::make_pair(transform(row - 1, Data::fieldHeight), col);
    auto left = std::make_pair(row, transform(col - 1, Data::fieldWidth));
    auto right = std::make_pair(row, transform(col + 1, Data::fieldWidth));
    return std::array<Coordinate, 4>{top, left, right, bottom};
}

std::vector<Coordinate> getNeighbours(Coordinate& coordinate,  std::function<bool(const Coordinate &)> filter) {
    auto allNeighbours = getAllNeighbours(coordinate);
    std::vector<Coordinate> returnvalue;
    std::copy_if(allNeighbours.begin(), allNeighbours.end(), std::back_inserter(returnvalue), filter);
    return returnvalue;
};
