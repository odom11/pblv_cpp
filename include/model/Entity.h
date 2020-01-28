//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_ENTITY_H
#define POPULATIONDYNAMICS_ENTITY_H

#include <controller/actions/ActionVisitor.h>

class Entity {
public:
    virtual ~Entity() = 0;
    virtual void act(ActionVisitor& visitor) = 0;
};
#endif //POPULATIONDYNAMICS_ENTITY_H
