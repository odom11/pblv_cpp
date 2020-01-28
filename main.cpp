#include <iostream>
#include <model/Data.h>
#include <model/Shark.h>
#include <controller/actions/MoveVisitor.h>
#include <controller/Simulator.h>

int main() {
    Data::fieldHeight = 3;
    Data::fieldWidth = 2;
    auto start = std::make_pair(1, 1);
    Shark shark;
    Simulator simulator;
    simulator.enterNewEntity(shark, start);
    MoveVisitor moveVisitor;
    for (int i = 0; i < 10; ++i) {
        shark.act(moveVisitor);
        auto newCoordinates = Data::entityToCoordinateMapping.find(&shark);
        std::cout << "x: " << newCoordinates->second.first << "\t y:" << newCoordinates->second.second << std::endl;
    }
    return 0;
}
