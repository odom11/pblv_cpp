//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_FISH_H
#define POPULATIONDYNAMICS_FISH_H

#include "Entity.h"

class Fish : public Entity {
public:
    Fish() : Entity(5) {};
    void act(ActionVisitor &visitor) override;

    std::unique_ptr<Entity> clone() override;
};

#endif //POPULATIONDYNAMICS_FISH_H
