//
// Created by ich on 1/28/20.
//

#include <controller/actions/SpreadVisitor.h>
#include <model/Shark.h>
#include <model/Fish.h>
#include <model/Data.h>
#include <random>
#include <functional>
#include <cassert>
#include <iterator>


std::array<Coordinate, 4> getAllNeighbours(Coordinate& coordinate);
std::vector<Coordinate> getNeighbours(Coordinate& coordinate,  std::function<bool(const Coordinate &)> filter);
//

void move(Entity& entity) {
    Coordinate oldCoordinate = Data::mapping.get(entity);
    auto allFreeNeighbours = std::move(getNeighbours(oldCoordinate, [](const Coordinate & coordinate1) {return !Data::mapping.contains(coordinate1);}));
    if (allFreeNeighbours.size() == 0) return;
    int randomIndex;
    if (allFreeNeighbours.size() == 1) {
        randomIndex = 0;
    } else {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, allFreeNeighbours.size() - 1);
        randomIndex = dist(mt);
    }
    Coordinate& newCoordinate = allFreeNeighbours[randomIndex];
    Data::mapping.update(entity, newCoordinate);
    if (entity.getAge() >= entity.PROCREATION_LIMIT) {
        Data::mapping.insert(entity.clone(), oldCoordinate);
        entity.setAge(-1);
    }
    entity.setAge(entity.getAge() + 1);
}

void SpreadVisitor::doIt(Shark& shark) {
    move(shark);
}

void SpreadVisitor::doIt(Fish &fish) {
    move(fish);
}
