//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_MOVEVISITOR_H
#define POPULATIONDYNAMICS_MOVEVISITOR_H

#include "ActionVisitor.h"

class MoveVisitor : public ActionVisitor {
public:
    void doIt(Shark& shark) override;
    void doIt(Fish& fish) override;
};

#endif //POPULATIONDYNAMICS_MOVEVISITOR_H
