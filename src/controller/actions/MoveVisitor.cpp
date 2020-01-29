//
// Created by ich on 1/28/20.
//

#include <controller/actions/MoveVisitor.h>
#include <model/Shark.h>
#include <model/Fish.h>
#include <model/Data.h>
#include <random>
#include <functional>

//std::array<Coordinate, 4> getAllNeighbours(Coordinate& coordinate) {
//    int row = std::get<ROW>(coordinate);
//    int col = std::get<COLUMN>(coordinate);
//    auto transform = [] (int value, int limit) {return (value + limit) % limit;};
//    auto top = std::make_pair(transform(row + 1, Data::fieldHeight), col);
//    auto bottom = std::make_pair(transform(row - 1, Data::fieldHeight), col);
//    auto left = std::make_pair(row, transform(col - 1, Data::fieldWidth));
//    auto right = std::make_pair(row, transform(col + 1, Data::fieldWidth));
//    return std::array<Coordinate, 4>{top, left, right, bottom};
//}
//
//std::vector<Coordinate> getNeighbours(Coordinate& coordinate,  std::function<bool(Entity& entity)> filter) {
//    auto allNeighbours = std::move(getAllNeighbours(coordinate));
//    std::vector<Coordinate> returnvalue;
//    std::copy_if(std::begin(allNeighbours), std::end(allNeighbours), std::back_inserter(returnvalue), filter);
//    return returnvalue;
//};

void move(Entity& entity) {
    Coordinate coordinate = Data::mapping.get(entity);
//    auto allFreeNeighbours = getNeighbours(coordinate, [](Entity& entity1) {return !Data::mapping.contains(entity1);});
//    if (allFreeNeighbours.size() == 0) return;
//    if (allFreeNeighbours.size() == 1) {
//    }

}

void MoveVisitor::doIt(Shark& shark) {
    move(shark);
}

void MoveVisitor::doIt(Fish &fish) {
    move(fish);
}
