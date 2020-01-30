//
// Created by ich on 1/30/20.
//

#include <model/Shark.h>
#include <controller/actions/FeedVisitor.h>
#include <Coordinate.h>
#include <model/Data.h>
#include <vector>
#include <functional>
#include <controller/actions/GetEatenVisitor.h>

std::array<Coordinate, 4> getAllNeighbours(Coordinate& coordinate);
std::vector<Coordinate> getNeighbours(Coordinate& coordinate,  std::function<bool(const Coordinate &)> filter);

void FeedVisitor::doIt(Shark &shark) {
    Coordinate& currentPosition = Data::mapping.get(shark);
    auto filledNeighbours = getNeighbours(currentPosition, [] (const Coordinate& coordinate) {return Data::mapping.contains(coordinate);});
    bool wasSatiated = false;
    GetEatenVisitor getEaten(wasSatiated);
    for (auto& neighbour : filledNeighbours) {
        if (wasSatiated) break;
        Entity& entity = Data::mapping.get(neighbour);
        entity.act(getEaten);
    }

    if (wasSatiated) {
        shark.setLifepoints(shark.getLifepoints() + 1);
    } else {
        shark.setLifepoints(shark.getLifepoints() - 1);
    }
}

void FeedVisitor::doIt(Fish &fish) {
    return;
}
