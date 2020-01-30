#include <iostream>
#include <model/Data.h>
#include <model/Fish.h>
#include <model/Shark.h>
#include <controller/actions/SpreadVisitor.h>
#include <controller/actions/FeedVisitor.h>
#include <controller/Simulator.h>

int main() {
    Data::fieldHeight = 3;
    Data::fieldWidth = 3;
    SpreadVisitor moveVisitor;
    auto shark = std::make_unique<Shark>();
    auto sharkptr = shark.get();
    auto fish = std::make_unique<Fish>();
    auto fishptr = fish.get();
    Data::mapping.insert(std::move(shark), std::make_pair(0,0));
    Data::mapping.insert(std::move(fish), std::make_pair(2,2));
    FeedVisitor visitor;
    assert(Data::mapping.size() == 2);
    visitor.doIt(*fishptr);
    assert(Data::mapping.size() == 2);
    visitor.doIt(*sharkptr);
    assert(Data::mapping.size() == 1);

    return 0;
}
