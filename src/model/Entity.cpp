//
// Created by ich on 1/28/20.
//

#include <model/Entity.h>

Entity::~Entity() {}

int Entity::getAge() const {
    return age;
}

void Entity::setAge(int age) {
    Entity::age = age;
}


