#include <iostream>
#include <model/Data.h>
#include <model/Shark.h>
#include <controller/actions/SpreadVisitor.h>
#include <controller/Simulator.h>

int main() {
    Data::fieldHeight = 3;
    Data::fieldWidth = 2;
    SpreadVisitor moveVisitor;
    auto sharkMngr = std::make_unique<Shark>();
    auto shark = sharkMngr.get();

    Data::mapping.insert(std::move(sharkMngr), std::make_pair(0,0));
    for (int i = 0; i < 100; ++i) {
        shark->act(moveVisitor);
        Coordinate& newCoordinates = Data::mapping.get(*shark);

        std::cout << "x: " << newCoordinates.first << "\t y:" << newCoordinates.second << "\t nuumber of elements: " << Data::mapping.size() << std::endl;
    }
    return 0;
}
