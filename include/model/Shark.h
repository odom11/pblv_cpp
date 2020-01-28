//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_SHARK_H
#define POPULATIONDYNAMICS_SHARK_H

#include "Entity.h"

class Shark : public Entity {
private:
    int lifepoints;
    int age;
public:
    virtual void act(ActionVisitor& visitor) override;

    int getLifepoints() const {
        return lifepoints;
    }

    void setLifepoints(int lifepoints) {
        lifepoints = lifepoints;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        age = age;
    }
};

#endif //POPULATIONDYNAMICS_SHARK_H
