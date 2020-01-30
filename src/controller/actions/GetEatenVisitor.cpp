//
// Created by ich on 1/30/20.
//

#include <model/Fish.h>
#include <model/Shark.h>
#include <controller/actions/GetEatenVisitor.h>
#include <model/Data.h>

void GetEatenVisitor::doIt(Shark &shark) {
    return;
}

void GetEatenVisitor::doIt(Fish &fish) {
    satiated = true;
    Data::mapping.remove(fish);
}
