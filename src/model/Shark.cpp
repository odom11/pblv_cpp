//
// Created by ich on 1/28/20.
//

#include <model/Shark.h>

void Shark::act(ActionVisitor &visitor) {
    visitor.doIt(*this);
}

std::unique_ptr<Entity> Shark::clone() {
    return std::make_unique<Shark>();
}

