//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_SHARK_H
#define POPULATIONDYNAMICS_SHARK_H

#include "Entity.h"

class Shark : public Entity {
private:
    int lifepoints;
public:
    Shark() : Entity(5) {};
    virtual void act(ActionVisitor& visitor) override;

    int getLifepoints() const {
        return lifepoints;
    }

    void setLifepoints(int lifepoints) {
        lifepoints = lifepoints;
    }

    std::unique_ptr<Entity> clone() override;
};

#endif //POPULATIONDYNAMICS_SHARK_H
