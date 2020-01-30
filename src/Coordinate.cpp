//
// Created by ich on 1/30/20.
//
#include <iostream>
#include <Coordinate.h>

std::ostream& operator<<(std::ostream& os, const Coordinate& coordinate) {
    os << "x: " << coordinate.first << "\t y: " << coordinate.second;
    return os;
}

