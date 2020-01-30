//
// Created by ich on 1/30/20.
//

#ifndef POPULATIONDYNAMICS_COORDINATE_H
#define POPULATIONDYNAMICS_COORDINATE_H

#include <utility>
using Coordinate = std::pair<int,int>;
enum coordinate {ROW, COLUMN};
std::ostream& operator<<(std::ostream& os, const Coordinate& coordinate);
#endif //POPULATIONDYNAMICS_COORDINATE_H
