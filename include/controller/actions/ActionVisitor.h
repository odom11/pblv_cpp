//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_ACTIONVISITOR_H
#define POPULATIONDYNAMICS_ACTIONVISITOR_H


class Shark;
class Fish;
class ActionVisitor {
public:
    virtual ~ActionVisitor() {}
    virtual void doIt(Shark& shark) = 0;
    virtual void doIt(Fish&) = 0;
};

#endif //POPULATIONDYNAMICS_ACTIONVISITOR_H
