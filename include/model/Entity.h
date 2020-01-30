//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_ENTITY_H
#define POPULATIONDYNAMICS_ENTITY_H

#include <controller/actions/ActionVisitor.h>
#include <memory>

class Entity {
    int age;
public:
    const int PROCREATION_LIMIT;
    Entity(int procreateAt) : PROCREATION_LIMIT(procreateAt){};
    virtual ~Entity() = 0;
    virtual void act(ActionVisitor& visitor) = 0;
    virtual std::unique_ptr<Entity> clone() = 0;

    int getAge() const;
    void setAge(int age);
};
#endif //POPULATIONDYNAMICS_ENTITY_H
