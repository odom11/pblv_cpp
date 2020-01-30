//
// Created by ich on 1/30/20.
//

#include <model/Fish.h>
#include <controller/actions/ActionVisitor.h>
#include <bits/unique_ptr.h>

void Fish::act(ActionVisitor &visitor) {
    visitor.doIt(*this);
}

std::unique_ptr <Entity> Fish::clone() {
    return std::make_unique<Fish>();
}
