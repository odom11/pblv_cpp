
#include <utility>

//
// Created by ich on 1/28/20.
//
class Entity;
using Coordinate = std::pair<int,int>;
class Simulator {
public:
    void update();
    void enterNewEntity(Entity& entity, Coordinate& coordinate);
};

